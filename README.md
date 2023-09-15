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
|15|08/27|[Day15](#day15)|
|16|08/28|[Day16](#day16)|
|17|08/29|[Day17](#day17)|
|18|09/01|[Day18](#day18)|
|19|09/02|[Day19](#day19)|
|20|09/03|[Day20](#day20)|
|21|09/05|[Day21](#day21)|
|22|09/10|[Day22](#day22)|
|23|09/11|[Day23](#day23)|
|24|09/12|[Day24](#day24)|
|25|09/13|[Day25](#day25)|

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

### Day15
<span style="color: RoyalBlue; font-size: 150%;">***マルチタスク-1***</span><br>
- TSS(Task Status Segment)
- EIPレジスタ: 次に実行する命令のメモリ番地を記憶するレジスタ
  - JMP 0x1234 = MOV EIP,0x1234
- JMPには2種類ある
  - near モード: EIPのみ切り替え
  - far モード: EIPとCSを同時に切り替え
- カウントはそれなりに早い(10sec: 90000)
- スピードアップ→day13と同じ不具合
  - ```boxfill8```を入れて対処したところ，動くようにはなったがカウンタが表示されない
  - ```bootpack.c``` の 126行目を直したらカウンタ表示された(でも遅い)(2023/08/31)
- ~~結局カウンタ表示されない~~

### Day16
<span style="color: RoyalBlue; font-size: 150%;">***マルチタスク-2***</span><br>
- ~~カウンタが表示されないねえ~~
- 遅いけどカウンタ表示されるようになった(2023/08/31)
- ウィンドウを4つに．ちょっと遅い
- タスクレベルを実装，動きが滑らかになった

### Day17
<span style="color: RoyalBlue; font-size: 150%;">***コンソール***</span><br>
本日の気づき
```C
*((int *) task_cons->tss.esp + 4) = (int) sht_cons;
*((int *) (task_cons->tss.esp + 4)) = (int) sht_cons;
```
括弧の有無がこんなにクリティカルだとは、、
- ```task_idle``` (task版番兵)を用意 →　タスクが一個でもバグらない
- ~~コンソールの方のカーソルが点滅しない~~ 治りました泣
- タブの切り替え(見た目のみ)
- コンソールで入力できるようになった！
- 記号に対応(フォントをやや修正)
- 現状は起動後のCaps Lockが反映されない → キーコードは0xbaで，クリック時のみ
  - 対応させた(192行目)
- qemuのみでの実行のため，ランプ点灯は未実装

### Day18
<span style="color: RoyalBlue; font-size: 150%;">***dirコマンド***</span><br>
- アクティブなウィンドウのカーソルのみ点滅するようにする
- スクロールに対応 (入力時)
- memコマンド(はりぼてOS初コマンド！)
- mysprintfで文字列にも対応したい
  - はりぼて用にカスタマイズされたスマートな関数をね
- clearコマンド
-ファイルタイプ一覧
  |12 bite 目|ファイルタイプ|
  |:--:|:---|
  |```0x01```|読み込み専用ファイル|
  |```0x02```|隠しファイル|
  |```0x04```|システムファイル|
  |```0x08```|ファイルではない情報(ディスクの名前とか)|
  |```0x10```|ディレクトリ|

### Day19
<span style="color: RoyalBlue; font-size: 150%;">***アプリケーション***</span><br>
- ウィンドウサイズの変更を簡単にしたい
- ~~sprintfを改良したい (再)~~ 文字列に対応しました(2023/09/02)
- console用に入力を区切り文字で区切るやつ実装したい
- ```cat``` が command not found になるの悔しすぎる
- 改行コードに対応(Carriage Return + Line Feed)
- FATに対応し，任意の大きさのファイルを読み出せるようになった

### Day20
<span style="color: RoyalBlue; font-size: 150%;">***API***</span><br>
- 本の通りに```hlt.nas```を書くと異常終了して再起動する
- (harib17c) ```hlt``` を実行すると上1/4が ```#C6C6C6``` になる
- (harib17d) ```hlt``` すると止まる、、関数の番地が違うのではないか？
- IDTの ```0x40``` 番に ```asm_cons_putchar``` を登録 → helloと出力された！
  - OS を書き換えてもアプリが動くようになる
- ```hello``` でも ```hello.hrb``` でも起動するようになった
- sprintfに```%fs```(ファイル名フォーマット)を導入したい
- ```hello``` は動くが ```hello2``` は動かない(これは次回)

### Day21
<span style="color: RoyalBlue; font-size: 150%;">***OSを守ろう***</span><br>
- ```hello2``` がちゃんと動いた
- ```
  EB 16 00 00 00 CB
  ```
  は
  ```Assembly
  [BITS 32]
    CALL  0x1b
    RETF
  ```
- OSを守ろう
- 例外は割り込み番号```0x0d```
- General Protected Exception.

### Day22
<span style="color: RoyalBlue; font-size: 150%;">***C言語でアプリケーションを作ろう***</span><br>
参考ページ:
- [割り込みと例外](https://www.hazymoon.jp/OpenBSD/annex/interrupt.html)

内容
- ESP[11]がEIP
- アプリではエラー文が出ない
- hrbファイルの0x000cがESPレジスタの初期値
  - 0x310000
- ついにウィンドウがでた！

### Day23
<span style="color: RoyalBlue; font-size: 150%;">***グラフィック色々***</span><br>
- 星空のディスタンス〜
- rand関数をmylibに実装したが、コンパイルの際に```mylib.o```も含めなければならなくなった泣
- ウィンドウを消せるようになった
- ~~強制終了で画面が閉じない？~~ → ディレクトリ違うだけだった泣

### Day24
<span style="color: RoyalBlue; font-size: 150%;">***ウィンドウ操作***</span><br>
- ウィンドウ切り替えにはF3キー
- カーソルでウィンドウを動かせる
- バツ印でウィンドウを消せるようになった
- タイマーを呼び出せるようにした

### Day25
<span style="color: RoyalBlue; font-size: 150%;">***コンソールを増やそう***</span><br>
- QEMUではBeep音が鳴らない
- カラーパレット2種類
- harib22fが動かない
  - ```inthandler27```を削除するとうまく動いた
- うまく動いてはいるが、起動後にカーソルが点滅しない
- FIFOの初期化をbootpackで行うと、点滅もうまく行った