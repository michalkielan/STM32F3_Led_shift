/*
 * 		 Project: F3_GPIOLedShift
 * 		 Board: STM32F3 - discovery
 * 		 data: 15.12.2013
 *       Autor: Michał Kielan
 *       notes: Diody biegnące w lewo
 */

#include "main.h"

GPIO_InitTypeDef GPIO_InitStruct;

unsigned int stanGPIOE;

unsigned int LedPortOn = 0xFF00;		//ledy ON w starszej części portu E
unsigned int LedPortOff = 0x0000;		//ledy OFF wszędzie

unsigned int pozLedOn = 0x0100;			// 0000'0001'0000'0000 dioda pozycja 8 -- ON

int main(void)
{
	Clock_Init();		//init clocka
	IO_Init();			// init GPIOE ledów ---> LEDy - HIGH-Active !!!

	while (1) {

		stanGPIOE = GPIO_ReadOutputData(GPIOE);		//pobierz stan PORTu E
		stanGPIOE = stanGPIOE & LedPortOff;				//wyzeruj bity

		GPIO_Write(GPIOE, pozLedOn | stanGPIOE);				//zapisz stan portu
		_delay_ms(10);

										//1000'0000'0000'0000 = 0x8000

			if(pozLedOn < 0x8000)	{		//pozycja diody < niz pozycja diody 8

				pozLedOn = pozLedOn << 1;		 //przesun o 1 w lewo
				_delay_ms(50);
			}

			else	{		//jesli dioda 8 wlaczona, ustaw pozycje 1
				pozLedOn = 0x100;

			}

	}

	return 0;
}

void Clock_Init(void)	{

	uint32_t ii;	//systick timer

	SysTick_Config(72);		//1us if f_clk = 72Mhz

	SystemCoreClockUpdate();
	ii = SystemCoreClock;		//read the system clock
}

void IO_Init(void)	{		//GPIO pin config

RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);		//GPIO Periph clock enable
														//config zegara od portu E

	GPIO_InitStruct.GPIO_Pin = L3 | L4 | L5 | L6 | L7 | L8 | L9 | L10;	//piny
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;				//OUT
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;				//push-pull
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;			//f 50Mhz
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;			//bez podciagania
	GPIO_Init(GPIOE, &GPIO_InitStruct);					//wywołanie GPIOE

}



