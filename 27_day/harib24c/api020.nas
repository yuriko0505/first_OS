; [FORMAT "WCOFF"]				; オブジェクトファイルを作るモード	
; [INSTRSET "i486p"]				; 486の命令まで使いたいという記述
[BITS 32]						; 32ビットモード用の機械語を作らせる
;[FILE "api001.nas"]				; ソースファイル名情報

		GLOBAL	api_beep

[SECTION .text]

api_beep:			; void api_beep(int tone);
		MOV		EDX,20
		MOV		EAX,[ESP+4]			; tone
		INT		0x40
		RET
