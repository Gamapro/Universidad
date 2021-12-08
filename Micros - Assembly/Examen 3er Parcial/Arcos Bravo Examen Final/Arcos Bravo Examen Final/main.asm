;
; Arcos Bravo Examen Final.asm
;
; Created: 30/11/2021 11:10:13 a. m.
; Author : David Gamaliel Arcos
;

/*
	TABLA

	   OCR0 |   Tiempo en alto  |  Angulo   |   Rango
	-------------------------------------------------
		86	|		0.000696	|	   0	|	0-9
		87	|		0.000704	|	  20	|	10-29
		88	|		0.000712	|	  40	|	30-49
		89	|		0.000720	|	  60	|	50-69
		90	|		0.000728	|	  80	|	70-89
		91	|		0.000736	|	 100	|	90-99

	; 86 -> 0 y 95 -> 180
	; 87 - 20 88 - 40 89 - 60 90 - 80 91 - 100


*/

;******************************************************
.include "m16def.inc"     
;******************************************************
;*******************
;Registros (aqui pueden definirse)
.def cont=r25
.def numDisp=r23
.def aux=r22
.def disp=r24
.def num=r21
.def rt=r17
;Palabras claves (aqu? pueden definirse)
;.equ LCD_DAT=DDRC
.equ MAT_DAT=DDRA
.equ MAT_PORT=PORTA
.equ MAT_PIN=PINA

.equ OUT_DAT=DDRB
.equ OUT_PORT=PORTB
;********************


.org 0x0000
;Comienza el vector de interrupciones.

jmp RESET ; Reset Handler
jmp EXT_INT0 ; IRQ0 Handler
jmp EXT_INT1 ; IRQ1 Handler
jmp TIM2_COMP ; Timer2 Compare Handler
jmp TIM2_OVF ; Timer2 Overflow Handler
jmp TIM1_CAPT ; Timer1 Capture Handler
jmp TIM1_COMPA ; Timer1 CompareA Handler
jmp TIM1_COMPB ; Timer1 CompareB Handler
jmp TIM1_OVF ; Timer1 Overflow Handler
jmp TIM0_OVF ; Timer0 Overflow Handler
jmp SPI_STC ; SPI Transfer Complete Handler
jmp USART_RXC ; USART RX Complete Handler
jmp USART_UDRE ; UDR Empty Handler
jmp USART_TXC ; USART TX Complete Handler
jmp ADC_COMP ; ADC Conversion Complete Handler
jmp EE_RDY ; EEPROM Ready Handler
jmp ANA_COMP ; Analog Comparator Handler
jmp TWSI ; Two-wire Serial Interface Handler
jmp EXT_INT2 ; IRQ2 Handler
jmp TIM0_COMP ; Timer0 Compare Handler
jmp SPM_RDY ; Store Program Memory Ready Handler
; Termina el vector de interrupciones.


;******************************************************
;Aquí comenzará el programa
;******************************************************
Reset:

;Primero inicializamos el stack pointer...
ldi r16, high(RAMEND)
out SPH, r16
ldi r16, low(RAMEND)
out SPL, r16 


;******************************************************

;No olvides configurar al inicio los puertos que utilizarás

;También debes configurar si habrá o no pull ups en las entradas

;Para las salidas deberás indicar cuál es la salida inicial

;Los registros que vayas a utilizar inicializalos si es necesario
;******************************************************

ldi r16, 10
mov r10, r16

; MATRIZ

ldi R16, 0b111_00000
out MAT_DAT, R16
ldi R16, 0xFF
out MAT_PORT, R16

; PORT D C B COMO SALIDAS
ldi r16, 0xFF
out ddrc, r16
out ddrd, r16
out ddrb, r16
ldi r16, 0x00
out portc, r16
out portd, r16
out portb, r16

; Servo
sei						; Set interruptions
ldi r16,0 
out tcnt0, r16			; Cuenta el num de ciclos
ldi r16, 0b0000_0011
out tifr, r16			; Banderas
ldi r16, 0b0000_0000	; 01 Por oveflow 10 por cmp
out timsk, r16			; Cual interrupcion usar
ldi r16, 86
out ocr0, r16			; Tope a comparar 
ldi r16, 0b0110_1011	; Preescaler de 64 
out tccr0, r16			; Modo FasetPWM, inicio en 1
rcall clrRegs
rcall moveServo

main:

	ldi R16, 0b110_11111
	out MAT_PORT, R16
	nop 
	nop

	sbis MAT_PIN, 4
	rcall C1
	sbis MAT_PIN, 3
	rcall C4
	sbis MAT_PIN, 2
	rcall C7
	sbis MAT_PIN, 1
	rcall AST

	ldi R16, 0b101_11111
	out MAT_PORT, R16
	nop 
	nop

	sbis MAT_PIN, 4
	rcall C2
	sbis MAT_PIN, 3
	rcall C5
	sbis MAT_PIN, 2
	rcall C8
	sbis MAT_PIN, 1
	rcall C0

	ldi R16, 0b011_11111
	out MAT_PORT, R16
	nop 
	nop

	sbis MAT_PIN, 4
	rcall C3
	sbis MAT_PIN, 3
	rcall C6
	sbis MAT_PIN, 2
	rcall C9
	sbis MAT_PIN, 1
	rcall GATO

rjmp main

clrRegs:
	ldi cont, 0
	ldi num, 0
	ldi aux, 0
	ldi disp, 0
	ldi numDisp , 0
	ldi rt, 0
	rcall outDisplay
ret

outDisplay:
	mov aux, disp
	swap aux
	andi aux, 0x0F
	out portc, aux

	mov aux, disp
	andi aux, 0x0F
	out portd, aux
ret

display:
	cpi cont, 2
	brge salto
	
	inc cont

	mul num, r10
	mov num, r0
	add num, aux

	swap disp
	andi disp, 0xF0
	or disp, numDisp

	rcall outDisplay

	salto:
ret

cero:
	ldi rt, 86	; cero grados
	out ocr0, rt			; Tope a comparar 
rjmp servoFinish
veinte:
	ldi rt, 87	; 20 grados
	out ocr0, rt			; Tope a comparar 
rjmp servoFinish
cuarenta:
	ldi rt, 88	; 40 grados
	out ocr0, rt			; Tope a comparar 
rjmp servoFinish
sesenta:
	ldi rt, 89	; 60 grados
	out ocr0, rt			; Tope a comparar 
rjmp servoFinish
ochenta:
	ldi rt, 90	; 80 grados
	out ocr0, rt			; Tope a comparar 
rjmp servoFinish
cien:
	ldi rt, 91	; 100 grados
	out ocr0, rt			; Tope a comparar 
rjmp servoFinish

moveServo:
	; 86 -> 0 y 95 -> 180
	; 87 - 20 88 - 40 89 - 60 90 - 80 91 - 100
	cpi num, 10
	brlo cero
	cpi num, 30
	brlo veinte
	cpi num, 50
	brlo cuarenta
	cpi num, 70
	brlo sesenta
	cpi num, 90
	brlo ochenta
	cpi num, 100
	brlo cien
	servoFinish:
ret

C0:
	rcall delayRebote

	ldi aux, 0
	ldi numDisp, 0b0000_0000
	rcall display

    btn4:
		sbis MAT_PIN, 1
		rjmp btn4
	rcall delayRebote
ret

C1:
    rcall delayRebote

	ldi aux, 1
	ldi numDisp, 0b0000_1000
	rcall display

    btn3:
		sbis MAT_PIN, 4
		rjmp btn3
    rcall delayRebote
ret

C2:
	rcall delayRebote

	ldi aux, 2
	ldi numDisp, 0b0000_0100
	rcall display

    btn7:
		sbis MAT_PIN, 4
		rjmp btn7
    rcall delayRebote
ret

C3:
	rcall delayRebote

	ldi aux, 3
	ldi numDisp, 0b0000_1100
	rcall display

    btn11:
		sbis MAT_PIN, 4
		rjmp btn11
    rcall delayRebote
ret

C4:
	rcall delayRebote

	ldi aux, 4
	ldi numDisp, 0b0000_0010
	rcall display

    btn2:
		sbis MAT_PIN, 3
		rjmp btn2
    rcall delayRebote
	ret

C5:
    rcall delayRebote
	
	ldi aux, 5
	ldi numDisp, 0b0000_1010
	rcall display

    btn6:
		sbis MAT_PIN, 3
		rjmp btn6
    rcall delayRebote
	ret

C6:
	rcall delayRebote

	ldi aux, 6
	ldi numDisp, 0b0000_0110
	rcall display

    btn10:
		sbis MAT_PIN, 3
		rjmp btn10
    rcall delayRebote
	ret

C7:
	rcall delayRebote

	ldi aux, 7
	ldi numDisp, 0b0000_1110
	rcall display

    btn1:
		sbis MAT_PIN, 2
		rjmp btn1
    rcall delayRebote
	ret

C8:
	rcall delayRebote

	ldi aux, 8
	ldi numDisp, 0b0000_0001
	rcall display

    btn5:
		sbis MAT_PIN, 2
		rjmp btn5
    rcall delayRebote
	ret

C9:
	rcall delayRebote

	ldi aux, 9
	ldi numDisp, 0b0000_1001
	rcall display

    btn9:
		sbis MAT_PIN, 2
		rjmp btn9
    rcall delayRebote
	ret

moveServoAux:
	rcall moveServo
rjmp retMoveServoAux

AST:
	rcall delayRebote

	cpi cont, 2
	breq moveServoAux
	retMoveServoAux:

    btn0:
		sbis MAT_PIN, 1
		rjmp btn0
    rcall delayRebote
	ret

GATO:
	rcall delayRebote

	rcall clrRegs
	rcall moveServo

    btn8:
		sbis MAT_PIN, 1
		rjmp btn8
    rcall delayRebote
	ret

delayRebote:
; ============================= 
;    delay loop generator 
;     400000 cycles:
; ----------------------------- 
; delaying 399999 cycles:
          ldi  R27, $97
WGLOOP0:  ldi  R28, $06
WGLOOP1:  ldi  R29, $92
WGLOOP2:  dec  R29
          brne WGLOOP2
          dec  R28
          brne WGLOOP1
          dec  R27
          brne WGLOOP0
; ----------------------------- 
; delaying 1 cycle:
          nop
; ============================= 
ret


;******************************************************

;Aquí están las rutinas para el manejo de las interrupciones concretas

;******************************************************

EXT_INT0: ; IRQ0 Handler
reti
EXT_INT1: 
reti ; IRQ1 Handler
TIM2_COMP: 
reti ; Timer2 Compare Handler
TIM2_OVF: 
reti ; Timer2 Overflow Handler
TIM1_CAPT: 
reti ; Timer1 Capture Handler
TIM1_COMPA: 
reti ; Timer1 CompareA Handler
TIM1_COMPB: 
reti ; Timer1 CompareB Handler
TIM1_OVF: 
reti ; Timer1 Overflow Handler
TIM0_OVF: 
reti ; Timer0 Overflow Handler
SPI_STC: 
reti ; SPI Transfer Complete Handler
USART_RXC: 
reti ; USART RX Complete Handler
USART_UDRE: 
reti ; UDR Empty Handler
USART_TXC: 
reti ; USART TX Complete Handler
ADC_COMP: 
reti ; ADC Conversion Complete Handler
EE_RDY: 
reti ; EEPROM Ready Handler
ANA_COMP: 
reti ; Analog Comparator Handler
TWSI: 
reti ; Two-wire Serial Interface Handler
EXT_INT2: 
reti ; IRQ2 Handler
TIM0_COMP: 
reti
SPM_RDY: 
reti ; Store Program Memory Ready Handler



