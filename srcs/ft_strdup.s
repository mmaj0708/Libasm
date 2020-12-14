
section .text
global ft_strdup
extern ft_strcpy
extern ft_strlen
extern error
extern malloc

ft_strdup:

push	rdi		;rdi est modifié une fois qu'une fct est appelée
call	ft_strlen
inc		rax ;rax = le ret de la fct appelée
mov		rdi, rax  ;placer la len de str dans l'arg pr malloc

call	malloc ;l'adr allouée est dans rax
; jz		end ; go to end si malloc fail
pop		rdi ; récup le src_ptr calé sur la stack
mov		rsi, rdi
mov		rdi, rax ; placer les args pour strcpy
call	ft_strcpy
ret

; end:

; push	rax
; call	error
; pop		qword[rax]
; mov		rax, 0
; ret
