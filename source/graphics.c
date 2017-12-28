#include <nds.h>
#include <stdio.h>
#include "graphics.h"
#include "basicTiles.h"






void configureSub(){


	REG_DISPCNT_SUB = MODE_0_2D | DISPLAY_BG0_ACTIVE;
	VRAM_C_CR = VRAM_ENABLE | VRAM_C_SUB_BG;
	BGCTRL_SUB[0] = BG_32x64 | BG_COLOR_256 | BG_MAP_BASE(0) | BG_TILE_BASE(1); //==============check memory


	swiCopy(basicTilesTiles,&BG_TILE_RAM_SUB(1)[0],basicTilesTilesLen);
	swiCopy(basicTilesPal,&BG_PALETTE_SUB[0],basicTilesPalLen/2);
}

void printGameSub( int gameMap[] ){ 	//0:fermer  1:end 2:9 3:8 4:7 5:8 6:6 7:5 8:4 9:3 10:2 11:1 12:0 13:
	int row,column;
	for(row=0;row<16;row++){
		for(column=0;column<16;column++){
			BG_MAP_RAM_SUB(0)[32*row*2+column*2]=basicTilesMap[4*gameMap[16*row+column]] ;
			BG_MAP_RAM_SUB(0)[32*row*2+column*2+1]=basicTilesMap[4*gameMap[16*row+column]+1] ;
			BG_MAP_RAM_SUB(0)[32*(row*2+1)+column*2]=basicTilesMap[4*gameMap[16*row+column]+2] ;
			BG_MAP_RAM_SUB(0)[32*(row*2+1)+column*2+1]=basicTilesMap[4*gameMap[16*row+column]+3] ;

			BG_MAP_RAM_SUB(1)[32*row*2+column*2]=basicTilesMap[4*gameMap[16*row+column+16*16]] ;
			BG_MAP_RAM_SUB(1)[32*row*2+column*2+1]=basicTilesMap[4*gameMap[16*row+column+16*16]+1] ;
			BG_MAP_RAM_SUB(1)[32*(row*2+1)+column*2]=basicTilesMap[4*gameMap[16*row+column+16*16]+2] ;
			BG_MAP_RAM_SUB(1)[32*(row*2+1)+column*2+1]=basicTilesMap[4*gameMap[16*row+column+16*16]+3] ;
		}
	}
}


void configureMain(){
}
