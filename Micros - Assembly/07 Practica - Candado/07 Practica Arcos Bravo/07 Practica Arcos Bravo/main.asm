;
; 07 Practica Arcos Bravo.asm
;
; Created: 16/10/2021 12:01:37 p. m.
; Author : David Gamaliel Arcos
;

;*******************
.include "m16def.inc"     
;*******************
;Registros (aqui pueden definirse)
.def r_1=r22
.def r_2=r23
.def r_cont=r24
.def rt=r25
.def rt2=r18
.def alarm_on=r19
;Palabras claves (aqu? pueden definirse)
;.equ LCD_DAT=DDRC
.equ MAT_DAT=DDRA
.equ MAT_PORT=PORTA
.equ MAT_PIN=PINA
.equ OUT_DAT=DDRD
.equ OUT_PORT=PORTD
.equ OUT_PIN=PIND
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

; MATRIZ

ldi R16, 0x0F
out MAT_DAT, R16
ldi R16, 0xFF
out MAT_PORT, R16

ldi r16, 0xFF
out OUT_DAT, r16
ldi r16, 0b1010_1000
out OUT_PORT, r16

rcall clrRegs

main:
	rcall cosas
	rcall teclado
	out OUT_PORT, rt
rjmp main

teclado:

	ldi R16, 0b1111_1110
	out MAT_PORT, R16
	nop 
	nop

	sbis MAT_PIN, 4
	rcall AST
	sbis MAT_PIN, 5
	rcall C7
	sbis MAT_PIN, 6
	rcall C4
	sbis MAT_PIN, 7
	rcall C1

	ldi R16, 0b1111_1101
	out MAT_PORT, R16
	nop 
	nop

	sbis MAT_PIN, 4
	rcall C0
	sbis MAT_PIN, 5
	rcall C8
	sbis MAT_PIN, 6
	rcall C5
	sbis MAT_PIN, 7
	rcall C2

	ldi R16, 0b1111_1011
	out MAT_PORT, R16
	nop 
	nop

	sbis MAT_PIN, 4
	rcall GATO
	sbis MAT_PIN, 5
	rcall C9
	sbis MAT_PIN, 6	
	rcall C6
	sbis MAT_PIN, 7
	rcall C3

	ldi R16, 0b1111_0111
	out MAT_PORT, R16
	nop 
	nop

	sbis MAT_PIN, 4
	rcall CD
	sbis MAT_PIN, 5
	rcall CC
	sbis MAT_PIN, 6
	rcall CB
	sbis MAT_PIN, 7
	rcall CA

ret

checkAlarmLabel:
	rcall checkAlarm
rjmp retcheckAlarmLabel

checkLabel:
	rcall check
rjmp retcheckLabel

r_cont_5_Label:
	rcall clrRegs
rjmp ret_r_cont_5_Label

cosas:
	
	cpi alarm_on, 0xFF
	breq checkAlarmLabel
	retcheckAlarmLabel:

	cpi r_cont, 4
	breq checkLabel
	retcheckLabel:

	cpi r_cont, 5
	breq r_cont_5_Label
	ret_r_cont_5_Label:

ret

unlock:
	; set unlock led
	ldi rt, 0b1000_0000
ret

movRegs:
	; uno 
	andi r_1, 0b0000_1111
	swap r_1
	; tres
	swap r_2
	; dos
	mov rt2, r_2
	andi rt2, 0b0000_1111
	or r_1, rt2
	andi r_2, 0b1111_0000
ret

block:
	rcall clrRegs
	rcall setAlarm
ret

setAlarm:
	; set alarm pin
	ldi rt, 0b0000_0001
	ldi alarm_on, 0xFF
ret

clrRegs:
	clr rt
	clr rt2
	clr r_1
	clr r_2
	clr r_cont
	clr alarm_on
ret 

LIMPIAR:
	rcall clrRegs
rjmp retLimpiar

checkAlarm:
	clr r_cont
	cpi r_2, 0x23
	breq LIMPIAR
	retLimpiar:
ret

ss:
	rcall setAlarm
	rjmp vuelveCheck

unlockLabel:
	rcall unlock
rjmp retunlockLabel

blockLabel:
	rcall block
rjmp retblockLabel

check:

	ldi alarm_on, 0x00
	; contraseña = 1 5 7 9
	cpi r_1, 0b0001_0101
	brne ss
	cpi r_2, 0b0111_1001
	brne ss
	vuelveCheck:

	cpi alarm_on, 0x00
	breq unlockLabel
	retunlockLabel:

	cpi alarm_on, 0xFF
	breq blockLabel
	retblockLabel:
	
	out OUT_PORT, rt

ret

C0:
	rcall delayRebote
	rcall movRegs
	ori r_2, 0x00
	inc r_cont
	btn4:
		sbis MAT_PIN, 4
		rjmp btn4
	rcall delayRebote
ret

C1:
    rcall delayRebote
	rcall movRegs
	ori r_2, 0x01
	inc r_cont
	btn3:
		sbis MAT_PIN, 7
		rjmp btn3
    rcall delayRebote
ret

C2:
	rcall delayRebote
	rcall movRegs
	ori r_2, 0x02
	inc r_cont
    btn7:
		sbis MAT_PIN, 7
		rjmp btn7
    rcall delayRebote
ret

C3:
	rcall delayRebote
	rcall movRegs
	ori r_2, 0x03
	inc r_cont
    btn11:
		sbis MAT_PIN, 7
		rjmp btn11
    rcall delayRebote
ret

C4:
	rcall delayRebote
	rcall movRegs
	ori r_2, 0x04
	inc r_cont
    btn2:
		sbis MAT_PIN, 6
		rjmp btn2
    rcall delayRebote
	ret

C5:
    rcall delayRebote
	rcall movRegs
	ori r_2, 0x05
	inc r_cont
    btn6:
		sbis MAT_PIN, 6
		rjmp btn6
    rcall delayRebote
	ret

C6:
	rcall delayRebote
	rcall movRegs
	ori r_2, 0x06
	inc r_cont
    btn10:
		sbis MAT_PIN, 6
		rjmp btn10
    rcall delayRebote
	ret

C7:
	rcall delayRebote
	rcall movRegs
	ori r_2, 0x07
	inc r_cont
    btn1:
		sbis MAT_PIN, 5
		rjmp btn1
    rcall delayRebote
	ret

C8:
	rcall delayRebote
	rcall movRegs
	ori r_2, 0x08
	inc r_cont
    btn5:
		sbis MAT_PIN, 5
		rjmp btn5
    rcall delayRebote
ret

C9:
	rcall delayRebote
	call movRegs
	ori r_2, 0x09
	inc r_cont
    btn9:
		sbis MAT_PIN, 5
		rjmp btn9
    rcall delayRebote
	ret

rest:
	call clrRegs
ret

AST:
	rcall delayRebote
	cpi alarm_on, 0
	breq rest
    btn0:
		sbis MAT_PIN, 4
		rjmp btn0
    rcall delayRebote
ret

GATO:
	rcall delayRebote
	cpi alarm_on, 0
	breq rest
    btn8:
		sbis MAT_PIN, 4
		rjmp btn8
    rcall delayRebote
ret

CA:
	rcall delayRebote
	rcall movRegs
	ori r_2, 0x0A
	inc r_cont
    btn15:
		sbis MAT_PIN, 7
		rjmp btn15
    rcall delayRebote
ret

CB:
	rcall delayRebote
	rcall movRegs
	ori r_2, 0x0B
	inc r_cont
    btn14:
		sbis MAT_PIN, 6
		rjmp btn14
    rcall delayRebote
	ret

CC:
	rcall delayRebote
	rcall movRegs
	ori r_2, 0x0C
	inc r_cont
    btn13:
		sbis MAT_PIN, 5
		rjmp btn13
    rcall delayRebote
	ret

CD:
	rcall delayRebote
	rcall movRegs
	ori r_2, 0x0D
	inc r_cont
    btn12:
		sbis MAT_PIN, 4
		rjmp btn12
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
