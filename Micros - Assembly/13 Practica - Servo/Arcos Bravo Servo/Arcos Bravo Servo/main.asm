;
; Arcos Bravo Servo.asm
;
; Created: 25/11/2021 11:13:05 a. m.
; Author : David Gamaliel Arcos
;
;*******************
.include "m16def.inc"     
;*******************
;Registros (aquí pueden definirse)
;.def temporal=r19

.def temp = r16
.def teclado = r22
.def cont = r19

;Palabras claves (aquí pueden definirse)
;.equ LCD_DAT=DDRC
;********************

.equ MAT_DAT=DDRD
.equ MAT_PORT=PORTD
.equ MAT_PIN=PIND

.org 0x0000
;Comienza el vector de interrupciones...
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

;**************
;Inicializar el Stack Pointer
;**************
Reset:
ldi r16, high(RAMEND)
out SPH, r16
ldi r16, low(RAMEND)
out SPL, r16 


;*********************************
;Aquí comienza el programa...
;No olvides configurar al inicio todo lo que utilizarás
;*********************************
ldi r16, 0xFF
out ddrb, r16
ldi r16, 0x00
out portb, r16

sei		
ldi r16,0 
out tcnt0, r16	
ldi r16, 0b0000_0011
out tifr, r16
ldi r16, 0b0000_0000
out timsk, r16
ldi r16, 7
out ocr0, r16	
ldi r16, 0b0110_1100
out tccr0, r16	

ldi temp, 0xff
out ddrc, temp
ldi temp, 1
out portc, temp

ldi R16, 0x0F
out MAT_DAT, R16

rcall delayRebote
rcall op3

main:
	ldi teclado, 0b1111_1110
	out MAT_PORT, teclado
	nop
	nop
	nop
	sbis MAT_PIN, 4
	rcall op1
	sbis MAT_PIN, 5
	rcall op2
	sbis MAT_PIN, 6
	rcall op3

	ldi teclado, 0b1111_1101
	out MAT_PORT, teclado
	nop
	nop
	nop
	sbis MAT_PIN, 4
	rcall op4
	sbis MAT_PIN, 5
	rcall op5

	rjmp main

op1:
	rcall delayRebote

	ldi r16, 1 ; 7
	out ocr0, r16
	
	ldi temp, 1
	out portc, temp

	op1r:
	sbis MAT_PIN, 4
	rjmp op1r
	rcall delayRebote

	ret

op2:
	rcall delayRebote

	ldi r16, 4	; 9 
	out ocr0, r16
	
	ldi temp, 2
	out portc, temp

	op2r:
	sbis MAT_PIN, 5
	rjmp op2r
	rcall delayRebote

	ret

op3:
	rcall delayRebote

	ldi r16, 8 ; 11
	out ocr0, r16
	
	ldi temp, 3
	out portc, temp

	op3r:
	sbis MAT_PIN, 6
	rjmp op3r
	rcall delayRebote

	ret

op4:
	rcall delayRebote

	ldi r16, 12 ; 13
	out ocr0, r16
	
	ldi temp, 4
	out portc, temp

	op4r:
	sbis MAT_PIN, 4
	rjmp op4r
	rcall delayRebote

	ret

op5:
	rcall delayRebote

	ldi r16, 15
	out ocr0, r16
	
	ldi temp, 5
	out portc, temp

	op5r:
	sbis MAT_PIN, 5
	rjmp op5r
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

;*********************************
;Aquí está el manejo de las interrupciones concretas
;*********************************
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



