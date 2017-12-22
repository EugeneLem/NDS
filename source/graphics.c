#include <nds.h>
#include <stdio.h>
#include "graphics.h"

u8 tile0[64] = { // ERROR: This must be defined/allocated outside of the main() function, as a global variable.
		         // If you allocate it inside the main(), it will be saved on the stack. The graphical engine does not have access to the stack/heap.
		2,7,7,7,7,7,7,7,
		7,2,7,7,7,7,7,7,
		7,7,2,7,7,7,7,7,
		7,7,7,2,7,7,7,7,
		7,7,7,7,2,7,7,7,
		7,7,7,7,7,2,7,7,
		7,7,7,7,7,7,2,7,
		7,7,7,7,7,7,7,2
};
u8 tile1[64] = { // ERROR: This must be defined/allocated outside of the main() function, as a global variable.
		2,7,7,7,7,7,7,2,
		7,2,7,7,7,7,2,7,
		7,7,2,7,7,2,7,7,
		7,7,7,2,2,7,7,7,
		7,7,7,2,2,7,7,7,
		7,7,2,7,7,2,7,7,
		7,2,7,7,7,7,2,7,
		2,7,7,7,7,7,7,2
};



void configureSub(){


	REG_DISPCNT_SUB = MODE_0_2D | DISPLAY_BG0_ACTIVE;
	VRAM_C_CR = VRAM_ENABLE | VRAM_C_SUB_BG;
	BGCTRL_SUB[0] = BG_32x32 | BG_COLOR_256 | BG_MAP_BASE(1) | BG_TILE_BASE(0);

	BG_PALETTE_SUB[2]=ARGB16(1,0,31,31);
	BG_PALETTE_SUB[7]=ARGB16(1,31,0,0);

	dmaCopy(tile0,&BG_TILE_RAM_SUB(0)[0],64);
	dmaCopy(tile1,&BG_TILE_RAM_SUB(0)[32],64);



	int i;
	for(i=0;i<32*32;i+=2){
		BG_MAP_RAM_SUB(1)[i]=0 ;
		BG_MAP_RAM_SUB(1)[i+1]=1;
	}
}

void configureMain(){


	REG_DISPCNT = MODE_0_2D | DISPLAY_BG0_ACTIVE;
	VRAM_A_CR = VRAM_ENABLE | VRAM_A_MAIN_BG;
	BGCTRL[0] = BG_32x32 | BG_COLOR_256 | BG_MAP_BASE(1) | BG_TILE_BASE(0);



	dmaCopy(tile0,&BG_TILE_RAM(0)[0],64);
	dmaCopy(tile1,&BG_TILE_RAM(0)[32],64);

	BG_PALETTE[1]=ARGB16(1,31,0,0);
	BG_PALETTE[7]=ARGB16(1,0,0,31);

	int i;
	for(i=0;i<32*32;i+=2){
		BG_MAP_RAM(1)[i]=0 ;
		BG_MAP_RAM(1)[i+1]=1;
	}


}
