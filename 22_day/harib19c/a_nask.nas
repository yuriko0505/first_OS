; [FORMAT "WCOFF"]				; オブジェクトファイルを作るモード	
; [INSTRSET "i486p"]				; 486の命令まで使いたいという記述
[BITS 32]						; 32ビットモード用の機械語を作らせる
;[FILE "a_nask.nas"]				; ソースファイル名情報

		GLOBAL	api_putchar
		GLOBAL	api_end

[SECTION .text]

api_putchar:	; void api_putchar(int c);
		MOV		EDX,1
		MOV		AL,[ESP+4]		; c
		INT		0x40
		RET

api_end:		; void api_end(void)
		MOV		EDX,4
		INT		0x40