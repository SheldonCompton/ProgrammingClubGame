use16
org 0x0000
jmp main

main:

mov al, 'S'
mov ah, 0x0e
int 0x10

jmp $

times 512-($-$$) db 0