
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
mov bl, BYTE [rdi + rcx] ;bl = rdi[rcx]
mov bh, BYTE [rsi + rcx] ;bh = rsi[rcx]

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