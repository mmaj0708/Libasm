
global _start

section	.data
msg db "yo man", 0x0a
len equ $ - msg

section .text

_start:

mov rax, 4
mov	rbx, 2
mov rcx, msg
mov rdx, len
int 0x80

mov rax, 1
; mov rbx, 4
int 0x80
