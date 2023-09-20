APP = gview

APILIBPATH   = ../lib/
HARIBOTEPATH = ../haribote/

LINKER = $(APILIBPATH)hrb.ld

MAKE   = make -r
DEL    = rm -f

CC     = i386-elf-gcc
CFLAGS = -m32 -fno-builtin

# デフォルト動作

default :
	$(MAKE) $(APP).hrb

# ファイル生成規則

$(APP).hrb : $(APP).o bmp.o jpeg.o $(APILIBPATH)libapi.a $(APILIBPATH)mylib.o $(LINKER)
	$(CC) $(CFLAGS) -march=i486 -nostdlib -T $(LINKER) -g $(APP).o bmp.o jpeg.o $(APILIBPATH)libapi.a $(APILIBPATH)mylib.o -o $(APP).hrb

haribote.img : ../haribote/ipl10.bin ../haribote/haribote.sys $(APP).hrb ../app_make.txt
	mformat -f 1440 -C -B $< -i haribote.img ::
	mcopy -i haribote.img ../haribote/haribote.sys ::
	mcopy -i haribote.img $(APP).hrb ::

# 一般規則

%.o : %.c
	$(CC) $(CFLAGS) -c $*.c -o $*.o

%.o : %.nas
	nasm -g -f elf $*.nas -o $*.o -l $*.lst

# コマンド

img :
	$(MAKE) haribote.img

run :
	$(MAKE) img
	qemu-system-i386 -drive file=haribote.img,format=raw,if=floppy -boot a

full :
	$(MAKE) -C $(APILIBPATH) libapi.a
	$(MAKE) -C $(APILIBPATH) mylib.o
	$(MAKE) $(APP).hrb

run_full :
	$(MAKE) -C $(APILIBPATH)
	$(MAKE) -C ../haribote
	$(MAKE) run

clean :
	-$(DEL) *.bin
	-$(DEL) *.lst
	-$(DEL) *.o
	-$(DEL) *.sys
	-$(DEL) hankaku.c
	-$(DEL) convHankakuTxt
	-$(DEL) haribote.img

src_only :
	$(MAKE) clean
	-$(DEL) $(APP).hrb
