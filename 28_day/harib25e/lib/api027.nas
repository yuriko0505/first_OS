; [FORMAT "WCOFF"]				; オブジェクトファイルを作るモード	
; [INSTRSET "i486p"]				; 486の命令まで使いたいという記述
[BITS 32]						; 32ビットモード用の機械語を作らせる
;[FILE "api027.nas"]				; ソースファイル名情報

		GLOBAL	api_getlang

[SECTION .text]

api_getlang:        ; int api_getlang(void);
        MOV     EDX,27
        INT     0x40
        RET