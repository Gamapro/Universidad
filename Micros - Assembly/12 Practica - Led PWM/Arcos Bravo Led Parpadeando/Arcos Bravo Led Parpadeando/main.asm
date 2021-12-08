;
; Arcos Bravo Led Parpadeando.asm
;
; Created: 18/11/2021 03:51:16 p. m.
; Author : David Gamaliel Arcos
;
;******************************************************
.include "m16def.inc"        
;******************************************************
;Registros (aquí pueden definirse)
.def cont=r17
.def dir=r18
;Palabras claves (aquí pueden definirse)
;.equ LCD_DAT=DDRC
;******************************************************
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

ldi r16, 0xFF
out ddrb, r16
ldi r16, 0x00
out portb, r16

ldi r16, 0b0000_0011
out ddra, r16
ldi r16, 0b1111_1101
out porta, r16

ldi r25, 25

; configurar timer
sei						; Set interruptions
ldi r16,0 
out tcnt0, r16			; Cuenta el num de ciclos
ldi r16, 0b0000_0011
out tifr, r16			; Banderas
ldi r16, 0b0000_0000	; 01 Por oveflow 10 por cmp
out timsk, r16			; Cual interrupcion usar
ldi r16, 0
out ocr0, r16			; Tope a comparar 
ldi r16, 0b0110_1001	; Preescaler de 1 
out tccr0, r16			; Modo FasetPWM, inicio en 1

rcall clrRegs

main:
	cpi cont, 250
	breq izq
	cpi cont, 0
	breq der
	brne turnoff
	retLed:

	sbis pina, 2
	rcall incre
	sbis pina, 3
	rcall decre

	out ocr0, cont			; Tope a comparar 
rjmp main

clrRegs:
	ldi dir, 0
	ldi cont, 0
ret

izq:
	ldi r16, 0b1111_1110
	out porta, r16
rjmp retLed

turnoff:
	ldi r16, 0b1111_1100
	out porta, r16
rjmp retLed

der:
	ldi r16, 0b1111_1101
	out porta, r16
rjmp retLed

incre:
	rcall delay
	cpi cont, 250
	breq skp
	add cont, r25
	skp:sbis pina, 2
	rjmp skp
	rcall delay
ret

decre:
	rcall delay
	cpi cont, 0
	breq skp2
	sub cont, r25
	skp2: sbis pina, 3
	rjmp skp2
	rcall delay
ret

delay:
          ldi  R30, $65
WGLOOP0:  ldi  R31, $A4
WGLOOP1:  dec  R31
          brne WGLOOP1
          dec  R30
          brne WGLOOP0
          ldi  R30, $01
WGLOOP2:  dec  R30
          brne WGLOOP2
          nop
          nop
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

