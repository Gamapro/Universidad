;
; AssemblerApplication1.asm
;
; Created: 13/11/2021 10:55:56 a. m.
; Author : David Gamaliel Arcos
;

;******************************************************
.include "m16def.inc"        
;******************************************************
;Registros (aquí pueden definirse)
;.def temporal=r19
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
out ddrb, r16
ldi r16, 0x00
out portb, r16

; configurar timer
sei						; Set interruptions
ldi r16,0 
out tcnt0, r16			; Cuenta el num de ciclos
ldi r16, 0b0000_0011
out tifr, r16			; Banderas
ldi r16, 0b0000_0010	
out timsk, r16			; Cual interrupcion usar
ldi r16, 238 ;  -> do	
out ocr0, r16			; Tope a comparar 
ldi r16, 0b0001_1011	; Preescaler de 64, modo ctc, oc0 activado en toggle
;            __ -> 01 toggle 10 apagado 
out tccr0, r16			; Modo y preescaler

ldi r18, 255

main:

	rcall apagar
	rcall delay
	rcall delay
	rcall encender	

	rcall do
	rcall delay24
	rcall re
	rcall delay24
	rcall mi
	rcall delay24
	rcall do
	rcall delay24
	rcall do
	rcall delay24
	rcall re
	rcall delay24
	rcall mi
	rcall delay24
	rcall do
	rcall delay24
	rcall mi
	rcall delay24
	rcall fa
	rcall delay24
	rcall sol
	rcall delay24
	rcall delay24
	rcall delay24
	rcall mi
	rcall delay24
	rcall fa
	rcall delay24
	rcall sol
	rcall delay24
	rcall delay24
	rcall delay24

	rcall apagar
	rcall delay
	rcall encender
	
	rcall sol 
	rcall delay14
	rcall la
	rcall delay14
	rcall sol
	rcall delay14
	rcall fa
	rcall delay14
	rcall mi
	rcall delay24
	rcall do
	rcall delay24
	rcall sol 
	rcall delay14
	rcall la
	rcall delay14
	rcall sol
	rcall delay14
	rcall fa
	rcall delay14
	rcall mi
	rcall delay24
	rcall do
	rcall delay24
	rcall re
	rcall delay24
	rcall sol2
	rcall delay24
	rcall do
	rcall delay24
	rcall delay24
	rcall re
	rcall delay24
	rcall sol2
	rcall delay24
	rcall do
	rcall delay24
	rcall delay24
	rcall delay24

	/*cpi r18, 8
	breq resNotes
	inicio:
	rcall encender
	inc r18 
	cpi r18, 0
	breq nota0
	cpi r18, 1
	breq nota1
	cpi r18, 2
	breq nota2
	cpi r18, 3
	breq nota3
	rcall delay
	inc r18
	cpi r18, 0
	breq callDo
	cpi r18, 1
	breq callRe
	cpi r18, 2
	breq callMi
	cpi r18, 3
	breq callFa
	cpi r18, 4
	breq callSol
	cpi r18, 5
	breq callLa
	cpi r18, 6
	breq callSi
	cpi r18, 7
	breq callDo_*/
	salto:
rjmp main

resNotes:
	ldi r18, 255
rjmp main

apagar:
ldi r16, 0b0000_1011	; Preescaler de 64, modo ctc, oc0 activado en toggle
;            __ -> 01 toggle 10 apagado 
out tccr0, r16			; Modo y preescaler
ldi r16, 0
out portb, r16
ret
encender:
ldi r16, 0b0001_1011	; Preescaler de 64, modo ctc, oc0 activado en toggle
;            __ -> 01 toggle 10 apagado 
out tccr0, r16			; Modo y preescaler
ret

sol2: ldi r16, 149 ; ->
out ocr0, r16			; Tope a comparar 
ret
do: ldi r16, 112 ; ->
out ocr0, r16			; Tope a comparar 
ret
re: ldi r16, 99 ;->
out ocr0, r16			; Tope a comparar 
ret
mi: ldi r16, 88 ;-> 
out ocr0, r16			; Tope a comparar 
ret
fa: ldi r16, 83 ;
out ocr0, r16			; Tope a comparar 
ret
sol: ldi r16, 74 ;
out ocr0, r16			; Tope a comparar 
ret
la: ldi r16, 66
out ocr0, r16			; Tope a comparar 
ret
si: ldi r16, 59 ; ->
out ocr0, r16			; Tope a comparar 
ret
do_: ldi r16, 55
out ocr0, r16			; Tope a comparar 
ret

callDo: rcall do
rjmp salto
callRe: rcall re
rjmp salto
callMi: rcall mi
rjmp salto
callFa: rcall fa
rjmp salto
callSol: rcall sol
rjmp salto
callLa: rcall la
rjmp salto
callSi: rcall si
rjmp salto
callDo_: rcall do_
rjmp salto

delay:
; ============================= 
;    delay loop generator 
;     5000000 cycles:
; ----------------------------- 
; delaying 4999995 cycles:
          ldi  R24, $21
WGLOOP0_:  ldi  R25, $D6
WGLOOP1_:  ldi  R27, $EB
WGLOOP2_:  dec  R27
          brne WGLOOP2_
          dec  R25
          brne WGLOOP1_
          dec  R24
          brne WGLOOP0_
; ----------------------------- 
; delaying 3 cycles:
          ldi  R24, $01
WGLOOP3_:  dec  R24
          brne WGLOOP3_
; ----------------------------- 
; delaying 2 cycles:
          nop
          nop
; ============================= 
ret


delay14:
; ============================= 
;    delay loop generator 
;     2000000 cycles:
; ----------------------------- 
; delaying 1999998 cycles:
          ldi  R24, $12
WGLOOP01:  ldi  R25, $BC
WGLOOP11:  ldi  R26, $C4
WGLOOP21:  dec  R26
          brne WGLOOP21
          dec  R25
          brne WGLOOP11
          dec  R24
          brne WGLOOP01
; ----------------------------- 
; delaying 2 cycles:
          nop
          nop
; ============================= 

ret

delay24:
; ============================= 
;    delay loop generator 
;     4000000 cycles:
; ----------------------------- 
; delaying 3999996 cycles:
          ldi  R24, $24
WGLOOP02:  ldi  R25, $BC
WGLOOP12:  ldi  R26, $C4
WGLOOP22:  dec  R26
          brne WGLOOP22
          dec  R25
          brne WGLOOP12
          dec  R24
          brne WGLOOP02
; ----------------------------- 
; delaying 3 cycles:
          ldi  R24, $01
WGLOOP3:  dec  R24
          brne WGLOOP3
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

