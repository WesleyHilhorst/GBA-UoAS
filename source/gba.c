/**
 * This file contains functions to control the background image.
 *
 * @date	11/12/09
 * @author	Wouter van Teijlingen
 * @email	wouter@0xff.nl
 */

#include "../headers/gba.h"

u32* OAMmem  		=(u32*)0x7000000;
u16* VideoBuffer 	=(u16*)0x6000000;
u16* OAMData		=(u16*)0x6010000;
u16* BGPaletteMem 	=(u16*)0x5000000;
u16* OBJPaletteMem 	=(u16*)0x5000200;

void wait_for_vsync()
{
	//while((volatile u16)REG_VCOUNT != 160){}
	while((volatile u16)REG_VCOUNT >= 160);
	while((volatile u16)REG_VCOUNT < 160);
}