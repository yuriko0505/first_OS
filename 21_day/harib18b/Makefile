OBJS_BOOTPACK = bootpack.o graphic.o dsctbl.o naskfunc.o hankaku.o mysprintf.o \
				int.o fifo.o keyboard.o mouse.o memory.o sheet.o timer.o \
				mtask.o window.o console.o file.o

MAKE     = make -r
DEL      = rm -f

CC = i386-elf-gcc
CFLAGS = -m32 -fno-builtin

# デフォルト動作

default :
	$(MAKE) img

# ファイル生成規則

# convHankakuTxt.c は標準ライブラリが必要なので、macOS標準のgccを使う
convHankakuTxt : convHankakuTxt.c
	gcc $< -o $@

hankaku.c : hankaku.txt convHankakuTxt
	./convHankakuTxt

ipl10.bin : ipl10.nas
	nasm $< -o $@ -l ipl10.lst

asmhead.bin : asmhead.nas
	nasm $< -o $@ -l asmhead.lst

naskfunc.o : naskfunc.nas
	nasm -g -f elf $< -o $@ -l naskfunc.lst

a_nask.o : a_nask.nas
	nasm -g -f elf $< -o $@ -l a_nask.lst

bootpack.hrb : $(OBJS_BOOTPACK) hrb.ld
	$(CC) $(CFLAGS) -march=i486 -nostdlib -T hrb.ld -g $(OBJS_BOOTPACK) -o $@

hello.hrb : hello.nas
	nasm $< -o $@

hello2.hrb : hello2.nas
	nasm $< -o $@

a.hrb : a.o a_nask.o hrb.ld
	$(CC) $(CFLAGS) -march=i486 -nostdlib -T hrb.ld -g $< a_nask.o -o $@

hello3.hrb : hello3.o a_nask.o hrb.ld
	$(CC) $(CFLAGS) -march=i486 -nostdlib -T hrb.ld -g $< a_nask.o -o $@

haribote.sys : asmhead.bin bootpack.hrb Makefile
	cat asmhead.bin bootpack.hrb > haribote.sys

haribote.img : ipl10.bin hello.hrb hello2.hrb a.hrb hello3.hrb haribote.sys Makefile
	mformat -f 1440 -C -B ipl10.bin -i haribote.img ::
	mcopy -i haribote.img haribote.sys ::
	mcopy -i haribote.img ipl10.nas ::
	mcopy -i haribote.img hello.hrb ::
	mcopy -i haribote.img hello2.hrb ::
	mcopy -i haribote.img a.hrb ::
	mcopy -i haribote.img hello3.hrb ::

# 一般規則

%.o : %.c
	$(CC) $(CFLAGS) -c $*.c -o $*.o

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