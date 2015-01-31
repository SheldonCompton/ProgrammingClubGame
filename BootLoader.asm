org 7C00h

jmp 0x0:start
LoadingMessage db 'Loading Kernel...',0
start:
cli
mov ax, 0x9000 ;Set up stack
mov ss, ax     ;Tell processor where stack is
mov sp, 0xFB00 ;Set stack offset
sti

jmp printMessage

printMessage:
mov ah, 0eh
mov si, LoadingMessage

lodsb
cmp ah,0
jz .done
int 10h
jmp printMessage
.done:
jmp $

times 510-($-$$) db 0 ;Fill rest of sector up with 0s to make this 512B (a sector)
dw 0xAA55	      ;Let BIOS know this is an OS
