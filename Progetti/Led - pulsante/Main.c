

unsigned int* punt;
int i;
void main (void){
  
  //ACCENSIONE LED CON USER BUTTON
  //ABILITO LA PERIFERICA GPIOA E GPIOE
  punt = (unsigned int*) 0x40021014;
  *punt |= (1<<17) | (1<<21);
  
  //IMPOSTO PA0 COME INPUT DIGITALE
  punt = (unsigned int*) 0x48000000;
  *punt &= ~(3<<0);
  
  //IMPOSTO TUTTE LE LINEE COME OUTPUT DIGITALI
  punt = (unsigned int*) 0x48001000;
  *punt = 0x55555555;
  
  //CONDIZIONE PULSANTE
  while(1){
    
    //se il pulsante è premuto
    punt = (unsigned int*) 0x48000010;
    
    if((*punt&(1<<0))==(1<<0)){  // se IDR10==1
      punt = (unsigned int*) 0x48001014;
      *punt = 0x0000FFFF;  //alzo le linee 
    
    }else{
        punt = (unsigned int*) 0x48001014;
        *punt = 0x00000000;  //abbasso le linee 
     
    }   
  }
}