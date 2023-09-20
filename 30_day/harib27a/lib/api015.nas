; [FORMAT "WCOFF"]				; オブジェクトファイルを作るモード	
; [INSTRSET "i486p"]				; 486の命令まで使いたいという記述
[BITS 32]						; 32ビットモード用の機械語を作らせる
;[FILE "api001.nas"]				; ソースファイル名情報

		GLOBAL	api_getkey

[SECTION .text]

api_getkey:		; int api_getkey(int mode);
		MOV		EDX,15
		MOV		EAX,[ESP+4]	; mode
		INT		0x40
		RET
