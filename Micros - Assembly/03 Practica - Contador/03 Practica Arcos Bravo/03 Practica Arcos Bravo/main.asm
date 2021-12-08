;
; 03 Practica Arcos Bravo.asm
;
; Created: 14/09/2021 03:21:50 p. m.
; Author : David Gamaliel Arcos
;



; A entrada con pull up
ldi r16, 0b0000_0000
out ddra,r16
ldi r16, 0b1111_1111
out porta,r16
; C salida con 0v
ldi r16, 0b1111_1111
out ddrc,r16
ldi r16, 0b1111_1111
out portc,r16

; De r0 a r9 cargar en ellos los valores para el display de 0 a 9
;ldi r16, 0b0000_0000
ldi r16, 0b0011_1111 ; 0
mov r0, r16
ldi r16, 0b0000_0110 ; 1
mov r1, r16
ldi r16, 0b0101_1011 ; 2
mov r2, r16
ldi r16, 0b0100_1111 ; 3
mov r3, r16
ldi r16, 0b0110_0110 ; 4
mov r4, r16
ldi r16, 0b0110_1101 ; 5
mov r5, r16
ldi r16, 0b0111_1101 ; 6
mov r6, r16
ldi r16, 0b0000_0111 ; 7
mov r7, r16
ldi r16, 0b0111_1111 ; 8
mov r8, r16
ldi r16, 0b0110_1111 ; 9
mov r9, r16

ldi r16,0

main:
	rcall checkDisplay
	rcall setDisplay
	sbis pina, 0
	rcall aumenta
	sbis pina, 1
	rcall decrementa
	sbis pina, 2
	rcall diez
	rjmp main

setDisplay:
	cpi r16, 0 ; Caso 0
	breq eq0
	cpi r16, 1 ; Caso 1
	breq eq1
	cpi r16, 2 ; Caso 2
	breq eq2
	cpi r16, 3 ; Caso 3
	breq eq3
	cpi r16, 4 ; Caso 4
	breq eq4
	cpi r16, 5 ; Caso 5
	breq eq5
	cpi r16, 6 ; Caso 6
	breq eq6
	cpi r16, 7 ; Caso 7
	breq eq7
	cpi r16, 8 ; Caso 8
	breq eq8
	cpi r16, 9 ; Caso 9
	breq eq9
	ldi r17,0
	out portc,r17
	ret
	eq0: out portc, r0
	ret
	eq1: out portc, r1
	ret
	eq2: out portc, r2
	ret
	eq3: out portc, r3
	ret
	eq4: out portc, r4
	ret
	eq5: out portc, r5
	ret
	eq6: out portc, r6
	ret
	eq7: out portc, r7
	ret
	eq8: out portc, r8
	ret
	eq9: out portc, r9
	ret

checkDisplay:
	cpi r16, 10 ; Caso 10
	breq set0
	cpi r16, 255 ; Caso 255
	breq set9
	ret
	set0: ldi r16,0
	ret
	set9: ldi r16,9
	ret
		

aumenta:  ; pina0
	rcall delayRebote
	inc r16
	cosa:
	sbis pina, 0
		rjmp cosa
ret
decrementa:
	rcall delayRebote
	dec r16
	cosa2:
	sbis pina, 1
		rjmp cosa2
ret
diez:
	; delay rebote
ret


delayRebote:
; delaying 49995 cycles:
          ldi  R20, $65
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