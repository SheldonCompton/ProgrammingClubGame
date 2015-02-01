org 7C00h

jmp 0x0:start

start:
cli
mov ax, 0x9000 ;Set up stack
mov ss, ax     ;Tell processor where stack is
mov sp, 0xFB00 ;Set stack offset
sti
jmp printKeyPresses

printKeyPresses:
mov ah, 0x0
int 0x16
mov ah, 0x0e
int 0x10

jmp printKeyPresses


times 510-($-$$) db 0 ;Fill rest of sector up with 0s to make this 512B (a sector)
dw 0xAA55             ;Let BIOS know this is an OS
