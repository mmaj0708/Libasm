

section	.text:

;rdi = 1st arg (fd)
;rsi = 2nd arg (addr start)
;rdx = 3 arg (nb of char)

global	ft_write
extern	_errno_location

ft_write:

mov rax, 1 ;call for write
syscall

cmp rax, 0
jl	error ; jl = jump if < 0
ret

error:
push rax ; ne pas perdre rax
call _errno_location
mov rax, -1