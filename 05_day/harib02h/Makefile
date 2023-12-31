MAKE     = make -r
DEL      = rm -f

# デフォルト動作

default :
	$(MAKE) img

# ファイル生成規則

# convHankakuTxt.c は標準ライブラリが必要なので、macOS標準のgccを使う
convHankakuTxt : convHankakuTxt.c
	gcc convHankakuTxt.c -o convHankakuTxt

hankaku.c : hankaku.txt convHankakuTxt
	./convHankakuTxt

ipl10.bin : ipl10.nas Makefile
	nasm ipl10.nas -o ipl10.bin -l ipl10.lst

asmhead.bin : asmhead.nas Makefile
	nasm asmhead.nas -o asmhead.bin -l asmhead.lst

naskfunc.o : naskfunc.nas Makefile
	nasm -g -f elf naskfunc.nas -o naskfunc.o -l naskfunc.lst

bootpack.hrb : bootpack.c hrb.ld hankaku.c naskfunc.o mysprintf.c Makefile   # 自作のmysprintf.c の sprintfでは警告が出るので、-fno-builtinオプションを追加
	i386-elf-gcc -march=i486 -m32 -nostdlib -fno-builtin -T hrb.ld -g bootpack.c hankaku.c naskfunc.o mysprintf.c -o bootpack.hrb

haribote.sys : asmhead.bin bootpack.hrb Makefile
	cat asmhead.bin bootpack.hrb > haribote.sys

haribote.img : ipl10.bin haribote.sys Makefile
	mformat -f 1440 -C -B ipl10.bin -i haribote.img ::
	mcopy -i haribote.img haribote.sys ::

# コマンド

img :
	$(MAKE) haribote.img

run :
	$(MAKE) img
	qemu-system-i386 -drive file=haribote.img,format=raw,if=floppy -boot a

clean :
	-$(DEL) *.bin
	-$(DEL) *.lst
	-$(DEL) *.o
	-$(DEL) *.sys
	-$(DEL) *.hrb
	-$(DEL) hankaku.c
	-$(DEL) convHankakuTxt

src_only :
	$(MAKE) clean
	-$(DEL) haribote.img