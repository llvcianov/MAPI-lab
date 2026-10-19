unsigned int* punt;
int i;
int cont;


void main (void){
  
  //CONTATORE
  //ABILITO LA PERIFERICA GPIOA E GPIOE
  punt = (unsigned int*) 0x40021014;
  *punt |= (1<<17) | (1<<21);
  
  //IMPOSTO PA0 COME INPUT DIGITALE
  punt = (unsigned int*) 0x48000000;
  *punt &= ~(3<<0);
  
  //IMPOSTO TUTTE LE LINEE COME OUTPUT DIGITALI
  punt = (unsigned int*) 0x48001000;
  *punt = 0x55555555;
  
  //CONDIZIONE CONTEGGIO
  cont=0;
  while(1){
    
    punt = (unsigned int*) 0x48000010; //PUNTO ALLL'IDR
    
    if((*punt&(1<<0))==(1<<0)){  //SE IL PULSANTE VIENE PREMUTO
      
      while((*punt&(1<<0))==(1<<0));  //FINCHE' LA CONDIZIONE E' RISPETTATA (PULSANTE PREMUTO), RIMANGO NEL CICLO WHILE E NON FACCIO NIENTE
      cont=cont+1; //APPENA LA CONDIZIONE NON E' PIU' RISPETTATA, ESCO DAL WHILE E INCREMENTO CONT DI 1
      
      //ACCENDO I LED SFRUTTANDO IL CONTATORE
      if(cont==9){
        cont=0;
        punt = (unsigned int*) 0x48001014; //PUNTO ALL'ODR
        *punt = 0x00000000;
      }
      punt = (unsigned int*) 0x48001014; //PUNTO ALL'ODR
      *punt |= (1<<(cont+7)); // FACCIO ALZARE LE LINEE DEI LED ALL'AUMENTO DI CONT, IL +7 E' PERCHE' NELL'ODR LE LINEE DEI LED VANNO DA PE8 A PE15.
       
      
    }
    
  }
  
}
