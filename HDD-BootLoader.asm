use16
org 7C00h

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;BOOTLOADER FOR HDD AND USB DRIVES EMULATING HDD;
;DO NOT MODIFY REGISTER DL                      ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

jmp start

start:

cli
mov ax, 0x0200	;start the stack after the bootloader
mov ss, ax	
mov ax, 0xC00	;make the stack 3k big later this will need to be changed and hardware detection added
mov ax, sp	;but for now this will work.
mov ax, ds
sti

mov ah, 0x0e
mov al, '1'
int 0x10

mov ah, 0x42
mov si, DiskAddressPacket
int 0x13
jc error


jmp	0xA00:0x0200

error:
mov ah, 0x0e
mov al, 'E'	
int 0x10


DiskAddressPacket:
db 0x10		;size of packet
db 0x0		;reserved
dw 0x1		;number of blocks to transfer
dw 0xA00	;where in memory to write to
dw 0x200	;offset
dq 0x2		;starting block to read
dd 0x0

times 510-($-$$) db 0 ;Fill rest of sector up with 0s to make this 512B (a sector)
dw 0xAA55             ;Let BIOS know this is an OS


