#include "stm32f30x.h"
#include <stdio.h>

#define Q 3.0/4096

unsigned int i;
unsigned int codice;
float tensione;

void main(void)
{
  //ABILITO PERIFERICHE
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN | RCC_AHBENR_ADC12EN;  
  
  //PA0 - MODALITA' ANALOGICA
  SET_BIT(GPIOA->MODER, GPIO_MODER_MODER0);
  
  //ABILITO REGOLATORE DI TENSIONE
  CLEAR_BIT(ADC1->CR,ADC_CR_ADVREGEN_1);
  SET_BIT(ADC1->CR, ADC_CR_ADVREGEN_0);
  for (i=0;i<8000;i++);                 
  
  //IMPOSTO IL CLOCK DI SISTEMA  
  SET_BIT(ADC1_2->CCR, ADC12_CCR_CKMODE_0);
  
  //AVVIO LA CALIBRAZIONE
  SET_BIT(ADC1->CR, ADC_CR_ADCAL);
  while ((ADC1->CR & ADC_CR_ADCAL)!=0); 
 
  //ABILITO L'ADC  
  SET_BIT(ADC1->CR, ADC_CR_ADEN); 
  while ((ADC1->ISR & ADC_ISR_ADRD)==0); 
  
  //IMPOSTO SEQUENZA E SAMPLING
  ADC1->SQR1 |= (1<<6);    // ADCIN1
  ADC1->SMPR1 |= (5<<3);   
  
  
  while(1)
  {
    //AVVIO CONVERSIONE
    SET_BIT(ADC1->CR, ADC_CR_ADSTART);
    while ((ADC1->ISR & ADC_ISR_EOC)==0);      
    
    //LEGGO E CONVERTO IL RISULTATO
    codice = ADC1->DR;          
    tensione = codice*Q;   
    printf("codice = %d\t tensione = %f\n",codice,tensione); 
  }
  
}
