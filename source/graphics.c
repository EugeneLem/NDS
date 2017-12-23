#include <nds.h>
#include <stdio.h>
#include "graphics.h"
#include "basicTiles.h"






void configureSub(){


	REG_DISPCNT_SUB = MODE_0_2D | DISPLAY_BG0_ACTIVE;
	VRAM_C_CR = VRAM_ENABLE | VRAM_C_SUB_BG;
	BGCTRL_SUB[0] = BG_32x32 | BG_COLOR_256 | BG_MAP_BASE(0) | BG_TILE_BASE(6); //check memory


	swiCopy(basicTilesTiles,&BG_TILE_RAM_SUB(6)[0],64*4/2+32);  //Pourquoi je dois mettre 5 ici??? INDEX TO  PALETTE?
	swiCopy(basicTilesPal,&BG_PALETTE_SUB[0],basicTilesPalLen/2);




	int i,j;
	for(i=0;i<32;i+=2){
		for(j=0;j<32;j+=2){
			BG_MAP_RAM_SUB(0)[32*j+i]=basicTilesMap[0] ;
			BG_MAP_RAM_SUB(0)[32*j+i+1]=basicTilesMap[1];
			BG_MAP_RAM_SUB(0)[32*(j+1)+i]=basicTilesMap[2];
			BG_MAP_RAM_SUB(0)[32*(j+1)+i+1]=basicTilesMap[3];
		}
	}
}

void configureMain(){


}
