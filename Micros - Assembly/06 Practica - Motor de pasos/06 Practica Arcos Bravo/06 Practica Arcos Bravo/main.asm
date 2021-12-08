;
; 06 Practica Arcos Bravo.asm
;
; Created: 12/10/2021 03:54:41 p. m.
; Author : David Gamaliel Arcos
;


.include "m16def.inc"     
   
;*******************
;Registros (aquí pueden definirse)
;.def temporal=r19

;Palabras claves (aquí pueden definirse)
;.equ LCD_DAT=DDRC
;********************

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

LDI R16, 0X00
OUT DDRB, R16

LDI R16, 0XFF
OUT PORTB, R16

LDI R16, 0XFF
OUT DDRA, R16
LDI R16, 0X00
OUT PORTA, R16

LDI R17, 0B0000_0011

FOO:
	SBIS PINB, 0
	RCALL B0
	SBIS PINB, 1
	RCALL B1
	RJMP FOO

oso: ldi r17, 0b0000_1000
rjmp retOso
oso2: ldi r17, 0b0000_0001
rjmp retOso2

B0:
	rcall delayRebote

	RIGHTR:
		/*LDI R16, 0B0000_0001
		AND R16, R17
		LSL R16
		LSL R16
		LSL R16*/
		LSR R17
		; OR R17, R16
		cpi r17, 0
		breq oso
		retOso:

		OUT PORTA, R17
		
		RCALL delayRebote
		RCALL delayRebote
	
	SBIS PINB, 0
	RJMP RIGHTR
	rcall delayRebote
	RET

B1:
	rcall delayRebote

	LEFTR:
		/*LDI R16, 0B0000_1000
		AND R16, R17

		LSR R16
		LSR R16
		LSR R16*/

		LSL R17
		cpi r17, 0b0001_0000
		breq oso2
		retOso2:
		; OR R17, R16
	
		OUT PORTA, R17

		RCALL delayRebote
		RCALL delayRebote
	
	SBIS PINB, 1
	RJMP LEFTR
	rcall delayRebote
	RET


	delayRebote:
; ============================= 
;    delay loop generator 
;     15000 cycles:
; ----------------------------- 
; delaying 14994 cycles:
          ldi  R22, $15
WGLOOP0:  ldi  R23, $ED
WGLOOP1:  dec  R23
          brne WGLOOP1
          dec  R22
          brne WGLOOP0
; ----------------------------- 
; delaying 6 cycles:
          ldi  R22, $02
WGLOOP2:  dec  R22
          brne WGLOOP2
; ============================= 

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





