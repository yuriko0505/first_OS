# first_OS

2023/08/05 ~

|Day|Date|Comment|
|----|----|----|
|0|08/05|[Day00](#day00)|
|1|08/05|[Day01](#day01)|
|2|08/05|[Day02](#day02)|
|3|08/06|[Day03](#day03)|
|4|08/07|[Day04](#day04)|
|5|08/08|[Day05](#day05)|
|6|08/09|[Day06](#day06)|
|7|08/10|[Day07](#day07)|
|8|08/14|[Day08](#day08)|

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

### Day05
<span style="color: RoyalBlue; font-size: 150%;">***構造体と文字表示とGDT/IDT初期化***</span><br>
やったこと
- 構造体を導入
- フォントを導入
- 変数の値を表示するようにする -> デバッグができる！
- マウスカーソルを描く
- GDT/IDTの設定

復習事項
- アロー演算子
- extern
- 動的引数（引数が可変個の関数）

### Day06
<span style="color: RoyalBlue; font-size: 150%;">***分割コンパイルと割り込み処理***</span><br>

### Day07
<span style="color: RoyalBlue; font-size: 150%;">***FIFOとマウス制御***</span><br>
お気持ち
- 割り込みが来たら状況をbufにいれておいて、すぐに戻す
- ctrlも普通に ```1d``` ↔︎ ```9d``` となる（Macbook Air, Ventra 13.1, qemu）
- ぐるぐる回るFIFO
- マウスからの割り込みにも対応した

### Day08
<span style="color: RoyalBlue; font-size: 150%;">***マウス制御と32ビットモード切り替え***</span><br>
マウスの動き(初期値: 8 0 0)
- 1 byte 目
  - 上位4bit: 0(上)，1(左)，2(右)，3(下)
  - 下位4bit: 8(通常時)，9(クリック)，a(2本指でクリック)
- 2 byte 目
  - 左右方向に動かすと変化
- 3 byte 目
  - 上下方向に動かすと変化

ついにカーソルが動いた！！！

```asmhead.nas```の話
- A20GTE信号線・・・メモリの1MB以上の部分を使えるようにする信号線
- CR0レジスタ・・・「コントロールレジスタ0」．OS以外がいじってはいけない．
- プロテクトモード