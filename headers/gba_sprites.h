/**
 * Contains all the relevant defines, variables and struct for 
 * sprite control.
 *
 * @date	11/12/09
 * @author	Dovoto
 * @author  GBAJunkie
 * @author  Wouter van Teijlingen
 * @email	wouter@0xff.nl
 */
 
#ifndef SQUARES_H
#define SQUARES_H

//define the screen width and height values to be used
#define SCREEN_WIDTH	240
#define SCREEN_HEIGHT   160

//colour convertion (converts a RGB colour to a 15-bit BGR value used by the GBA)
#define RGB16_BGR(r, g, b) ((r)+(g<<5)+(b<<10))

//attribute0 #defines
#define ROTATION_FLAG		0x100
#define SIZE_DOUBLE		0x200
#define MODE_NORMAL		0x0
#define MODE_TRANSPARENT	0x400
#define MODE_WINDOWED		0x800
#define MOSAIC			0x1000
#define COLOR_16		0x0000
#define COLOR_256		0x2000
#define SQUARE			0x0
#define TALL			0x4000
#define WIDE			0x8000

//attribute1 #defines
#define ROTDATA(n)		((n)<<9)
#define HORIZONTAL_FLIP		0x1000
#define VERTICAL_FLIP		0x2000
#define SIZE_8			0x0
#define SIZE_16			0x4000
#define SIZE_32			0x8000
#define SIZE_64			0xC000

//atrribute2 #defines
#define PRIORITY(n)	        ((n)<<10)
#define PALETTE(n)		((n)<<12)

/**
 * sprite structure definitions
 */
typedef struct TagOAMEntry
{
	u16 attribute0;
	u16 attribute1;
	u16 attribute2;
	u16 attribute3;
}OAMEntry, *pOAMEntry;

/**
 * sprite rotation information (don't worry about this for now)
 */
typedef struct TagRotData
{
	u16 filler1[3];
	u16 pa;
	u16 filler2[3];
	u16 pb;
	u16 filler3[3];
	u16 pc;
	u16 filler4[3];
	u16 pd;
}RotData, *pRotData;

/**
 * animated sprite structure required
 */
typedef struct
{
	u16 x;			//x and y position on screen
	u16 y;
	//u16 sprite_frame[3];     //animation frame storage
	//int active_frame;        //which frame is active
	u16 OAMSpriteNum;       //which sprite referring to
	u16 sprite_index;
} Sprite;

//create an OAM variable and make it point to the address of OAM
extern u16* OAM;

//create the array of sprites (128 is the maximum)
extern OAMEntry sprites[128];

extern void copy_oam();
extern void initialize_sprites();
extern void update_sprite( Sprite s, u16 tiles );

#endif



