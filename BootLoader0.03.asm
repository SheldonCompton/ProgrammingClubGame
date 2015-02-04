org 7C00h

jmp 0x0:start

start:
cli
mov ax, 0x9000 ;Set up stack
mov ss, ax     ;Tell processor where stack is
mov sp, 0xFB00 ;Set stack offset
sti

;http://www.delorie.com/djgpp/doc/rbinter/id/14/7.html

mov ah, 0x42 ;extended read function

;dl might need the drive number in it but I think it is preloaded with the drive #
;of where we booted from

;(Sheldon)for ds:si I'm not sure how to create a disk address packet(see website)

int 0x13


times 510-($-$$) db 0 ;Fill rest of sector up with 0s to make this 512B (a sector)
dw 0xAA55             ;Let BIOS know this is an OS
