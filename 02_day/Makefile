ipl.bin: ipl.nas Makefile
	nasm ipl.nas -o ipl.bin -l ipl.lst

helloos.img: ipl.bin Makefile
	mformat -f 1440 -C -B ipl.bin -i helloos.img ::

img:
	make -r helloos.img

asm:
	make -r ipl.bin

run:
	make img
	qemu-system-x86_64 -fda helloos.img