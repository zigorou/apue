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


