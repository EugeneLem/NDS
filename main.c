#include <nds.h>
#include <stdio.h>
#include "graphics.h"


int main(void) {
	configureMain();
	configureSub();


	while(1)
        swiWaitForVBlank();	
	return 0;
}
