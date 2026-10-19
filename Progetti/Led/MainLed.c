
unsigned int* punt;
int i;
void main (void){
 
  //ABILITO LA PERIFERICA GPIOE
  punt = (unsigned int*) 0x40021014;
  *punt |= (1<<21);
  
  //IMPOSTO LE LINEE COME OUTPUT DIGITALI
  punt = (unsigned int*) 0x48001000;
  *punt |= (1<<30) | (1<<28) | (1<<26) | (1<<24) | (1<<22) | (1<<20) | (1<<18) | (1<<16); 
  //oppure mettendo insieme : *punt |= (1<<30) |= (1<<28);
  *punt &= ~(1<<31) & ~(1<<29) & ~(1<<27) & ~(1<<25) & ~(1<<23) & ~(1<<21) & ~(1<<19) & ~(1<<17);
  
  //ALZO E ABBASSO IL LIVELLO DELLE LINEE
  punt = (unsigned int*) 0x48001014;
  while(1){
    
    *punt |= (1<<8) | (1<<9) | (1<<10) | (1<<11) | (1<<12) | (1<<13) | (1<<14) | (1<<15);
     //oppure *punt |= (3<<14) [shifto la coppia 11 (che è 3 in esadecimale) di 14 posizioni]
    for(i=0;i<100000;i++);
    //*punt &= ~(3<<14);
    *punt &= ~(1<<8) & ~(1<<9) & ~(1<<10) & ~(1<<11) & ~(1<<12) & ~(1<<13) & ~(1<<14) & ~(1<<15);
    for(i=0;i<100000;i++);
  
  }

}