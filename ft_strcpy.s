
section .text

global ft_strcpy

;rdi = 1st arg
;rsi = 2nd arg
;bl = buffer to save char

ft_strcpy:

mov	rcx, 0

copy:

mov	bl, BYTE [rsi + rcx] ; bl = rsi[rcx]
mov	BYTE [rdi + rcx], bl
cmp	BYTE [rsi + rcx], 0
je	end
inc	rcx
jmp	copy

end:

mov rax, rdi
ret
