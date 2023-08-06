# first_OS

2023/08/05 ~

|Day|Date|Comment|
|----|----|----|
|0|08/05|[Day00](#day00)|
|1|08/05|[Day01](#day01)|
|2|08/05|[Day02](#day02)|

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

### Day03
<span style="color: RoyalBlue; font-size: 150%;">***32ビットモード突入とC言語導入***</span><br>
空のディスクに対してファイルを普通に保存すると，
1. ファイル名は ```0x002600```　以降に入るらしい
2. ファイルの中身は ```0x004200``` 以降に入るらしい

なんか色々やった．<br>
- Cコンパイラ: i386-elf-gcc
