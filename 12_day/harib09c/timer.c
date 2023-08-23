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
	timerctl.timeout = 0;
	return;
}

void inthandler20(int *esp)
{
	io_out8(PIC0_OCW2, 0x60);	/* IRQ-00受付完了をPICに通知 */
	timerctl.count++;
	if (timerctl.timeout > 0) {
		timerctl.timeout--;
		if (timerctl.timeout == 0) {
			fifo8_put(timerctl.fifo, timerctl.data);
		}
	}
	return;
}

void settimer(unsigned int timeout, struct FIFO8 *fifo, unsigned char data)
{
	int eflags;
	eflags = io_load_eflags();	/* 割り込み許可フラグの値を記録する */
	io_cli();					/* 許可フラグを0にして割り込み禁止にする */
	timerctl.timeout = timeout;
	timerctl.fifo = fifo;
	timerctl.data = data;
	io_store_eflags(eflags);	/* 割り込み許可フラグを元に戻す */
	return;
}
