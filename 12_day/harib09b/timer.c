/* タイマ関係 */

#include "bootpack.h"

#define PIT_CTRL	0x0043
#define PIT_CNT0	0x0040

struct TIMERCTL timerctl;

void init_pit(void)
/*
・割り込み周期に0を指定すると65536を指定したとみなされる
・割り込み頻度 = クロック / 設定カウント数
・11932(0x2e9c)を指定し，約100Hzとする
*/
{
	io_out8(PIT_CTRL, 0x34);
	io_out8(PIT_CNT0, 0x9c);  /* 割り込み周期の下位8bit */
	io_out8(PIT_CNT0, 0x2e);  /* 割り込み周期の上位8bit */
	timerctl.count = 0;
	return;
}

void inthandler20(int *esp)
{
	io_out8(PIC0_OCW2, 0x60);	/* IRQ-00受付完了をPICに通知 */
	timerctl.count++;
	return;
}