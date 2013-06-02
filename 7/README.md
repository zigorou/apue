# 7. UNIX プロセスの環境

## 7.2 main 関数

 * gcc 等でのコンパイル時にリンケージエディタが main 関数が呼ばれる前の起動ルーティンがコマンド行引数と環境変数を受け取り main 関数が呼ばれるように設定する

## 7.3 プロセスの終了

 1. 正常終了
   1. main から戻る
   1. exit を呼ぶ
   1. _exit を呼ぶ
 1. 異常終了
   1. abort を呼ぶ
   1. シグナルで終了させられる

### exit と _exit 関数

 * _exit
   + 直接カーネルに戻る
 * exit
   + 後始末してくれる
     - stdio の後始末 (fclose)

終了状態を考えた時に次の古典的な例は誤り。

```c
#include <stdio.h>

main() {
    printf("Hello, world\n");
}
```

これは暗黙の終了状態になっているので return(0); または exit(0); すべきである。
また main の宣言は次のようにすべきである。

```c
int main(void);
```

### atexit 関数

atexit(3) は次のような宣言である

```c
int atexit(void (*func)(void));
```

プログラム 7.1 では次のような関数宣言された関数をハンドラとして定義している。

```c
static void my_exit1(void);
```

atexit(3) は登録された順番とは逆に呼び出しが掛かる事に注意する。

## 7.4 コマンド行引数

## 7.5 環境リスト

帯域変数 environ に環境変数の key=value のリストがあるので冒頭で次のように宣言しておけば使える。

```c
extern char **environ;
```

一方で ANSI C では規定外であるが POSIX.1 では第3匹数に environ を使うように規定している。つまり、

```c
int main(int argc, char *argv[], char *environ[]);
```

のようなインターフェースになっている。

## 7.6 C プログラムのメモリ配置

 * テキストセグメント
   - CPU が実行する機械語命令群
   - 共有される、またしばしば読み取り専用 (CoW)
 * 初期化されたデータセグメント
 * 初期化されていないデータセグメント
   - bss セグメント (block started by symbol)
 * スタック
 * ヒープ
   - 動的に割り当てられた領域
   
size(1) コマンドでテキスト、データ、bss のセグメントをバイト単位で調べられる。

```
$ size /usr/bin/gcc /bin/sh
__TEXT  __DATA  __OBJC  others  dec     hex
45056   4096    0       4294979584      4295028736      10000f000       /usr/bin/gcc
626688  57344   0       4295024640      4295708672      1000b5000       /bin/sh
```

## 7.7 共有ライブラリ

## 7.8 メモリ割り付け

 1. malloc(3)
   - 指定されたバイトするのメモリを割り付ける。メモリの初期値は不定。
 1. calloc(3)
   - 指定サイズのオブジェクトに必要な領域を指定個数割り付ける。領域は全て 0 に初期化される
 1. realloc(3)
   - 既に割り付けた領域のサイズを変更する。新たに割り付けた領域の内容は不定
 1. free(3)
   - alloc 関数で割り当てられた領域を解放する

alloc 関数は sbrk(2) システムコールを用いて実現されている。

### alloca 関数

```c
#include <alloca.h>

void *alloca(size_t size);
```

stdlib.h でも構わないらしい。ヒープからではなくスタックからメモリを確保する。

## 7.9 環境変数

 * getenv(3)
 * putenv(3)
 * setenv(3)
 * unsetenv(3)

# 7.10 setjmp と longjmp 関数

C には goto が無いので代わりに大域的な goto となる setjmp(3), longjmp(3) を使う。

 * jmp_buf 構造体を global 変数として宣言する
 * setjmp(3) は直接呼ばれた場合は 0 を返し、longjmp(3) から呼ばれて戻った場合は非ゼロ値が返る
 
プログラム 7.5 は最適化オプションの有無によって結果が異なる。影響を受けたくない場合は大局的な分岐を使うポータブルなコードを書くには
volatile 属性にする必要がある。

ところで CMake で一時的に -O1 とかつけるのはどうやるんだろうか。
どうも

```
$ cmake -DCMAKE_C_FLAGS="-O2 -g" .
```

のようにすれば一律変更出来る模様。




