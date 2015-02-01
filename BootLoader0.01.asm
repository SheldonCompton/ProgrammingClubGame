org 7C00h

jmp 0x0:start

start:
cli
mov ax, 0x9000 ;Set up stack
mov ss, ax     ;Tell processor where stack is
mov sp, 0xFB00 ;Set stack offset
sti


mov ah, 0Eh ;Tell bios we're writing a char to screen!
mov al, 'L' ;Load a new character into memory
int 10h     ;Call BIOS video interrupt
mov al, 'o'
int 10h
mov al, 'a'
int 10h
mov al, 'd'
int 10h
mov al, 'i'
int 10h
mov al, 'n'
int 10h
mov al, 'g'
int 10h

jmp $

times 510-($-$$) db 0 ;Fill rest of sector up with 0s to make this 512B (a sector)
dw 0xAA55             ;Let BIOS know this is an OS
