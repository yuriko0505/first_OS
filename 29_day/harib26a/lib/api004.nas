; [FORMAT "WCOFF"]				; オブジェクトファイルを作るモード	
; [INSTRSET "i486p"]				; 486の命令まで使いたいという記述
[BITS 32]						; 32ビットモード用の機械語を作らせる
;[FILE "api001.nas"]				; ソースファイル名情報

        GLOBAL	api_end

[SECTION .text]

api_end:		; void api_end(void)
		MOV		EDX,4
		INT		0x40