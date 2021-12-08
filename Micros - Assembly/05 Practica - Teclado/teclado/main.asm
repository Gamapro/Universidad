;Palabras claves (aqu? pueden definirse)
;.equ LCD_DAT=DDRC
.equ MAT_DAT=DDRA
.equ MAT_PORT=PORTA
.equ MAT_PIN=PINA

.equ OUT_DAT=DDRC
.equ OUT_PORT=PORTC
.org 0x0000



; MATRIZ

ldi R16, 0x0F
out MAT_DAT, R16

ldi R16, 0xFF
out OUT_DAT, R16

ldi R16, 0x00
out OUT_PORT, R16

ldi R17, 0x00



MAT:
	ldi R16, 0b1111_1110
	out MAT_PORT, R16
	nop
	nop

	sbis MAT_PIN, 4
	rcall AST
	btn0:
		sbis MAT_PIN, 4
		rjmp btn0
	sbis MAT_PIN, 5
	rcall C7
	btn1:
		sbis MAT_PIN, 5
		rjmp btn1
	sbis MAT_PIN, 6
	rcall C4
	btn2:
		sbis MAT_PIN, 6
		rjmp btn2
	sbis MAT_PIN, 7
	rcall C1
	btn3:
		sbis MAT_PIN, 7
		rjmp btn3
	ldi R16, 0b1111_1101
	out MAT_PORT, R16
	nop
	nop

	sbis MAT_PIN, 4
	rcall C0
	btn4:
		sbis MAT_PIN, 4
		rjmp btn4
	sbis MAT_PIN, 5
	rcall C8
	btn5:
		sbis MAT_PIN, 5
		rjmp btn5
	sbis MAT_PIN, 6
	rcall C5
	btn6:
		sbis MAT_PIN, 6
		rjmp btn6
	sbis MAT_PIN, 7
	rcall C2
	btn7:
		sbis MAT_PIN, 7
		rjmp btn7

	ldi R16, 0b1111_1011
	out MAT_PORT, R16
	nop
	nop

	sbis MAT_PIN, 4
	rcall GATO
	btn8:
		sbis MAT_PIN, 4
		rjmp btn8
	sbis MAT_PIN, 5
	rcall C9
	btn9:
		sbis MAT_PIN, 5
		rjmp btn9
	sbis MAT_PIN, 6
	rcall C6
	btn10:
		sbis MAT_PIN, 6
		rjmp btn10
	sbis MAT_PIN, 7
	rcall C3
	btn11:
		sbis MAT_PIN, 7
		rjmp btn11

	ldi R16, 0b1111_0111
	out MAT_PORT, R16
	nop
	nop

	sbis MAT_PIN, 4
	rcall CD
	btn12:
		sbis MAT_PIN, 4
		rjmp btn12
	sbis MAT_PIN, 5
	rcall CC
	btn13:
		sbis MAT_PIN, 5
		rjmp btn13
	sbis MAT_PIN, 6
	rcall CB
	btn14:
		sbis MAT_PIN, 6
		rjmp btn14
	sbis MAT_PIN, 7
	rcall CA
	btn15:
		sbis MAT_PIN, 7
		rjmp btn15
	out OUT_PORT, R17
	rjmp MAT

C0:
	rcall delayRebote
	andi R17, 0xF0
	swap R17
	out OUT_PORT, R17
	ret

C1:
	rcall delayRebote
	andi R17, 0xF0
	ori R17, 1
	swap R17
	out OUT_PORT, R17
	ret
C2:
	rcall delayRebote
	andi R17, 0xF0
	ori R17, 2
	swap R17
	out OUT_PORT, R17
	ret
C3:
	rcall delayRebote
	andi R17, 0xF0
	ori R17, 3
	swap R17
	out OUT_PORT, R17
	ret
C4:
	rcall delayRebote
	andi R17, 0xF0
	ori R17, 4
	swap R17
	out OUT_PORT, R17
	ret
C5:
	rcall delayRebote
	andi R17, 0xF0
	ori R17, 5
	swap R17
	out OUT_PORT, R17
	ret

C6:
	rcall delayRebote
	andi R17, 0xF0
	ori R17, 6
	swap R17
	out OUT_PORT, R17
	ret

C7:
	rcall delayRebote
	andi R17, 0xF0
	ori R17, 7
	swap R17
	out OUT_PORT, R17
	ret

C8:
	rcall delayRebote
	andi R17, 0xF0
	ori R17, 8
	swap R17
	out OUT_PORT, R17
	ret

C9:
	rcall delayRebote
	andi R17, 0xF0
	ori R17, 9
	swap R17
	out OUT_PORT, R17
	ret

AST:
	rcall delayRebote

	ret

GATO:
	rcall delayRebote

	ret

CA:
	rcall delayRebote

	ret

CB:
	rcall delayRebote

	ret

CC:
	rcall delayRebote

	ret

CD:
	rcall delayRebote

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
