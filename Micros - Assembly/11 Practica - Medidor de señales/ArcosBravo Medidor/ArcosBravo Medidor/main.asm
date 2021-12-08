;
; ArcosBravo Medidor.asm
;
; Created: 16/11/2021 04:14:53 p. m.
; Author : David Gamaliel Arcos
;

;******************************************************
.include "m16def.inc"        
;******************************************************
;Registros (aquí pueden definirse)
.def cero=r17
.def aux=r20
.def cont=r19
.def show=r21
.def cont2=r22
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

ldi r16, 10
mov r10, r16

ldi r16, 0xFF
out ddrc, r16
ldi r16, 0x00
out portc, r16

out ddra, r16
out ddrb, r16
out porta, r16
ldi r16, 0xFF
out portb, r16

; configurar timer
sei						; Set interruptions
ldi r16,0 
out tcnt0, r16			; Cuenta el num de ciclos
ldi r16, 0b0000_0011
out tifr, r16			; Banderas
ldi r16, 0b0000_0010
out timsk, r16			; Cual interrupcion usar
ldi r16, 124
out ocr0, r16			; Tope a comparar 
ldi r16, 0b0000_1011	; Preescaler de 1 
out tccr0, r16			; Modo y preescaler

rcall clrRegs
main:
	sbis pinb, 0
	rcall mostrar
rjmp main

mostrar:
	rcall delayRebote

	mov aux, cont
	ldi show, 0
	
	cpi aux, 10
	brlo menor_que_10  ; if low
	suma_10:
	inc show
	sub aux, r10
	cpi aux, 10
	brsh suma_10	; if same or highe
	menor_que_10:
	swap show
	add show, aux
	out portc, show

	tr: 
		sbis pinb, 0
		rjmp tr
	rcall delayRebote
ret

delayRebote:
;    delay loop generator 
;     50000 cycles:
          ldi  R24, $65
WGLOOP0:  ldi  R25, $A4
WGLOOP1:  dec  R25
          brne WGLOOP1
          dec  R24
          brne WGLOOP0
; delaying 3 cycles:
          ldi  R24, $01
WGLOOP2:  dec  R24
          brne WGLOOP2
; delaying 2 cycles:
          nop
          nop
ret

clrRegs:
	ldi aux, 0
	ldi cero, 0
	ldi cont2, 0
	ldi show, 0
	ldi cont, 0
ret

incCero:
	inc cont2
	ldi cero, 0xFF
ret

incUno:
	cpi cero, 0
	brne cambio
	retCambio:
	inc cont2
ret

cambio:
	mov cont, cont2
	ldi cont2, 0
	ldi cero, 0
rjmp retCambio

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
	in r0, SREG
	sbis pina, 0
	rcall incCero
	sbic pina, 0
	rcall incUno
	out SREG, r0
reti
SPM_RDY: 
reti ; Store Program Memory Ready Handler

