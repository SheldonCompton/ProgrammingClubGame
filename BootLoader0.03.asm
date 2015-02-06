org 7C00h


jmp 0x0:start

start:
cli
mov ax, 0x9000 ;Set up stack
mov ss, ax     ;Tell processor where stack is
mov sp, 0xFB00 ;Set stack offset
sti


mov ah, 0x0e
mov al, '1'
int 0x10

mov ah, 0x42 ;extended read function
int 0x13
cmp ah,0
jne error

jmp 	0x880:0xFB00	;jump to the loaded kernel

error:
mov ah, 0x0e
mov al, 'Y'	
int 0x10


DiskAddressPacket:
db 0x10		;size
db 0		
dw 0x20		;# of sectors to transfer
dw 0x0		;transfer buffer (16bitsegment:16bitoffset)
dw 0		;page 0
dd 1		
dd 0

times 510-($-$$) db 0 ;Fill rest of sector up with 0s to make this 512B (a sector)
dw 0xAA55             ;Let BIOS know this is an OS
