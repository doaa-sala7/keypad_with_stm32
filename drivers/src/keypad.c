/*
 * keypad.c
 *
 *  Created on: May 20, 2022
 *      Author: Doaa
 */
#include "gpio.h"
#include "stm32f4xx.h"
#include "keypad.h"


const int no_raws = 4;
const int no_cols = 3;
char rows[4]={1,2,3,4}; //fill the array
char cols[3]={5,6,7}; //fill the array

char lookupTable[4][3]={{1,2,3},{4,5,6},{7,8,9},{'*',0,'#'}};// fill the array


char currentvalue;


void KeyPad_INIT(void)
{
	//input pins
	GPIO_Init(GPIOA,rows[0],0,0,1);
	GPIO_Init(GPIOA,rows[1],0,0,1);
	GPIO_Init(GPIOA,rows[2],0,0,1);
	GPIO_Init(GPIOA,rows[3],0,0,1);

	//out put pins
	GPIO_Init(GPIOA,cols[0],1,0,1);
	GPIO_Init(GPIOA,cols[1],1,0,1);
	GPIO_Init(GPIOA,cols[2],1,0,1);

}

void KeyPad_MANAGE(void)
{
	for( int i=0;i<3;i++) //col
	{
		GPIO_Write(GPIOA,cols[i],0);
		for(int k=0;k<4;k++) //raw
		{
			if(GPIO_Read(GPIOA,rows[k])==0)
			{

				//flag=1;

				while(GPIO_Read(GPIOA,rows[k])){}
				currentvalue=lookupTable[k][i];
				KeypadCallouts_KeyPressNotificaton();
			}
			//if(flag) break;

		}
		GPIO_Write(GPIOA,cols[i],1);

	}

}

char KeyPad_GET_VALUE(void)
{
	return currentvalue;
}

void KeypadCallouts_KeyPressNotificaton(void)
{
	int PressedKey=KeyPad_GET_VALUE();

	switch(PressedKey)
	{

	case 0:
		GPIO_Write(GPIOB,0,0);
		GPIO_Write(GPIOB,1,0);
		GPIO_Write(GPIOB,2,0);
		GPIO_Write(GPIOB,3,0);
		break;
	case 1:
		GPIO_Write(GPIOB,0,1);
		GPIO_Write(GPIOB,1,0);
		GPIO_Write(GPIOB,2,0);
		GPIO_Write(GPIOB,3,0);
		break;
	case 2:
		GPIO_Write(GPIOB,0,0);
		GPIO_Write(GPIOB,1,1);
		GPIO_Write(GPIOB,2,0);
		GPIO_Write(GPIOB,3,0);
		break;
	case 3:
		GPIO_Write(GPIOB,0,1);
		GPIO_Write(GPIOB,1,1);
		GPIO_Write(GPIOB,2,0);
		GPIO_Write(GPIOB,3,0);
		break;
	case 4:
		GPIO_Write(GPIOB,0,0);
		GPIO_Write(GPIOB,1,0);
		GPIO_Write(GPIOB,2,1);
		GPIO_Write(GPIOB,3,0);
		break;
	case 5:
		GPIO_Write(GPIOB,0,1);
		GPIO_Write(GPIOB,1,0);
		GPIO_Write(GPIOB,2,1);
		GPIO_Write(GPIOB,3,0);
		break;
	case 6:
		GPIO_Write(GPIOB,0,0);
		GPIO_Write(GPIOB,1,1);
		GPIO_Write(GPIOB,2,1);
		GPIO_Write(GPIOB,3,0);
		break;
	case 7:
		GPIO_Write(GPIOB,0,1);
		GPIO_Write(GPIOB,1,1);
		GPIO_Write(GPIOB,2,1);
		GPIO_Write(GPIOB,3,0);
		break;
	case 8:
		GPIO_Write(GPIOB,0,0);
		GPIO_Write(GPIOB,1,0);
		GPIO_Write(GPIOB,2,0);
		GPIO_Write(GPIOB,3,1);
		break;
	case 9:
		GPIO_Write(GPIOB,0,1);
		GPIO_Write(GPIOB,1,0);
		GPIO_Write(GPIOB,2,0);
		GPIO_Write(GPIOB,3,1);
		break;


	}


	// set seven segment
}



/*
switch(i)
{
case 0:
	GPIO_Write(GPIOA,cols[i],0);////have a problem
	GPIO_Write(GPIOA,cols[i+1],1);
	GPIO_Write(GPIOA,cols[i+2],1);
	break;
case 1:
	GPIO_Write(GPIOA,cols[i],1);////have a problem
	GPIO_Write(GPIOA,cols[i+1],0);
	GPIO_Write(GPIOA,cols[i+2],1);
	break;
case 2:
	GPIO_Write(GPIOA,cols[i],1);////have a problem
	GPIO_Write(GPIOA,cols[i+1],1);
	GPIO_Write(GPIOA,cols[i+2],0);
	break;
}*/
