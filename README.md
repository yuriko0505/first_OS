# first_OS

2023/08/05 ~

|Day|Date|Comment|
|----|----|----|
|0|08/05|[Day00](#day00)|
|1|08/05|[Day01](#day01)|
|2|08/05|[Day02](#day02)|
|3|08/06|[Day03](#day03)|
|4|08/07|[Day04](#day04)|

githubのつかいかた→[ソフI_バージョン管理](https://eeic-software1.github.io/2022/git/)

## 日記
### Day00
イントロ．<br>
OS自作がんばるぞー

### Day01
<span style="color: RoyalBlue; font-size: 150%;">***PCの仕組みからアセンブラ入門まで***</span><br>
とりあえず動かす．インストールしたツールたち↓
- バイナリエディタ: Hex Fiend
- エミュレータ: qemu
- アセンブラ: NASM

### Day02
<span style="color: RoyalBlue; font-size: 150%;">***アセンブラ学習***</span><br>
mformatの使い方 → [mtools についてのメモ](https://qiita.com/code2545Light/items/1586a7c19ba91fdc0cb4)<br>

コンピュロみがある！
|レジスタ名|英語|意味|
|:--:|----|----|
|```AX```|accumulator|累積演算機|
|```CX```|counter|カウンタ|
|```DX```|data|データ|
|```BX```|base|土台|
|```SP```|stack pointer|スタック用ポインタ|
|```BP```|base pointer|ベース用ポインタ|
|```SI```|source index|読み込みインデックス|
|```DI```|destination index|書き込みインデックス|

### Day03
<span style="color: RoyalBlue; font-size: 150%;">***32ビットモード突入とC言語導入***</span><br>
空のディスクに対してファイルを普通に保存すると，
1. ファイル名は ```0x002600```　以降に入るらしい
2. ファイルの中身は ```0x004200``` 以降に入るらしい

なんか色々やった．<br>
- Cコンパイラ: i386-elf-gcc

### Day04
<span style="color: RoyalBlue; font-size: 150%;">***C言語と画面表示の練習***</span><br>
アセンブラで定義した関数をCソースで使う．<br>
ここでアセンブラ関数の書き方を復習．
```Assembly
[FORMAT "WCOFF"]        ; オブジェクトファイルを作るモード
[INSTRSET "i486p"]      ; 486の命令まで使いたいという記述
[BITS 32]               ; 32ビットモード用の機械語を作らせる
[FILE "naskfunc.nas"]   ; ソースファイル名情報

    GLOBAL _io_load_eflags      ; addをグローバルスコープで見えるようにする．

[SECTION .text]     ;コードセグメントに（.objファイル中ではテキストセクション）
_io_load_eflags:
    PUSHFD
    POP     EAX     ; 関数の戻り値は EAX
    RET
```
※ちなみに，CやC++のプログラム中にインラインでアセンブリコードを記述することができる！