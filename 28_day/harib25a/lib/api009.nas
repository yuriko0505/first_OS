; [FORMAT "WCOFF"]				; オブジェクトファイルを作るモード	
; [INSTRSET "i486p"]				; 486の命令まで使いたいという記述
[BITS 32]						; 32ビットモード用の機械語を作らせる
;[FILE "api001.nas"]				; ソースファイル名情報

		GLOBAL	api_malloc

[SECTION .text]

api_malloc:		; char *api_malloc(int size);
		PUSH	EBX
		MOV		EDX,9
		MOV		EBX,[CS:0x0020]
		MOV		ECX,[ESP+8]			; size
		INT		0x40
		POP		EBX
		RET
