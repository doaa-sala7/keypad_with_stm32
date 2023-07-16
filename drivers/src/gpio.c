/*
#include "stm32f4xx.h"
#include "gpio.h"

void GPIO_Init (GPIO_TypeDef * GPIOx,char pin,char dir,char enable_pin, char iotype)
{
	//Enable clock to GBIOx
	RCC->AHB1ENR |= (1u<<enable_pin);

	if(dir)
	{
		GPIOx->MODER |= (1u<<(2*pin));
		GPIOx->MODER &=~(1u<<(2*pin+1));

		if(iotype==1)
		{
			//push pull
			GPIOx->OTYPER &=~ (1u<<(pin));
		}
		else
		{
			//open drain
			GPIOx->OTYPER |=(1u<<(pin));
		}
	}
	else
	{
		GPIOx->MODER &=~(1u<<(2*pin));
		GPIOx->MODER &=~(1u<<(2*pin+1));

		switch(iotype)
		{
		case 0:
			//no pull up/down
			GPIOx->PUPDR &=~(1u<<(2*pin));
			GPIOx->PUPDR &=~(1u<<(2*pin+1));
			break;
		case 1:
			//pull up
			GPIOx->PUPDR |=(1u<<(2*pin));
			GPIOx->PUPDR &=~(1u<<(2*pin+1));
			break;
		case 2:
			//pull down
			GPIOx->PUPDR &=~(1u<<(2*pin));
			GPIOx->PUPDR |=(1u<<(2*pin+1));
			break;
		case 3:
			//reversed
			GPIOx->PUPDR |=(1u<<(2*pin));
			GPIOx->PUPDR |=(1u<<(2*pin+1));
			break;


		}

	}

}

char GPIO_Write(GPIO_TypeDef * GPIOx,char pin,char state)
{
	if (GPIOx->MODER & (1u<<(2*pin)))
	{
		if(state)
			{
				GPIOx->ODR |=(1u<<pin);
			}
			else
			{
				GPIOx->ODR &=~(1u<<pin);
			}
		return 0;
	}
	else
	{
		return 1;
	}
}


char GPIO_Read(GPIO_TypeDef * GPIOx,char pin)
{
	char x;
	if (!(GPIOx->MODER & (1u<<(2*pin))))
	{

		if(((GPIOx->IDR) &(1u<< pin)))
		{
			x= 1;
		}
		else
		{
			x=0;
		}
	}
	return x;

}
*/


#include "stm32f4xx.h"
#include "gpio.h"

void GPIO_Init (GPIO_TypeDef * GPIOx,char pin,char dir,char enable_pin,char State)
{
	//Enable clock to GBIOx
	RCC->AHB1ENR |= (1u<<enable_pin);

	if(dir)
	{
		GPIOx->MODER |= (1u<<(2*pin));
		GPIOx->MODER &=~(1u<<(2*pin+1));
		//OUTPUT_TYPE(1/PUSH_PULL) 0/OPEN DRAIN)
		switch (State)
		{
		case (0):
				GPIOx->OTYPER  |=(1u<<(pin));
			    break;
		case (1):
				  GPIOx->OTYPER &=~ (1u <<  pin);
				  break;



		}
	}
	else
	{
		GPIOx->MODER &=~(1u<<(2*pin));
		GPIOx->MODER &=~(1u<<(2*pin+1));
		//INPUT TYPE(1/PULL UP) (2/PULLDOWN)
		switch (State) {
		case (0):
				GPIOx->PUPDR &=~ (1u << 2 * pin);
			    GPIOx->PUPDR  |=(1u<<(2*pin+1));
			    break;
		case (1):
		      GPIOx->PUPDR |= (1u << 2 * pin);
			  GPIOx->PUPDR  &=~(1u<<(2*pin+1));
			  break;


					}
	}

}

char GPIO_Write(GPIO_TypeDef * GPIOx,char pin,char state)
{
	if (GPIOx->MODER & (1u<<(2*pin)))
	{
		if(state)
			{
				GPIOx->ODR |=(1u<<pin);
			}
			else
			{
				GPIOx->ODR &=~(1u<<pin);
			}
		return 0;
	}
	else
	{
		return 1;
	}
}

char GPIO_Read(GPIO_TypeDef * GPIOx,char pin){
	char read;

	if (!(GPIOx->MODER & (1u<<(2*pin))))
		{
			 if( GPIOx->IDR & (1u<<pin)){
				 read=1;
			 }

			 else{
				 read=0;
			 }
			 return read;
		}
	else
		{
			return 1;
		}

}

