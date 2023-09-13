OBJS_BOOTPACK = bootpack.o graphic.o dsctbl.o naskfunc.o hankaku.o mylib.o \
				int.o fifo.o keyboard.o mouse.o memory.o sheet.o timer.o \
				mtask.o window.o console.o file.o

APPS = a.hrb hello3.hrb hello4.hrb hello5.hrb winhelo.hrb winhelo2.hrb winhelo3.hrb stars.hrb stars2.hrb lines.hrb
COPYED_TO_IMG = hello.hrb hello2.hrb $(APPS) haribote.sys

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

hello4.hrb : hello4.o a_nask.o hrb.ld
	$(CC) $(CFLAGS) -march=i486 -nostdlib -T hrb.ld -g $< a_nask.o -o $@

hello5.hrb : hello5.nas
	nasm $< -o $@

winhelo.hrb : winhelo.o a_nask.o hrb.ld
	$(CC) $(CFLAGS) -march=i486 -nostdlib -T hrb.ld -g $< a_nask.o -o $@

winhelo2.hrb : winhelo2.o a_nask.o hrb.ld
	$(CC) $(CFLAGS) -march=i486 -nostdlib -T hrb.ld -g $< a_nask.o -o $@

winhelo3.hrb : winhelo3.o a_nask.o hrb.ld
	$(CC) $(CFLAGS) -march=i486 -nostdlib -T hrb.ld -g $< a_nask.o -o $@

stars.hrb : stars.o a_nask.o hrb.ld mylib.o
	$(CC) $(CFLAGS) -march=i486 -nostdlib -T hrb.ld -g $< a_nask.o mylib.o -o $@

stars2.hrb : stars2.o a_nask.o hrb.ld mylib.o
	$(CC) $(CFLAGS) -march=i486 -nostdlib -T hrb.ld -g $< a_nask.o mylib.o -o $@

lines.hrb : lines.o a_nask.o hrb.ld mylib.o
	$(CC) $(CFLAGS) -march=i486 -nostdlib -T hrb.ld -g $< a_nask.o mylib.o -o $@

haribote.sys : asmhead.bin bootpack.hrb Makefile
	cat asmhead.bin bootpack.hrb > haribote.sys

haribote.img : ipl10.bin $(COPYED_TO_IMG) Makefile
	mformat -f 1440 -C -B $< -i haribote.img ::
	mcopy -i haribote.img haribote.sys ::
	mcopy -i haribote.img ipl10.nas ::
	mcopy -i haribote.img hello.hrb ::
	mcopy -i haribote.img hello2.hrb ::
	mcopy -i haribote.img a.hrb ::
	mcopy -i haribote.img hello3.hrb ::
	mcopy -i haribote.img hello4.hrb ::
	mcopy -i haribote.img hello5.hrb ::
	mcopy -i haribote.img winhelo.hrb ::
	mcopy -i haribote.img winhelo2.hrb ::
	mcopy -i haribote.img winhelo3.hrb ::
	mcopy -i haribote.img stars.hrb ::
	mcopy -i haribote.img stars2.hrb ::
	mcopy -i haribote.img lines.hrb ::

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