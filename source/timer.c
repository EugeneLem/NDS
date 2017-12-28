#include <nds.h>
#include <stdio.h>
#include "timer.h"

int verticalOffset=0;

void setTimer0(){
	TIMER_CR(0)=TIMER_ENABLE | TIMER_DIV_1024  | TIMER_IRQ_REQ;  //===================CHECK ORDER IS RIGHT
	TIMER_DATA(0)=TIMER_FREQ_1024(4);
	irqSet(IRQ_TIMER0,&slide_ISR);
	irqEnable(IRQ_TIMER0);

}

void slide_ISR(){
	if (verticalOffset<80){
		verticalOffset++;
		REG_BG0VOFS_SUB=4*verticalOffset;
	}
	else if (verticalOffset<160){
		verticalOffset++;
		REG_BG0VOFS_SUB=4*(160-verticalOffset);
	}
	else{
		verticalOffset=1;
		REG_BG0VOFS_SUB=4*verticalOffset;
	}
}
