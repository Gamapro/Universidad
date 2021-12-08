;
; 04 Practica - David Arcos.asm
;
; Created: 23/09/2021 04:12:36 p. m.
; Author : David Gamaliel Arcos
;


ldi r16, 0      ; entrada porta
out ddra, r16
ldi r16, 0xff   ; pull-ups a
out porta, r16

; ldi r16, 0xff   ; salida portc
out ddrc, r16
ldi r16, 0       ; 0s
out portc, r16

ldi r17,0  ; uno
ldi r18,0  ; dos

main:
	sbis pina, 0
	rcall resetUno ; Caso 0 a0 -> reset uno
	sbis pina, 4
	rcall resetDos ; Caso 1 a4 -> reset dos
	sbis pina, 2
	rcall incUno ; Caso 2 inc uno a2
	sbis pina, 6
	rcall incDos ; Caso 3 inc dos a6 
	rcall loadLEDS
	rjmp main

resetUno:
	rcall delayRebote
	ldi r17,0  ; uno
	cosau:
	sbis pina, 0
		rjmp cosau
	ret

resetDos: ; Caso 1 a4 -> reset dos
	rcall delayRebote
	ldi r18,0  ; dos
	cosad:
	sbis pina, 4
		rjmp cosad
	ret

incUno: ; Caso 2 inc uno a2
	rcall delayRebote
	inc r17
	sbrc r17, 4
	ldi r17,0  ; uno
	cosaui:
	sbis pina, 2
		rjmp cosaui
	ret

incDos: ; Caso 3 inc dos a6 
	rcall delayRebote
	inc r18
	sbrc r18, 4
	ldi r18,0  ; dos
	cosadi:
	sbis pina, 6
		rjmp cosadi
	ret

loadLEDS:
	; r17 - uno     r18 - dos
	ldi r19, 0
	or r19, r17
	swap r19
	or r19, r18
	out portc, r19
	ret


delayRebote:
; delaying 49995 cycles:          ldi  R20, $65
WGLOOP0:  ldi  R21, $A4
WGLOOP1:  dec  R21
          brne WGLOOP1
          dec  R20
          brne WGLOOP0
; ----------------------------- 
; delaying 3 cycles:
          ldi  R20, $01
WGLOOP2:  dec  R20
          brne WGLOOP2
; ----------------------------- 
; delaying 2 cycles:
          nop
          nop
; ============================= 
ret
