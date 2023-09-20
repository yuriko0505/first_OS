OBJS_BOOTPACK = bootpack.o graphic.o dsctbl.o naskfunc.o hankaku.o ../lib/mylib.o \
				int.o fifo.o keyboard.o mouse.o memory.o sheet.o timer.o \
				mtask.o window.o console.o file.o tek.o

LINKER = ../lib/hrb.ld

MAKE     = make -r
DEL      = rm -f

CC = i386-elf-gcc
CFLAGS = -m32 -fno-builtin

# デフォルト動作

default :
	$(MAKE) -C ../lib/ mylib.o
	$(MAKE) ipl20.bin
	$(MAKE) haribote.sys

# ファイル生成規則

# convHankakuTxt.c は標準ライブラリが必要なので、macOS標準のgccを使う
convHankakuTxt : convHankakuTxt.c
	gcc $< -o $@

hankaku.c : hankaku.txt convHankakuTxt
	./convHankakuTxt

ipl20.bin : ipl20.nas
	nasm $< -o $@ -l ipl20.lst

asmhead.bin : asmhead.nas
	nasm $< -o $@ -l asmhead.lst

naskfunc.o : naskfunc.nas
	nasm -g -f elf $< -o $@ -l naskfunc.lst

bootpack.hrb : $(OBJS_BOOTPACK) $(LINKER)
	$(CC) $(CFLAGS) -march=i486 -nostdlib -T $(LINKER) -g $(OBJS_BOOTPACK) -o $@

haribote.sys : asmhead.bin bootpack.hrb Makefile
	cat asmhead.bin bootpack.hrb > haribote.sys

# 一般規則

%.o : %.c
	$(CC) $(CFLAGS) -c $*.c -o $*.o

%.o : %.nas
	nasm -g -f elf $*.nas -o $*.o -l $*.lst

# コマンド

clean :
	-$(DEL) asmhead.bin
	-$(DEL) *.lst
	-$(DEL) *.o
	-$(DEL) *.hrb
	-$(DEL) hankaku.c
	-$(DEL) convHankakuTxt

src_only :
	$(MAKE) clean
	-$(DEL) ipl20.bin
	-$(DEL) haribote.sys