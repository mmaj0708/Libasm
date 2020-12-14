

section	.text:

;rdi = 1st arg (fd)
;rsi = 2nd arg (addr start)
;rdx = 3 arg (nb of char)

global	ft_write
extern	__errno_location ; récup l'adr de errno

ft_write:

mov rax, 1 ;call for write
syscall

cmp rax, 0
jl	error ; jl = jump if < 0
ret

error:

neg		rax
mov		rdi, rax ; ne pas perdre rax
call	__errno_location
mov		[rax], rdi ; set value of errno
mov		rax, -1
ret

; on aurait aussi pu utilisr la stack comme buf au lieu de rdi