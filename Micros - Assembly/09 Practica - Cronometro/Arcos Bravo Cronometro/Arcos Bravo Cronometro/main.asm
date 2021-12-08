;
; Arcos Bravo Cronometro.asm
;
; Created: 10/11/2021 06:06:18 p. m.
; Author : David Gamaliel Arcos
;
;******************************************************


.include "m16def.inc"     
 
   
;******************************************************
;Registros (aquí pueden definirse)
.def active=r19
.def minuto=r18
.def segundo=r17
.def aux=r20
.def aux2=r21
.def scaler=r22
.def contador=r23
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

ldi r16, 0x00
out ddra, r16

ldi r16, 0xFF
out ddrc, r16
out ddrd, r16 
out porta, r16 
ldi r16, 0x00
out portc, r16
out portd, r16


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
ldi r16, 0b0000_1100	; Preescaler de 256, 
out tccr0, r16			; Modo y preescaler

; Ciclo de 0.008 seg
ldi scaler, 125
; Aumentar a 125 para llegar al segundo
ldi contador, 0

main:
rjmp main

lol:
	rcall show
rjmp retCallShow

callShow:
	cpi minuto, 5
	brne lol
	retCallShow:
rjmp afterCall

activar:
	rcall delayRebote
	ldi active, 0xFF
	rcall clearRegs
	rcall showPuertos
	trabaActivar:
	sbis pina, 0
	rjmp trabaActivar
	rcall delayRebote
ret

limpiar:
	rcall delayRebote
	ldi active, 0x00
	rcall clearRegs
	rcall showPuertos
	trabaLimpiar:
	sbis pina, 7
	rjmp trabaLimpiar
	rcall delayRebote
ret

checkButtons:
	sbis pina, 0
	rcall activar
	sbis pina, 7
	rcall limpiar
ret

show:
	inc segundo
	cpi segundo, 60
	breq aumMinuto
	retAum:
ret

aumMinuto:
	ldi segundo, 0
	inc minuto
rjmp retAum

clearRegs:
	ldi segundo, 0
	ldi minuto , 0
ret

clear:
	rcall clearRegs
rjmp retClear

showPuertos:
	out portc, minuto
	ldi aux2, 0
	mov aux, segundo
	cpi aux, 10
	brlo menor_que_10  ; if low
	suma_10:
	inc aux2
	sub aux, r10
	cpi aux, 10
	brsh suma_10  ; if same or higher
	menor_que_10:
	swap aux2
	cpi aux, 0
	breq es_cero
	no_cero:
	inc aux2
	dec aux
	cpi aux, 0
	brne no_cero
	es_cero:
	out portd, aux2
ret

checkAll:
	ldi contador, 0
	cpi active, 0
	brne callShow
	afterCall:
	cpi active, 0
	breq clear
	retClear:
	rcall showPuertos
rjmp retcheckAll


delayRebote:
; ============================= 
;    delay loop generator 
;     250000 cycles:
; ----------------------------- 
; delaying 249999 cycles:
          ldi  R24, $A7
WGLOOP0:  ldi  R25, $02
WGLOOP1:  ldi  R26, $F8
WGLOOP2:  dec  R26
          brne WGLOOP2
          dec  R25
          brne WGLOOP1
          dec  R24
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
	; cosas
	rcall checkButtons
	inc contador
	cp contador, scaler 
	breq checkAll
	retcheckAll:
reti
SPM_RDY: 
reti ; Store Program Memory Ready Handler



