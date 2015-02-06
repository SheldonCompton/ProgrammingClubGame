org 0x0000
jmp main

main:
cli
mov ax, 0x9000 ;Set up stack
mov ss, ax     ;Tell processor where stack is
mov sp, 0xFB00 ;Set stack offset
sti

mov al, 'S'
mov ah, 0x0e
int 0x10

jmp main

times 512-($-$$) db 0