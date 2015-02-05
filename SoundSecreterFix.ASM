;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Sudokuu's Superior Sound Secreter
; Version: acid.1
; Last Revised: 2015 Feb 04 23:58
;
; Notes: This is the BIOS version of the
; code so it can be run as stand-alone
; code. Secreter code is contained in .o0@
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

use16		; use 16 bit real mode
org	7c00h	; BIOS origin has to be 7C00 hex for some reason


;@0o.o0@0o.o0@0o.o0@0o.o0@;
mov	al, 182 	; Prepare the speaker by
out	43h, al 	; setting port 43h to 182
mov	ax, 4560	;*decide the frequency - aside: 4560 is Middle C
out	42h, al 	; output low byte to 42h (port 42h is an 8-bit port)
mov	al, ah		; move high into low byte
out	42h, al 	; output high byte(now low byte)to 42h
in	al, 61h 	; get port 61h's value
or	al, 00000011b	; set the two rightmost bits to 1
out	61h, al 	; output new value back into 61h
mov	bx, 25		;*decide the duration

.pause1:		;
mov	cx, 65535	; set cx to 65535

.pause2:		;
dec	cx		; decrement cx
jne	.pause2 	; go back to .pause2 - effect: pause for 65535 ticks
dec	bx		; decrement bx
jne	.pause1 	; go back to .pause1 - effect: pause for bx ticks
in	al, 61h 	; get value of 61h
and	al, 11111100b	; set the two rightmost bits to 0
out	61h, al 	; output new value back into 61h
;@0o.o0@0o.o0@0o.o0@0o.o0@;

times	510-($-$$) db 0 ; fill remaining space in sector with zeroes
dw	0xAA55		; tell BIOS we are an OS
