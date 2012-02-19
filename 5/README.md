# 5.標準入出力ライブラリ

## 5.2 ストリームとFILEオブジェクト

 * 標準入出力関数ではファイルに stream を結びつけるという概念になる
 * fopen(3) は FILE 構造体のポインタを返す
   * 通常 FILE 構造体の中身を気にする必要は無い

## 5.3 標準入力、標準出力、標準エラー出力

 * File Descripter
   * STDIN_FILENO
   * STDOUT_FILENO
   * STDERR_FILENO
 * FILE pointer
   * stdin
   * stdout
   * stderr

## 5.4 バッファリング

 * 完全なバッファリング
   * バッファは標準入出力関数が malloc して取得する
   * fflush(3) を呼び出した時に flush される
 * 行バッファリング
   * fgets(3), fputs(3)
 * アンバッファド
   * 標準エラー出力はアンバッファド
   
これらの振る舞いを setbuf(3), setvbuf(3) で変更出来る。

## 5.5 ストリームのオープン

 * fopen(3), freopen(3), fdopen(3)
 * fclose(3)
 
mode vs type をまとめたい
 
## 5.6 ストリームに対する読み書き

 * 1文字ずつ読む
   * getc(3), fgetc(3), getchar(3)
 * エラー
   * ferror(3), feof(3), clearerr(3)
 * 1文字戻す
   * ungetc(3)
 * 1文字ずつ書く
   * putc(3), fputc(3), putchar(3)

## 5.7 行単位の入出力

 * 行単位で読む
   * fgets(3), gets(3)
     * gets(3) はバッファサイズ指定出来ないので使用しては駄目！
 * 行単位で書く
   * fputs(3), puts(3)
   
## 5.8 標準入出力の効率

ベンチマーク取りたいところ

## 5.9 バイナリ入出力

 * fread(3), fwrite(3)
   * 関数定義がデータサイズ * その個数みたいな感じ
   * 戻り値もその個数になる
 * バイナリ非互換
 
## 5.10 ストリームの位置決め

 * ftell(3), fseek(3)
   * long int で表現出来る
 * fgetpos(3), fsetpos(3)
   * UNIX 以外のシステムとの互換性
 * rewind(3)
   * 先頭に戻る
   
## 5.11 書式付き入出力

 * printf(3), fprintf(3), sprintf(3)
   * sprintf(3) はオーバーフローに注意 (snprintf(3))
 * vprintf(3), vfprintf(3), vsprintf(3)
   * 可変長引数リスト用
 * scanf(3), fscanf(3), sscanf(3)
   * 入力


## 5.12 実装の詳細

 * fileno(3) で *FILE -> file descripter を取得出来る
 
## 5.13 一時ファイル

 * tmpnam(3)
   * ファイルパスを返す
 * tmpfile(3)
   * FILE 構造体ポインタを返す
 * tempnam(3)
   * ディレクトリ、プリフィックス指定可能

## 5.14 標準入出力の代替

 * fio(3)
 * sfio
 * mmap(2)

## 5.16 演習問題

あとで

 
