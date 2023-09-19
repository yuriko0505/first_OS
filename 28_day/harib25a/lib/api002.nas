; [FORMAT "WCOFF"]				; オブジェクトファイルを作るモード	
; [INSTRSET "i486p"]				; 486の命令まで使いたいという記述
[BITS 32]						; 32ビットモード用の機械語を作らせる
;[FILE "api001.nas"]				; ソースファイル名情報

        GLOBAL	api_putstr0

[SECTION .text]

api_putstr0:	; void api_putstr0(char *s);
		PUSH	EBX
		MOV		EDX,2
		MOV		EBX,[ESP+8]		; s
		INT		0x40
		POP		EBX
		RET