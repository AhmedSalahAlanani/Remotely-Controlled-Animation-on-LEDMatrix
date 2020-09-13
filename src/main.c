/*
 * main.c
 *
 *  Created on: Sep 2, 2020
 *      Author: Ahmed Salah
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "LEDMRX_interface.h"
#include "IR_NEC_interface.h"

#define	ANIMATION_DELAY	(6)

void Animation_1(void);
void Animation_2(void);
void Animation_3(void);

int main (void)
{
	MRCC_voidInitSysClock ();
	MRCC_voidEnableClock  (RCC_APB2,RCC_APB2_IOPAEN);
	MRCC_voidEnableClock  (RCC_APB2,RCC_APB2_IOPBEN);
	MRCC_voidEnableClock  (RCC_APB2,RCC_APB2_AFIOEN);

	HLEDMRX_voidInit();
	HIR_NEC_voidInit();

	while(1)
	{
		switch( HIR_NEC_u8ReadReceivedFrame() )
		{
			case IR_NEC_NO_BUTTON_PRESSED:
				asm volatile ("NOP");
				break;

			case IR_NEC_BUTTON_0_PRESSED:
				asm volatile ("NOP");
				break;

			case IR_NEC_BUTTON_1_PRESSED:
				Animation_1();
				break;

			case IR_NEC_BUTTON_2_PRESSED:
				Animation_2();
				break;

			case IR_NEC_BUTTON_3_PRESSED:
				Animation_3();
				break;

			case IR_NEC_BUTTON_4_PRESSED:
				asm volatile ("NOP");
				break;

			case IR_NEC_BUTTON_5_PRESSED:
				asm volatile ("NOP");
				break;

			case IR_NEC_BUTTON_6_PRESSED:
				asm volatile ("NOP");
				break;

			case IR_NEC_BUTTON_7_PRESSED:
				asm volatile ("NOP");
				break;

			case IR_NEC_BUTTON_8_PRESSED:
				asm volatile ("NOP");
				break;

			case IR_NEC_BUTTON_9_PRESSED:
				asm volatile ("NOP");
				break;

			case IR_NEC_BUTTON_STAR_PRESSED:
				asm volatile ("NOP");
				break;

			case IR_NEC_BUTTON_WINDOW_PRESSED:
				asm volatile ("NOP");
				break;

			case IR_NEC_BUTTON_UP_PRESSED:
				asm volatile ("NOP");
				break;

			case IR_NEC_BUTTON_DOWN_PRESSED:
				asm volatile ("NOP");
				break;

			case IR_NEC_BUTTON_RIGHT_PRESSED:
				asm volatile ("NOP");
				break;

			case IR_NEC_BUTTON_LEFT_PRESSED:
				asm volatile ("NOP");
				break;

			case IR_NEC_BUTTON_OK_PRESSED:
				asm volatile ("NOP");
				break;
		}

	}

}


void Animation_1(void)
{
	/*	Create Animation_1 frames*/
	static const u8 Animation_1 [][8] = {	{0,108,30 ,108, 0, 0 ,0,0},
											{0,108,30 ,108, 0, 0 ,0,0},
											{0,108,30 ,108, 0, 0 ,0,0},
											{0, 0 , 0 ,126, 0, 0 ,0,0},
											{0, 16,104, 30,40, 80,0,0},
											{0, 0 , 0 ,108,30,108,0,0},
											{0, 0 ,66 , 36,30,36,66,0},
											{0, 0 , 0 ,108,30,108,0,0},
											{0, 0 ,66 , 36,30,36,66,0},
											{0, 0 , 0 ,108,30,108,0,0}	};

	/*	Display Animation_1	*/
	for(u8 i=0; i<(sizeof(Animation_1)/sizeof(Animation_1[1])); i++)
	{
		for(u8 j=0; j<ANIMATION_DELAY; j++)
		{
			HLEDMRX_voidDisplayFrame(Animation_1[i]);
		}
	}
}


void Animation_2(void)
{
	/*	Create Animation_1 frames*/
	static const u8 Animation_2 [][8] = {	{0,108,30,108,0 ,64,0,0},
											{0,108,30,108,0 ,64,0,0},
											{0,108,30,108,0 ,64,0,0},
											{8,100,30,36 ,72,32,0,0},
											{8,100,30,20 ,20,0 ,8,0},
											{8,100,30,20 ,10,0 ,0,4},
											{8,100,30,20 ,10,0 ,0,0},
											{8,100,30,20 ,20,0 ,0,0},
											{0,108,30,108,0 ,0 ,0,0},
											{0,108,30,108,0 ,0 ,0,0},
											{0,108,30,108,0 ,0 ,0,0}	};

	/*	Display Animation_1	*/
	for(u8 i=0; i<(sizeof(Animation_2)/sizeof(Animation_2[1])); i++)
	{
		for(u8 j=0; j<ANIMATION_DELAY; j++)
		{
			HLEDMRX_voidDisplayFrame(Animation_2[i]);
		}
	}
}

void Animation_3(void)
{
	/*	Create Animation_1 frames*/
	static const u8 Animation_3 [][8] = {	{0,108,30,108,0  , 0,0,0},
											{0,108,30,108,0  , 0,0,0},
											{0,108,30, 36,66 , 0,0,0},
											{0, 66,36, 30,100, 8,0,0},
											{0,108,30, 36,66 , 0,0,0},
											{0, 66,36, 30,100, 8,0,0},
											{0,108,30, 36,66,  0,0,0},
											{0, 66,36, 30,100, 8,0,0},
											{0,108,30, 36,66 , 0,0,0},
											{0,108,30,108,0  , 0,0,0},
											{0,108,30,108,0  , 0,0,0},
											{0,108,30,108,0  , 0,0,0}	};

	/*	Display Animation_1	*/
	for(u8 i=0; i<(sizeof(Animation_3)/sizeof(Animation_3[1])); i++)
	{
		for(u8 j=0; j<ANIMATION_DELAY; j++)
		{
			HLEDMRX_voidDisplayFrame(Animation_3[i]);
		}
	}
}
