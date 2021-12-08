;
; Examen 2 Arcos Bravo.asm
;
; Created: 19/10/2021 12:42:40 p. m.
; Author : David Gamaliel Arcos
;

;*******************
.include "m16def.inc"     
;*******************
;Registros (aqui pueden definirse)
.def r_azul=r22
.def r_verde=r23
.def r_rojo=r24
.def aux=r19
.def signo=r18
.def r_cont=r25
;Palabras claves (aqu? pueden definirse)
;.equ LCD_DAT=DDRC
.equ DDR_VERDE=DDRD
.equ DDR_ROJO=DDRB
.equ DDR_AZUL=DDRC
.equ PORT_VERDE=PORTD
.equ PORT_ROJO=PORTB
.equ PORT_AZUL=PORTC
.equ DDR_TECLADO=DDRA
.equ PORT_TECLADO=PORTA
.equ PIN_TECLADO=PINA
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

ldi r16, 0xFF	
out DDR_VERDE, R16
out DDR_ROJO, R16
out DDR_AZUL, R16

ldi r16, 0x00	
out PORT_VERDE, R16
out PORT_ROJO, R16
out PORT_AZUL, R16

ldi r16, 0b0000_1110
out DDR_TECLADO, r16
ldi r16, 0xFF
out PORT_TECLADO, r16

rcall clrRegs

main:
	rcall checkReset
	rcall teclado
	rcall checkSum

	out PORT_VERDE, r_verde
	out PORT_ROJO,  r_rojo
	out PORT_AZUL,  r_azul

rjmp main

checkSum:
	cpi r_cont, 0x05
	breq suma_o_resta
	ret_suma_o_resta:
ret

sumar:
	mov aux, r1
	sum_verde:
		inc r0
		dec aux
		cpi aux, 0
	brne sum_verde
rjmp ret_sumar

restar:
	mov aux, r1
	res_verde:
		dec r0
		dec aux
		cpi aux, 0
	brne res_verde
rjmp ret_restar

multi_verde:
	add r1, r10
	dec aux
	cpi aux, 0
	brne multi_verde
rjmp ret_multi_verde

own_multiply_azul:
	add r0, r10
	dec aux
	cpi aux, 0
	brne own_multiply_azul
rjmp ret_multi_azul

suma_o_resta:
	ldi aux, 0x0A
	mov r10, aux
	ldi aux, 0x01
	mov r2, aux
	clr r0
	clr r1

	// unidad azul
	mov aux, r_azul
	swap aux
	andi aux, 0x0F
	add r0,aux
	// decena azul
	mov aux, r_azul
	andi aux, 0x0F
	cpi aux, 0
	brne own_multiply_azul
	ret_multi_azul:

	// unidad verde
	mov aux, r_verde
	swap aux
	andi aux, 0x0F
	add r1,aux
	// decena verde
	mov aux, r_verde
	andi aux, 0x0F
	cpi aux, 0
	brne multi_verde
	ret_multi_verde:

	mov aux, r1
	cpi aux, 0
	breq salta_op

	// SIGNO MAS   -    0xFF
	cpi signo, 0xFF
	breq sumar
	ret_sumar:
	// SIGNO MENOS -    0x00
	cpi signo, 0x00
	breq restar
	ret_restar:

	salta_op:

	// pasar de binario a dec
	mov aux, r0
	clr r1
	
	cpi aux, 10
	brlo menor_que_10 
	suma_10:
	inc r1
	sub aux,r10
	cpi aux, 10
	brsh suma_10 
	menor_que_10:
	swap r1
	cpi aux, 0
	breq es_cero
	no_cero:
	inc r1
	dec aux
	cpi aux, 0
	brne no_cero
	es_cero:
	swap r1
	mov r_rojo, r1

rjmp ret_suma_o_resta

clrRegs:
	clr r_azul
	clr r_verde
	clr r_rojo
	clr r_cont
	clr aux
	clr signo
ret

checkReset:
	sbis PIN_TECLADO, 0
	rcall clrRegs
ret

teclado:

	ldi R16, 0b1111_1101
	out PORT_TECLADO, R16
	nop 
	nop

	sbis PIN_TECLADO, 4
	rcall C1
	sbis PIN_TECLADO, 5
	rcall C4
	sbis PIN_TECLADO, 6
	rcall C7
	sbis PIN_TECLADO, 7
	rcall AST

	ldi R16, 0b1111_1011
	out PORT_TECLADO, R16
	nop 
	nop

	sbis PIN_TECLADO, 4
	rcall C2
	sbis PIN_TECLADO, 5
	rcall C5
	sbis PIN_TECLADO, 6
	rcall C8
	sbis PIN_TECLADO, 7
	rcall C0

	ldi R16, 0b1111_0111
	out PORT_TECLADO, R16
	nop 
	nop

	sbis PIN_TECLADO, 4
	rcall C3
	sbis PIN_TECLADO, 5
	rcall C6
	sbis PIN_TECLADO, 6
	rcall C9
	sbis PIN_TECLADO, 7
	rcall GATO

ret

incc: 
	inc r_cont
rjmp ret_incc

inc_cont:
	cpi r_cont, 0x05
	brne incc
	ret_incc:
ret

aum_3:
	or r_verde, aux
	rcall inc_cont
rjmp aum_3_ret

aum_4:
	swap r_verde
	or r_verde, aux
	swap r_verde
	rcall inc_cont
rjmp aum_4_ret

aum_1:
	or r_azul, aux
	rcall inc_cont
rjmp aum_1_ret

aum_2:
	swap r_azul
	or r_azul, aux
	swap r_azul
	rcall inc_cont
rjmp aum_2_ret

checkValue:
	
	cpi r_cont, 0x04
	breq aum_4
	aum_4_ret:

	cpi r_cont, 0x03
	breq aum_3
	aum_3_ret:

	cpi r_cont, 0x01
	breq aum_2
	aum_2_ret:

	cpi r_cont, 0x00
	breq aum_1
	aum_1_ret:

ret

signoo:
	mov signo, aux
	rcall inc_cont
rjmp signoo_ret

checkSign:
	cpi r_cont, 0x02
	breq signoo
	signoo_ret:
ret

C1:
	rcall retardoBoton
	
	ldi aux, 0x01
	rcall checkValue

	btn1:
		sbis PIN_TECLADO, 4
		rjmp btn1
	rcall retardoBoton
RET

C4:
	rcall retardoBoton

	ldi aux, 0x04
	rcall checkValue

	btn4:
		sbis PIN_TECLADO, 5
		rjmp btn4
	rcall retardoBoton
RET

C7:
	rcall retardoBoton

	ldi aux, 0x07
	rcall checkValue

	btn7:
		sbis PIN_TECLADO, 6
		rjmp btn7
	rcall retardoBoton
RET

AST:
	rcall retardoBoton
	// SIGNO MAS
	ldi aux, 0xFF
	rcall checkSign
	btnAST:
		sbis PIN_TECLADO, 7
		rjmp btnAST
	rcall retardoBoton
RET

C2:
	rcall retardoBoton
	
	ldi aux, 0x02
	rcall checkValue

	btn2:
		sbis PIN_TECLADO, 4
		rjmp btn2
	rcall retardoBoton
RET

C5:
	rcall retardoBoton

	ldi aux, 0x05
	rcall checkValue

	btn5:
		sbis PIN_TECLADO, 5
		rjmp btn5
	rcall retardoBoton
RET

C8:
	rcall retardoBoton

	ldi aux, 0x08
	rcall checkValue

	btn8:
		sbis PIN_TECLADO, 6
		rjmp btn8
	rcall retardoBoton
RET

C0:
	rcall retardoBoton

	ldi aux, 0x00
	rcall checkValue

	btn0:
		sbis PIN_TECLADO, 7
		rjmp btn0
	rcall retardoBoton
RET

C3:
	rcall retardoBoton
	
	ldi aux, 0x03
	rcall checkValue

	btn3:
		sbis PIN_TECLADO, 4
		rjmp btn3
	rcall retardoBoton
RET

C6:
	rcall retardoBoton

	ldi aux, 0x06
	rcall checkValue

	btn6:
		sbis PIN_TECLADO, 5
		rjmp btn6
	rcall retardoBoton
RET

C9:
	rcall retardoBoton

	ldi aux, 0x09
	rcall checkValue

	btn9:
		sbis PIN_TECLADO, 6
		rjmp btn9
	rcall retardoBoton
RET

GATO:
	rcall retardoBoton
	// SIGNO MENOS
	ldi aux, 0x00
	rcall checkSign

	btnGATO:
		sbis PIN_TECLADO, 7
		rjmp btnGATO
	rcall retardoBoton
RET

retardoBoton:
; ============================= 
;    delay loop generator 
;     159999 cycles:
; ----------------------------- 
; delaying 159975 cycles:
          ldi  R20, $E1
WGLOOP0:  ldi  R21, $EC
WGLOOP1:  dec  R21
          brne WGLOOP1
          dec  R20
          brne WGLOOP0
; ----------------------------- 
; delaying 24 cycles:
          ldi  R20, $08
WGLOOP2:  dec  R20
          brne WGLOOP2
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

