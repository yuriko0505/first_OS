; [FORMAT "WCOFF"]				; オブジェクトファイルを作るモード	
; [INSTRSET "i486p"]				; 486の命令まで使いたいという記述
[BITS 32]						; 32ビットモード用の機械語を作らせる
;[FILE "api001.nas"]				; ソースファイル名情報

		GLOBAL	api_alloctimer

[SECTION .text]

api_alloctimer:	; int api_alloctimer(void);
		MOV		EDX,16
		INT		0x40
		RET
