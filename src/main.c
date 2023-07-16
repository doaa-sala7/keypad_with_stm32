
#include "stm32f4xx.h"
#include "gpio.h"
#include "keypad.h"


int main(void)
{
	//7 segment
	GPIO_Init(GPIOB,0,1,1,1);
	GPIO_Init(GPIOB,1,1,1,1);
	GPIO_Init(GPIOB,2,1,1,1);
	GPIO_Init(GPIOB,3,1,1,1);

//	GPIO_Init(GPIOB,4,1,1,1);
//	GPIO_Init(GPIOB,5,1,1,1);
//	GPIO_Init(GPIOB,6,1,1,1);



	//keypad
	KeyPad_INIT();

//	GPIO_Init(GPIOB,3,0,1,1);
//	GPIO_Init(GPIOB,5,1,1,1);
//	GPIO_Init(GPIOB,6,1,1,1);
//	GPIO_Init(GPIOB,7,1,1,1);


	while(1)
	{
		KeyPad_MANAGE();

	}


/*
	GPIO_Init(GPIOB,3,0,1,1);
	GPIO_Init(GPIOB,5,1,1,1);
	GPIO_Init(GPIOB,6,1,1,1);
	GPIO_Init(GPIOB,7,1,1,1);

	int j=0;

	while (1){



	  if (GPIO_Read(GPIOB,3) == 1) { //check if the button is not Pressed (default 1 active low  (Pressed:0, Not pressed :1))
		  for (int i = 0; i < 3000; i++) {}// delay for some time

		 if (GPIO_Read(GPIOB,3) == 0) { //check if the button is Pressed
			 j++;
		    switch(j){


		    case 0:

		    	  GPIO_Write(GPIOB,5,1);
		    	  GPIO_Write(GPIOB,6,0);
		    	  GPIO_Write(GPIOB,7,0);


		    	  break;
		     case 1:
		    	  GPIO_Write(GPIOB,5,0);
		    	  GPIO_Write(GPIOB,6,1);
		    	  GPIO_Write(GPIOB,7,0);

		    	  break;
		     case 2:
		    	  GPIO_Write(GPIOB,5,1);
		    	  GPIO_Write(GPIOB,6,1);
		    	  GPIO_Write(GPIOB,7,0);
		    	  break;
		     case 3:
		    	  GPIO_Write(GPIOB,5,0);
		    	  GPIO_Write(GPIOB,6,0);
		    	  GPIO_Write(GPIOB,7,1);
		    	  break;
		     case 4:
		    	  GPIO_Write(GPIOB,5,1);
		    	  GPIO_Write(GPIOB,6,0);
		    	  GPIO_Write(GPIOB,7,1);
		    	   break;

		     case 5:
		    	  GPIO_Write(GPIOB,5,0);
		    	  GPIO_Write(GPIOB,6,1);
		    	  GPIO_Write(GPIOB,7,1);
		    	  break;

		     case 6:
		    	  GPIO_Write(GPIOB,5,1);
		    	  GPIO_Write(GPIOB,6,1);
		    	  GPIO_Write(GPIOB,7,1);
		    	  break;

		     case 7:
		    	  GPIO_Write(GPIOB,5,0);
		    	  GPIO_Write(GPIOB,6,0);
		    	  GPIO_Write(GPIOB,7,0);
		    	  j=0;
		    	  break;
		      }

		}
	  }

		}
		*/
	return 0;
}
/*unsigned char sevenSegHex[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,0x6D, 0x7D, 0x07, 0x7F, 0x6F};
void KeypadCallouts_KeyPressNotificaton(void)
{
	int PressedKey=KeyPad_GET_VALUE();
	for ( unsigned char i = 0; i < 7; i++) {
			GPIO_Write(GPIOB, i, (sevenSegHex[PressedKey] & (1 << i)));
		}
}*/
