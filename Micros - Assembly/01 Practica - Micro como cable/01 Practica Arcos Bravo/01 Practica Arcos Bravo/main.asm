;
; 01 Practica Arcos Bravo.asm
;
; Created: 30/09/2021 03:53:40 p. m.
; Author : David Gamaliel Arcos
;

; A entrada con pull up
ldi r16, 0b0000_0000
out ddra,r16
ldi r16, 0b1111_1111
out porta,r16
; C salida con 0v
; ldi r16, 0b1111_1111
out ddrc,r16
ldi r16, 0b1111_1111
out portc,r16

main:
	in r16, pina
	com r16
	out portc, r16
	rjmp main
