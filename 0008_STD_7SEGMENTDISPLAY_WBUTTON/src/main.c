#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

int count=0;

GPIO_InitTypeDef GPIO_InitStruckt;


void GPIO_Config()
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

	GPIO_InitStruckt.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStruckt.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruckt.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruckt.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_InitStruckt.GPIO_Speed = GPIO_Speed_100MHz;

	GPIO_Init(GPIOE, &GPIO_InitStruckt);

    GPIO_InitStruckt.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 |
    		GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 |
			GPIO_Pin_5 | GPIO_Pin_6;

    GPIO_InitStruckt.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStruckt.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruckt.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStruckt.GPIO_Speed = GPIO_Speed_100MHz;

    GPIO_Init(GPIOA, &GPIO_InitStruckt);

}

void delay(uint32_t time)
{
	while(time--);
}


int main(void)
{
	GPIO_Config();


  while (1)
  {
	  if(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_0))
	  {
		  while(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_0));
		  delay(1680000);

		  count++;
	  }

	  switch(count)
	  {
	  case 0:
	  {
		  GPIO_SetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 |
		    		GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 |
					GPIO_Pin_6);
		  GPIO_ResetBits(GPIOA, GPIO_Pin_5);
		  break;
	  }

	  case 1:
	  {
		  GPIO_SetBits(GPIOA, GPIO_Pin_1 | GPIO_Pin_2);
		  		  GPIO_ResetBits(GPIOA, GPIO_Pin_0 |
		  				  GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_6);
		  		  break;
	  }

	  case 2:
	  {
		  GPIO_SetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 |
		    		GPIO_Pin_3 | GPIO_Pin_4 |
					GPIO_Pin_5);
		  		  GPIO_ResetBits(GPIOA, GPIO_Pin_2 | GPIO_Pin_6);
		  		  break;
	  }

	  case 3:
	  {
		  GPIO_SetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 |
		    		GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_5);
		  		  GPIO_ResetBits(GPIOA, GPIO_Pin_4 | GPIO_Pin_6);
		  		  break;
	  }

	  case 4:
	  {
		  GPIO_SetBits(GPIOA, GPIO_Pin_1 | GPIO_Pin_2 |
					GPIO_Pin_5 | GPIO_Pin_6);
		  		  GPIO_ResetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_3 |
		  				  GPIO_Pin_4 );
		  		  break;
	  }

	  case 5:
	  {
		  GPIO_SetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_2
				  | GPIO_Pin_3 | GPIO_Pin_5 | GPIO_Pin_6);
		  		  GPIO_ResetBits(GPIOA, GPIO_Pin_1 | GPIO_Pin_4);
		  		  break;
	  }

	  case 6:
	  {
		  GPIO_SetBits(GPIOA, GPIO_Pin_2 | GPIO_Pin_3 |
				  GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6);
		  		  GPIO_ResetBits(GPIOA, GPIO_Pin_0 |
		  				  GPIO_Pin_1);
		  		  break;
	  }

	  case 7:
	  {
		  GPIO_SetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 |
		    		GPIO_Pin_2);
		  		  GPIO_ResetBits(GPIOA, GPIO_Pin_3 | GPIO_Pin_4 |
		  				GPIO_Pin_5 | GPIO_Pin_6);
		  		  break;
	  }

	  case 8:
	  {
		  GPIO_SetBits(GPIOA, GPIO_Pin_All);
		  		  break;
	  }

	  case 9:
	  {
		  GPIO_SetBits(GPIOA, GPIO_Pin_0 | GPIO_Pin_1 |
		    		GPIO_Pin_2 | GPIO_Pin_3 |
					GPIO_Pin_5 | GPIO_Pin_6);
		  		  GPIO_ResetBits(GPIOA, GPIO_Pin_4);
		  		  break;
	  }
	  default:
	  {
		  count=0;
		  break;
	  }
	  }


  }
}



void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}


uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
