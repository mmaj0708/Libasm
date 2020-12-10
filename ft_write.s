

section	.text:

;rdi = 1st arg (fd)
;rsi = 2nd arg (addr start)
;rdx = 3 arg (nb of char)

global	ft_write

ft_write:

mov rax, 1 ;call for write
syscall
ret