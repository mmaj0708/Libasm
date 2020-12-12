
section .text

global ft_strlen
; tester d'abord la compil
; pour recup les arg ? syscall ? l'arg1 serait dans rdi ?

ft_strlen :

mov rcx, 0

cmp :

cmp		BYTE [rdi + rcx], 0
je		end ; si derniere cmp est un égal
inc		rcx
jmp		cmp

end :

mov rax, rcx
ret