
section .text

global ft_strcmp

;rdi = 1st arg
;rsi = 2nd arg

ft_strcmp:

mov rax, 0
mov rbx, 0
mov rcx, -1

inc:

inc rcx

cmp:

;transfer de buff
mov bl, [rdi + rcx] ;bl = rdi[rcx]
mov bh, [rsi + rcx] ;bh = rsi[rcx]

;vérif si pas en fin de fichier
cmp bl, 0
je end
cmp bh, 0
je end

;vérif si char equal
cmp bl, bh
je	inc

end:

sub		bl, bh
movsx	rax, bl
ret

; section .text
; global ft_strcmp

; ft_strcmp:
; 	mov rcx, 0
; 	mov rax, 0

; loop:
; 	mov cl, [rdi]
; 	mov al, [rsi]
; 	inc rdi
; 	inc rsi
; 	; jmp check

; check:
; 	cmp cl, 0
; 	je ret_diff
; 	cmp al, cl
; 	je loop
; 	; jne ret_diff

; ret_diff:
; 	sub al, cl
; 	jc correct_overflow
; 	neg rax
; 	ret

; correct_overflow:
; 	mov dl, 255
; 	sub dl, al
; 	mov al, dl
; 	inc rax
; 	ret