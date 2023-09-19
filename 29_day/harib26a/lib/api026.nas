; [FORMAT "WCOFF"]				; オブジェクトファイルを作るモード	
; [INSTRSET "i486p"]				; 486の命令まで使いたいという記述
[BITS 32]						; 32ビットモード用の機械語を作らせる
;[FILE "api025.nas"]				; ソースファイル名情報

		GLOBAL	api_cmdline

[SECTION .text]

api_cmdline:		; int api_cmdline(char *buf, int maxsize);
		PUSH	EBX
		MOV		EDX,26
		MOV		ECX,[ESP+12]		; maxsize
		MOV		EBX,[ESP+8]			; buf
		INT		0x40
		POP		EBX
		RET