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
|9|08/15|[Day09](#day09)|
|10|08/17|[Day10](#day10)|
|11|08/19|[Day11](#day11)|
|12|08/23|[Day12](#day12)|
|13|08/25|[Day13](#day13)|
|14|08/27|[Day14](#day14)|

githubのつかいかた→[ソフI_バージョン管理](https://eeic-software1.github.io/2022/git/)<br>
[サポートページ](http://hrb.osask.jp/) <- hikaliumさんの名が！

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

### Day09
<span style="color: RoyalBlue; font-size: 150%;">***メモリ管理***</span><br>
- メモリ管理チェック(2)では ```128 MB``` となった．
  - Cコンパイラがそのままコンパイルした？
- メモリ管理チェック(3)でも ```128 MB``` となった．
  - 現在のQEMUのメモリはデフォルト ```128 MB``` らしい．
- メモリ管理の基本は「確保と解放」
- 632KB + 124MB = 127,608KB
- STEPのmallocのやつ思い出した

### Day10
<span style="color: RoyalBlue; font-size: 150%;">***重ね合わせ処理***</span><br>
- メモリは0x1000B(4kB)単位で管理するようにした
- harib07b
  - 127532 KB
  - 重ね合わせの処理には成功
  - マウスがチカチカする！
- harib07c
  - 127532 KB
  - bよりは滑らか
  - まだチカチカする
- harib07d
  - ヌルヌル動くようになった！

### Day11
<span style="color: RoyalBlue; font-size: 150%;">***ついにウィンドウ***</span><br>
- マウスが画面の端っこまで行くようになった
- ついにウィンドウが出た！　127520 KB
- 高速カウンター，背景がチラチラする
- refresh対象とそれより上のレイヤーのみ書き換えるようにすると，ちらつきはほとんど無くなるがマウスをカウンタの上に置くとチラつく
- カウンタが少し早くなった気がする
- zIndexの値を使って角画素ごとにzIndexの値を当てはめたmapを作り、それに応じてrefreshsubを実行するように変更
- 実行すると、マウスをカウンタ上に置いてもちらつきがなくなった

気付き
- mysprintfを桁数指定対応にしたい -> した

### Day12
<span style="color: RoyalBlue; font-size: 150%;">***タイマ-1***</span><br>
- タイマは時間管理に重要
- PIC (Programmable Interval Timer)
- IRQ0に接続
- タイマの ```timeout``` を残り時間 → 終了予定時刻に変更
- 次に終わりそうなタイマに注目する
- ```sheet.c``` に倣い，タイマを順番に格納しておく

### Day13
<span style="color: RoyalBlue; font-size: 150%;">***タイマ-2***</span><br>
- タイム測定がうまくいかない
  - for文の始めの ```sprintf``` と ```putfonts8_asc_sht``` を消すと全く動かない
    - マウスの反応がガクガク、キーボードの反応も遅い
  - ```sprintf``` を入れると10倍くらいの遅さで動く
  - ```putfonts8_asc_sht``` を 入れるとちゃんと動く(が，ウィンドウが汚い())
  - ```sprintf```　と ```putfonts8_asc_sht``` と両方入れてもちゃんと動く
  - inthandler20の問題っぽい ← Mac(qemu)とWindowsでは違う？
  - 原因は不明だが、```sheet_refresh``` を入れて対処
    - harib10c: 224000
    - harib10g: 218000
- キーボード，マウス．タイマのFIFOバッファを共通化
  - 共通化したのにむしろ遅くなった
- タイマを配列から連結リストへ
  - harib10h: 219000
- 番兵を用意
  - harib10i: 218000

### Day14
<span style="color: RoyalBlue; font-size: 150%;">***高解像度・キー入力***</span><br>
- CPUのJMP命令は，飛び先の番地によって実行クロック数が変わる
- VESA BIOS Extentionssw
- VBEの画面モード番号
  ||画面サイズ|
  |:--:|:--:|
  |```0x101```|640 x 480|
  |```0x103```|800 x 640|
  |```0x105```|1024 x 768|
  |```0x107```|1280 x 1024|
- ```ES:DI``` にそのビデオカードで利用できるVBEの情報が書き込まれる
- 手元環境では ```0x107``` も指定可能
- ```static``` をつけると，RESB命令でなくDB命令になる
- テキストボックスを作り，文字を入力できるようになった
- ウィンドウをマウスで動かせるようになった