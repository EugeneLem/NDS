#include <nds.h>
#include <stdio.h>
#include "graphics.h"
#include "timer.h"


int main(void) {
	configureMain();
	configureSub();
	setTimer0();


	while(1)
		swiWaitForVBlank();

	return 0;


}
