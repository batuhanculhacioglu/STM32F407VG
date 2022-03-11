#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

int i = 0;

void delay(uint32_t time)
{
  while(time--);
}

void GPIO_Config()
{
   RCC->CR |= 0x00030000; // HSEON AND HSEONRDY ENABLE
   while(!(RCC->CR & 0x00020000)); // HSEON READY FLAG WAÝT
   RCC->CR |= 0x00080000; // CSS ENABLE
   RCC->PLLCFGR |= 0x00400000; // PLSS e HSE SEÇTÝK
   RCC->PLLCFGR |= 0x00000004; // PLL M = 4
   RCC->PLLCFGR |= 0x00005A00; // PLL N = 168
   RCC->PLLCFGR |= 0x00000000; // PLL P = 2
   RCC->CFGR |= 0x00000000; // AHB PRESCALER = 1
   RCC->CFGR |= 0x00008000; // APB2 PRESCALER = 2
   RCC->CFGR |= 0x00001400; // APB1 PRESCALER = 4
   RCC->CIR |= 0x00080000; // HSERDY FLAG CLEAR
   RCC->CIR |= 0x00800000; // CSS FLAG CLEAR

   RCC->AHB1ENR |= 0x00000009; // AHB1 PORTUN A VE D ENABLE

   GPIOD->MODER = 0x55000000; // 12,13,14,15 OUTPUT
   GPIOD->OTYPER = 0x00000000; // PUSS PULL
   GPIOD->OSPEEDR = 0xFF000000; // 100MHZ
   GPIOD->PUPDR = 0x00000000; // NO PULL

}


int main(void)
{

	GPIO_Config();

  while (1)
  {

      if(GPIOA->IDR & 0x00000001)
      {
    	  while(GPIOA->IDR & 0x00000001)
    		  delay(1680000); // 0,1 SN
    	  i++;

      }

      if(i%2==0)
    	  GPIOD->ODR = 0x00000000;
      else
    	  GPIOD->ODR = 0x0000F000;


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
