MAKE     = make -r
DEL      = rm -f

# デフォルト動作

default :
	$(MAKE) img

# ファイル生成規則

haribote.img : haribote/ipl10.bin haribote/haribote.sys Makefile \
				a/a.hrb hello3/hello3.hrb hello4/hello4.hrb hello5/hello5.hrb \
				winhelo/winhelo.hrb winhelo2/winhelo2.hrb winhelo3/winhelo3.hrb \
				stars/stars.hrb stars2/stars2.hrb lines/lines.hrb \
				noodle/noodle.hrb color/color.hrb color2/color2.hrb
	mformat -f 1440 -C -B $< -i haribote.img ::
	mcopy -i haribote.img haribote/haribote.sys ::
	mcopy -i haribote.img haribote/ipl10.nas ::
	mcopy -i haribote.img a/a.hrb ::
	mcopy -i haribote.img hello3/hello3.hrb ::
	mcopy -i haribote.img hello4/hello4.hrb ::
	mcopy -i haribote.img hello5/hello5.hrb ::
	mcopy -i haribote.img winhelo/winhelo.hrb ::
	mcopy -i haribote.img winhelo2/winhelo2.hrb ::
	mcopy -i haribote.img winhelo3/winhelo3.hrb ::
	mcopy -i haribote.img stars/stars.hrb ::
	mcopy -i haribote.img stars2/stars2.hrb ::
	mcopy -i haribote.img lines/lines.hrb ::
	mcopy -i haribote.img noodle/noodle.hrb ::
	mcopy -i haribote.img color/color.hrb ::
	mcopy -i haribote.img color2/color2.hrb ::

# コマンド

img :
	$(MAKE) haribote.img

run :
	$(MAKE) img
	qemu-system-i386 -drive file=haribote.img,format=raw,if=floppy -boot a

full :
	$(MAKE) -C haribote
	$(MAKE) -C lib
	$(MAKE) -C a
	$(MAKE) -C hello3
	$(MAKE) -C hello4
	$(MAKE) -C hello5
	$(MAKE) -C winhelo
	$(MAKE) -C winhelo2
	$(MAKE) -C winhelo3
	$(MAKE) -C stars
	$(MAKE) -C stars2
	$(MAKE) -C lines
	$(MAKE) -C noodle
	$(MAKE) -C color
	$(MAKE) -C color2
	$(MAKE) haribote.img

run_full :
	$(MAKE) full
	qemu-system-i386 -drive file=haribote.img,format=raw,if=floppy -boot a

run_os :
	$(MAKE) -C haribote
	$(MAKE) run

clean :
# 何もしない

src_only :
	$(MAKE) clean
	-$(DEL) haribote.img

clean_full :
	$(MAKE) -C haribote		clean
	$(MAKE) -C lib			clean
	$(MAKE) -C a			clean
	$(MAKE) -C hello3		clean
	$(MAKE) -C hello4		clean
	$(MAKE) -C hello5		clean
	$(MAKE) -C winhelo		clean
	$(MAKE) -C winhelo2		clean
	$(MAKE) -C winhelo3		clean
	$(MAKE) -C stars		clean
	$(MAKE) -C stars2		clean
	$(MAKE) -C lines		clean
	$(MAKE) -C noodle		clean
	$(MAKE) -C color		clean
	$(MAKE) -C color2		clean

src_only_full :
	$(MAKE) -C haribote		src_only
	$(MAKE) -C lib			src_only
	$(MAKE) -C a			src_only
	$(MAKE) -C hello3		src_only
	$(MAKE) -C hello4		src_only
	$(MAKE) -C hello5		src_only
	$(MAKE) -C winhelo		src_only
	$(MAKE) -C winhelo2		src_only
	$(MAKE) -C winhelo3		src_only
	$(MAKE) -C stars		src_only
	$(MAKE) -C stars2		src_only
	$(MAKE) -C lines		src_only
	$(MAKE) -C noodle		src_only
	$(MAKE) -C color		src_only
	$(MAKE) -C color2		src_only
	-$(DEL) haribote.img

refresh :
	$(MAKE) full
	$(MAKE) clean_full
	-$(DEL) haribote.img
