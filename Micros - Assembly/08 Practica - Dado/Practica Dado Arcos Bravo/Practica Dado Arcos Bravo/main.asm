;
; Practica Dado Arcos Bravo.asm
;
; Created: 28/10/2021 12:49:11 p. m.
; Author : David Gamaliel Arcos
; Author : Luis Fernando Caro
;*******

.include "m16def.inc"     
   
;*******
;Registros (aqu? pueden definirse)
;.def temporal=r19

;Palabras claves (aqu? pueden definirse)
;.equ LCD_DAT=DDRC
;********

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

;******
;Inicializar el Stack Pointer
;******
Reset:
	ldi r16, high(RAMEND)
	out SPH, r16
	ldi r16, low(RAMEND)
	out SPL, r16 

;***********
;Aqu? comienza el programa...
;No olvides configurar al inicio todo lo que utilizar?s
;***********

LDI R16, 0xFF
out DDRC, R16

SEI
ldi R16, 0b1110_0000
out GIFR, R16

ldi R16, 0b0000_1010
out MCUCR, R16 

ldi R16, 0b0100_0000 
out GICR, R16

LDI R17, 1

MAIN:
	LDI R16, 0XFF
	OUT PORTD, R16
	CPI R17, 7
	BREQ RESETCONT
	BRNE INCCONT
	REG:
	rjmp MAIN 

INCCONT:
	INC R17
	RJMP REG
RESETCONT:
	LDI R17, 1 
	RJMP REG

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

uno: ldi r19, 0b0000_1000
rjmp fin

dos: ldi r19, 0b0010_0010
rjmp fin

tres: ldi r19, 0b0001_1100
rjmp fin

cuatro: ldi r19, 0b0101_0101
rjmp fin

cinco: ldi r19, 0b0101_1101
rjmp fin

seis: ldi r19, 0b0111_0111
rjmp fin

siete: ldi r19, 0b0111_1111
rjmp fin

dado:
	cpi r17, 1
	breq uno
	cpi r17, 2
	breq dos
	cpi r17, 3
	breq tres
	cpi r17, 4
	breq cuatro
	cpi r17, 5
	breq cinco
	cpi r17, 6
	breq seis
	cpi r17, 7
	breq siete
	fin:
	out portc, r19
ret

;***********
;Aqu? est? el manejo de las interrupciones concretas
;***********
EXT_INT0: ; IRQ0 Handler
	rcall delayRebote
	rcall delayRebote
	rcall dado
	// out PORTC, R17
	rcall delayRebote
	rcall delayRebote
	rcall delayRebote
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

