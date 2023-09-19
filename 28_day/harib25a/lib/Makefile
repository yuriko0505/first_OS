OBJS_API =	api001.o api002.o api003.o api004.o api005.o api006.o \
			api007.o api008.o api009.o api010.o api011.o api012.o \
			api013.o api014.o api015.o api016.o api017.o api018.o \
			api019.o api020.o api021.o api022.o api023.o api024.o \
			api025.o api026.o alloca.o

MAKE     = make -r
DEL      = rm -f

CC = i386-elf-gcc
CFLAGS = -m32 -fno-builtin

# デフォルト動作

default :
	$(MAKE) libapi.a

# ファイル生成規則

libapi.a : $(OBJS_API)
	ar rusv $@ $(OBJS_API)

mylib.o : mylib.c
	$(CC) $(CFLAGS) -c $< -o $@

# 一般規則

%.o : %.nas
	nasm -g -f elf $*.nas -o $*.o -l $*.lst

# コマンド

clean:
	-$(DEL) *.lst
	-$(DEL) *.o

src_only:
	$(MAKE) clean
	-$(DEL) libapi.a