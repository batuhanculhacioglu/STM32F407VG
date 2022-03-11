#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

void delay(uint32_t time)
{
 while(time--);
}

void GPIO_Config()

{

	RCC->CR |= 0x00030000;
	while(!(RCC->CR & 0x00020000));
	RCC->CR |= 0x00080000;
	RCC->PLLCFGR |= 0x00400000;
	RCC->PLLCFGR |= 0x00000004;
	RCC->PLLCFGR |= 0x00005A00;
	RCC->PLLCFGR |= 0x00000000;
	RCC->CFGR |= 0x00000000;
	RCC->CFGR |= 0x00008000;
	RCC->CFGR |= 0x00001400;
	RCC->CIR |= 0x00080000;
	RCC->CIR |= 0x00800000;

	RCC->AHB1ENR |= 0x00000008;

	GPIOD->MODER = 0x55000000;
	GPIOD->OTYPER = 0x00000000;
	GPIOD->OSPEEDR = 0xFF000000;
	GPIOD->PUPDR = 0x00000000;

}

int main(void)
{
  GPIO_Config();

  while (1)
  {
	  GPIOD->ODR = 0x00001000;
	  delay(16800000);

	  GPIOD->ODR = 0x00002000;
	  delay(16800000);

	  GPIOD->ODR = 0x00004000;
	  delay(16800000);

	  GPIOD->ODR = 0x00008000;
	  delay(16800000);



  }
}


void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
