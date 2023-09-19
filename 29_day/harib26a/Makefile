MAKE     = make -r
DEL      = rm -f

# デフォルト動作

default :
	$(MAKE) img

# ファイル生成規則

haribote.img : haribote/ipl20.bin haribote/haribote.sys Makefile \
				a/a.hrb hello3/hello3.hrb hello4/hello4.hrb hello5/hello5.hrb \
				winhelo/winhelo.hrb winhelo2/winhelo2.hrb winhelo3/winhelo3.hrb \
				stars/stars.hrb stars2/stars2.hrb lines/lines.hrb \
				noodle/noodle.hrb color/color.hrb color2/color2.hrb \
				prime/prime.hrb prime2/prime2.hrb \
				typeipl/typeipl.hrb cat/cat.hrb \
				iroha/iroha.hrb chklang/chklang.hrb \
				notrec/notrec.hrb bball/bball.hrb invader/invader.hrb
	mformat -f 1440 -C -B $< -i haribote.img ::
	mcopy -i haribote.img haribote/haribote.sys ::
	mcopy -i haribote.img haribote/ipl20.nas ::
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
	mcopy -i haribote.img prime/prime.hrb ::
	mcopy -i haribote.img prime2/prime2.hrb ::
	mcopy -i haribote.img typeipl/typeipl.hrb ::
	mcopy -i haribote.img cat/cat.hrb ::
	mcopy -i haribote.img iroha/iroha.hrb ::
	mcopy -i haribote.img euc.txt ::
	mcopy -i haribote.img jp_font/nihongo.fnt ::
	mcopy -i haribote.img chklang/chklang.hrb ::
	mcopy -i haribote.img notrec/notrec.hrb ::
	mcopy -i haribote.img bball/bball.hrb ::
	mcopy -i haribote.img invader/invader.hrb ::

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
	$(MAKE) -C prime
	$(MAKE) -C prime2
	$(MAKE) -C typeipl
	$(MAKE) -C cat
	$(MAKE) -C iroha
	$(MAKE) -C chklang
	$(MAKE) -C notrec
	$(MAKE) -C bball
	$(MAKE) -C invader
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
	$(MAKE) -C prime		clean
	$(MAKE) -C prime2		clean
	$(MAKE) -C typeipl		clean
	$(MAKE) -C cat			clean
	$(MAKE) -C iroha		clean
	$(MAKE) -C chklang		clean
	$(MAKE) -C notrec		clean
	$(MAKE) -C bball		clean
	$(MAKE) -C invader		clean

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
	$(MAKE) -C prime		src_only
	$(MAKE) -C prime2		src_only
	$(MAKE) -C typeipl		src_only
	$(MAKE) -C cat			src_only
	$(MAKE) -C iroha		src_only
	$(MAKE) -C chklang		src_only
	$(MAKE) -C notrec		src_only
	$(MAKE) -C bball		src_only
	$(MAKE) -C invader		src_only
	-$(DEL) haribote.img

refresh :
	$(MAKE) full
	$(MAKE) clean_full
	-$(DEL) haribote.img
