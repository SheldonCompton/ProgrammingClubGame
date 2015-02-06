org 7C00h

;;;;;;;;;;;;;;;;;;;
;DO NOT MODIFY DL!;
;;;;;;;;;;;;;;;;;;;

jmp 0x0:start

start:
cli
xor ax,ax
mov ds,ax
mov es,ax
mov ss,ax
mov sp,0x7C00
sti

mov ah, 0x0e
mov al, '1'
int 0x10

mov ah, 0x42

int 0x13
jc error

jmp	0x0:0x0		;jump to the loaded kernel

error:
mov ah, 0x0e
mov al, 'E'	
int 0x10

DiskAddressPacket:
db 0x10		;size of packet
db 0x0		;reserved
dw 0x1		;number of blocks to transfer
dw 0x0		;where in memory to load to
dw 0x0		;offset
dq 0x1		;starting block to read
dq 0x0


times 510-($-$$) db 0 ;Fill rest of sector up with 0s to make this 512B (a sector)
dw 0xAA55             ;Let BIOS know this is an OS
