void io_hlt(void);

void HariMain(void)
{
	int i; /* 変数宣言。iという変数は、32ビットの整数型 */
	char *p; /* pという変数は、BYTE [...]用の番地 */

	for (i = 0xa0000; i <= 0xaffff; i++) {

		/*　テキストにある通り
		warning: assignment to 'char *' from 'int' makes pointer from integer without a cast [-Wint-conversion]
		が出る */
		// p = (char *) i;      /* とキャストすれば、警告が消える*/
		p = i; /* 番地を代入 */
		*p = i & 0x0f;

		/* これで write_mem8(i, i & 0x0f); の代わりになる */
	}

	for (;;) {
		io_hlt();
	}
}