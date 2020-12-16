
section .text
global ft_read
extern __errno_location

ft_read:

mov		rax, 0
syscall
cmp		rax, 0
jl		error
ret

error:

neg		rax ; rax contient le ret du syscall qui doit être affecté à errno
mov 	rdi, rax
call	__errno_location
mov		[rax], rdi ; ici [rax] = l'emplacement de errno
mov		rax, -1
ret
