
section .text
global ft_read
; extern __errno_location

ft_read:

mov rax, 0
syscall
ret