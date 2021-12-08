	;
; 02 Practica Arcos Bravo.asm
;
; Created: 09/09/2021 03:24:38 p. m.
; Author : David Gamaliel Arcos
;


; Replace with your application code

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

; Set r17 as 1111_0000 to subtract later
ldi r17, 0b1111_0000

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

; ld r16, X+r16 

main:
	; Leer puerto A, y setear en 0 los 4 bits que no se usan
	in r16, pina
	sub r16,r17

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
	
	out portc, r0
	rjmp main

	eq0: out portc, r0
	rjmp main
	eq1: out portc, r1
	rjmp main
	eq2: out portc, r2
	rjmp main
	eq3: out portc, r3
	rjmp main
	eq4: out portc, r4
	rjmp main
	eq5: out portc, r5
	rjmp main
	eq6: out portc, r6
	rjmp main
	eq7: out portc, r7
	rjmp main
	eq8: out portc, r8
	rjmp main
	eq9: out portc, r9
	rjmp main