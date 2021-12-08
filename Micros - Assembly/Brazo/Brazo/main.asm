;*******************
; Título del proyecto
;
;
; Created: 19/11/2021 05:29:19 p. m.
; Author : David Gamaliel Arcos
; Author : Luis Fernando Caro 
;
;*******************

.include "m16def.inc"     
   
;*******************
;Registros (aquí pueden definirse)
;.def temporal=r19

.def temp=r16
.def grad=r23
.def color=r25

;Palabras claves (aquí pueden definirse)
;.equ LCD_DAT=DDRC
;********************

.equ adat = ddra
.equ aport = porta
.def are = r19

.equ bdat = ddrb
.equ bport = portb
.def bre = r20

.equ cdat = ddrc
.equ cport = portc
.def cre = r21

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

ldi temp, 0xff
out adat, temp
ldi temp, 0x00
out aport, temp

ldi are, 0b0000_0011

ldi temp, 0xff
out bdat, temp
ldi temp, 0x00
out bport, temp

ldi bre, 0b0000_0011

ldi temp, 0xff
out cdat, temp
ldi temp, 0x00
out cport, temp

ldi cre, 0b0000_0011

;-------------------

ldi temp, 0b1000_0000
out ddrd, temp
ldi temp, 0b0011_1111
out portd, temp

rcall delayRebote

main:
	sbis pind, 5
	rcall btn
	sbis pind, 2
	rcall subir_garra
	sbis pind, 1
	rcall bajar_garra
	sbis pind, 3
	rcall abrir_garra
	sbis pind, 4
	rcall cerrar_garra
	sbic pind, 6 
	rcall ledon
	sbis pind, 6
	rcall ledoff
rjmp main
;-------------------

btn:
	rcall delayrebote

	ldi color, 0xFF

	;ldi grad, 0xff
	;rcall b_right ;abre 
	
	ldi grad, 0xff
	rcall a_left ; baja
	ldi grad, 0x8f
	rcall a_left ; baja 

	ldi grad, 0xff
	rcall b_left ; cierra

	sbic pind, 6 
	ldi color, 0x00 ; guardar si color es blanco

	ldi grad, 0xff
	rcall a_right ; sube
	ldi grad, 0x8f
	rcall a_right ; sube

	sbic pind, 6 
	ldi color, 0x00 ; guardar si color es blanco
	
	sbrs color, 0 
	rcall girar_negro
	sbrc color, 0 
	rcall girar_blanco

	btnf: sbis pind, 5
	rjmp btnf

	rcall delayrebote
ret

ledon:
	ldi temp,0b1011_1111
	out portd, temp
	ret 

ledoff:
	ldi temp,0b0011_1111
	out portd, temp
	ret

girar_negro:
	ldi grad, 0xff
	rcall c_right
	ldi grad, 0x4f
	rcall c_right

	ldi grad, 0xff
	rcall b_right ; abre

	ldi grad, 0xff
	rcall c_left
	ldi grad, 0x4f
	rcall c_left

	ret

girar_blanco:
	ldi grad, 0xff
	rcall c_left
	ldi grad, 0x4f
	rcall c_left

	ldi grad, 0xff
	rcall b_right ; abre

	ldi grad, 0xff
	rcall c_right
	ldi grad, 0x4f
	rcall c_right

	ret

subir_garra:
	rcall delayrebote	
	ldi grad, 0x4f
	rcall a_right
	btnf1:
	sbis pind, 2
	rjmp btnf1
	rcall delayrebote
ret
bajar_garra:
	rcall delayrebote	
	ldi grad, 0x4f
	rcall a_left
	btnf2:
	sbis pind, 1
	rjmp btnf2
	rcall delayrebote
ret
abrir_garra:
	rcall delayrebote	
	ldi grad, 0x4f
	rcall b_right
	btnf3:
	sbis pind, 3
	rjmp btnf3
	rcall delayrebote
ret
cerrar_garra:
	rcall delayrebote	
	ldi grad, 0x4f
	rcall b_left
	btnf4:
	sbis pind, 4
	rjmp btnf4
	rcall delayrebote
ret

a_right: a_right_2:
	dec grad
	cpi grad, 0

	breq endra
	
	LDI temp, 0B0000_0001
	AND temp, are

	LSL temp
	LSL temp
	LSL temp

	LSR are
	OR are, temp
	
	OUT aport, are

	RCALL delaymot

	rjmp a_right_2

	endra:

	ret

a_left: a_left_2:
	dec grad
	cpi grad, 0

	breq endla
	
	LDI temp, 0B0000_1000
	AND temp, are

	LSR temp
	LSR temp
	LSR temp

	LSL are
	OR are, temp
	
	OUT aport, are

	RCALL delaymot

	rjmp a_left_2

	endla:

	ret

b_right:
	dec grad
	cpi grad, 0

	breq endrb
	
	LDI temp, 0B0000_0001
	AND temp, bre

	LSL temp
	LSL temp
	LSL temp

	LSR bre
	OR bre, temp
	
	OUT bport, bre

	RCALL delaymot

	rjmp b_right

	endrb:

	ret

b_left:
	dec grad
	cpi grad, 0

	breq endlb
	
	LDI temp, 0B0000_1000
	AND temp, bre

	LSR temp
	LSR temp
	LSR temp

	LSL bre
	OR bre, temp
	
	OUT bport, bre

	RCALL delaymot

	rjmp b_left

	endlb:

	ret

c_right:
	dec grad
	cpi grad, 0

	breq endrc
	
	LDI temp, 0B0000_0001
	AND temp, cre

	LSL temp
	LSL temp
	LSL temp

	LSR cre
	OR cre, temp
	
	OUT cport, cre

	RCALL delaymot

	rjmp c_right

	endrc:

	ret

c_left:
	dec grad
	cpi grad, 0

	breq endlc
	
	LDI temp, 0B0000_1000
	AND temp, cre

	LSR temp
	LSR temp
	LSR temp

	LSL cre
	OR cre, temp
	
	OUT cport, cre

	RCALL delaymot

	rjmp c_left

	endlc:

	ret

delaymot:
	; delaying 7998 cycles:
          ldi  R17, $1F
	WGLOOP0:  ldi  R18, $55
	WGLOOP1:  dec  R18
			  brne WGLOOP1
			  dec  R17
			  brne WGLOOP0
	; ----------------------------- 
	; delaying 2 cycles:
			  nop
			  nop
	; ============================= 
ret

delayrebote:
	; delaying 79998 cycles:
			  ldi  R17, $86
	WGLOOP00:  ldi  R18, $C6
	WGLOOP10:  dec  R18
			  brne WGLOOP10
			  dec  R17
			  brne WGLOOP00
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



