; [FORMAT "WCOFF"]				; オブジェクトファイルを作るモード	
; [INSTRSET "i486p"]				; 486の命令まで使いたいという記述
[BITS 32]						; 32ビットモード用の機械語を作らせる
;[FILE "alloca.nas"]				; ソースファイル名情報

        GLOBAL  __alloca

[SECTION .text]

__alloca:
        ADD     EAX, -4
        SUB     ESP, EAX
        JMP     DWORD [ESP+EAX]