
#include "stm32f30x.h"

int cont;

void main(){
  
  cont = 0;
  RCC->AHBENR |= (RCC_AHBENR_GPIOEEN) | (RCC_AHBENR_GPIOAEN); //ABILITO PERIFERICHE
  GPIOE->MODER |= 0x55550000; //PE8-PE15 OUTPUT DIGITALI
  CLEAR_BIT(GPIOA->MODER, GPIO_MODER_MODER0_0); //PA0 INPUT DIGITALE
  CLEAR_BIT(GPIOA->MODER, GPIO_MODER_MODER0_1);
 
  cont = 0;
  while(1){
    
    if((READ_BIT(GPIOA->IDR, GPIO_IDR_0)) == (1<<0)){
      
      while((READ_BIT(GPIOA->IDR, GPIO_IDR_0)) == (1<<0)){};
      
      cont += 1;
      
      if (cont == 9){
        cont = 0;
        GPIOE->ODR = 0x00000000;
       }
      
      GPIOE->ODR |= (1<<(cont+7));
      
    }
  }
  
  
  
}