/**
 * Contains all the relevant defines for the keypad.
 *
 * @date	11/12/09
 * @author	Nokturn
 * @email	unknown
 */
 
#ifndef KEYPAD_H
#define KEYPAD_H

#define KEY_A 1
#define KEY_B 2
#define KEY_SELECT 4
#define KEY_START 8
#define KEY_RIGHT 16
#define KEY_LEFT 32
#define KEY_UP 64
#define KEY_DOWN 128
#define KEY_R 256
#define KEY_L 512
int* KEYS = (int*)0x04000130;
#define KEYSMAP        *(volatile u16*)0x04000130
#define KEYDOWN(k)  (~KEYSMAP & k)

#endif
