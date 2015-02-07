;|





	org 0x1600

	USE16

	cli		; disable all interrupts

	lgdt [cs:GDTR]	; load GDT register

	mov  eax,cr0	; switch to protected (32-bit) mode
	or   al,1
	mov  cr0,eax

	jmp  CODE_SELECTOR:pm_start

NULL_SELECTOR = 0
DATA_SELECTOR = 1 shl 3 	; flat data selector (ring 0)
CODE_SELECTOR = 2 shl 2 	; 32-bit code selector (ring 0)
LONG_SELECTOR = 3 shl 3 	; 64-bit code selector (ring 0)

GDTR:				; Global Descriptors Table Register
  dw 4*8-1			; limit of GDT (size minus one)
  dq GDT			; linear address of GDT

GDT rw 4			; null descriptor
    dw 0xFFFF,0,0x9200,0x8F	; flat data descriptor
    dw 0xFFFF,0,0x9A00,0xCF	; 32-bit code descriptor
    dw 0xFFFF,0,0x9A00,0xAF	; 64-bit code descriptor

	USE32
pm_start:
	mov	eax,DATA_SELECTOR	; load 4 GB data descriptor
	mov	ds,ax			; to all data segment registers
	mov	es,ax
	mov	fs,ax
	mov	gs,ax
	mov	ss,ax

	mov	eax,DATA_SELECTOR	; enable physical-address extensions
	or	eax,1, shl 5
	mov	cr4,eax

	mov	edi,0x70000
	mov	ecx,0x4000 shr 2
	xor	eax,eax
	rep	stosd			; clear page tables

	mov	dword [0x70000],0x71000 + 111b ; first PDP table
	mov	dword [0x71000],0x72000 + 111b ; first page directory
	mov	dword [0x72000],0x73000 + 111b ; first page table

	mov	edi,0x73000		 ; address of first page table
	mov	eax,0 + 111b
	mov	ecx,256 		; number of pages to map (1 MB)
  make_page_entries:
	stosd
	add	edi,4
	add	eax,0x1000
	loop	make_page_entries

	mov	eax,0x70000
	mov	cr3,eax 		; load page-map level-4 base

	mov	ecx,0xC0000080		; EFER MSR
	rdmsr
	or	eax,1 shl 8		; enable long mode
	wrmsr


	mov	eax,cr0
	or	eax,1 shl 31
	mov	cr0,eax 		; enable paging

	jmp	LONG_SELECTOR:long_start

	USE64

long_start:

	mov	al,10001b		; begin PIC 1 initialization
	out	0x20,al
	mov	al,10001b		; begin PIC 2 initialization
	out	0xA0,al
	mov	al,0x80 		; IRQ 0-7: interrupts 80h-87h
	out	0x21,al
	mov	al,0x88 		; IRQ 8-15: interrupts 88h-8Fh
	out	0xA1,al
	mov	al,100b 		; slave connected to IRQ2
	out	0x21,al
	mov	al,2
	out	0xA1,al
	mov	al,1			; Intel environment, manual EOI
	out	0x21,al
	out	0xA1,al
	in	al,0x21
	mov	al,11111100b		; enable only clock and keyboard IRQ
	out	0x21,al
	in	al,0xA1
	mov	al,11111111b
	out	0xA1,al

	xor	edi,edi 		; create IDT (at linear address 0)
	mov	ecx,21
  make_exception_gates: 		; make gates for exception handlers
	mov	esi,exception_gate
	movsq
	movsq
	loop	make_exception_gates
	mov	ecx,256-21
  make_interrupt_gates: 		; make gates for the other interrupts
	mov	esi,interrupt_gate
	movsq
	movsq
	loop	make_interrupt_gates

	mov	word [0x80*16],clock	 ; set IRQ 0 handler
	mov	word [0x81*16],keyboard  ; set IRQ 1 handler

	lidt	[IDTR]			; load IDT register

	sti				; now we may enable the interrupts

  main_loop:

	mov	rax,'L O N G '
	mov	[0xB8000],rax

	jmp	main_loop


IDTR:					; Interrupt Descriptor Table Register
  dw 256*16-1				; limit of IDT (size minus one)
  dq 0					; linear address of IDT

exception_gate:
  dw exception and 0xFFFF,LONG_SELECTOR
  dw 0x8E00,exception shr 16
  dd 0,0

interrupt_gate:
  dw interrupt and 0xFFFF,LONG_SELECTOR
  dw 0x8F00,interrupt shr 16
  dd 0,0

exception:				; exception handler
	in	al,0x61 		; turn on the speaker
	or	al,3
	out	0x61,al
	jmp	exception		; repeat it until reboot

interrupt:				; handler for all other interrupts
	iretq

clock:
	inc	byte [0xB8000+2*80]	; make the ticks appear
	push	rax
	mov	al,0x20
	out	0x20,al
	pop	rax
	iretq

keyboard:
	push	rax
	in	al,0x60
	cmp	al,1			; check for Esc key
	je	reboot
	mov	[0xB8000+2*(80+1)],al	; show the scan key
	in	al,0x61 		; give finishing information
	out	0x61,al 		; to keyboard...
	mov	al,0x20
	out	0x20,al 		; ...and interrupt controller
	pop	rax
	iretq

reboot:
	mov	al,0xFE
	out	0x64,al 		 ; reboot computer
	jmp	reboot
