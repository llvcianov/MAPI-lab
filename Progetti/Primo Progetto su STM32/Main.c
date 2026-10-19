unsigned int* puntatore;  //i registri sono unsigned int, dichiaro un puntatore a registro
int i; //variabile per il for

void main (void) {
  
  // RCC base address = 0x40021000
  // Address offset di AHB enable register = 0x14
  
  puntatore = (unsigned int*) 0x40021014; //(AHBENR offset + RCC base addres), punto all'idirizo AHBENR di RCC
  
  //*puntatore = (1<<21); //abilito la periferica GPIOE
  *puntatore |= (1<<21); //ISTRUZIONE CORRETTA CON LA OR, lascio inalterati gli altri bit
  
  
  
  // GPIOE base address = 0x48001000
  // Address offset di Moder = 0x00
  
  puntatore = (unsigned int*) 0x48001000;  //effettuo conversione di tipo e punto all'indirizzo 0x48001000
  
  //*puntatore = (1<<20);  //assegno al valore puntato da puntatore 00000000000100000000000000000000, 
                           //impostando così la linea PE10 come output digitale
  *puntatore |= (1<<20); //ISTRUZIONE CORRETTA CON LA OR, lascio inalterati gli altri bit
  *puntatore &= ~(1<<21); //ISTRUZIONE CORRETTA CON LA AND, lascio inalterati gli altri bit
  
  
  
  // Address offset di ODR = 0x14
  
  puntatore = (unsigned int*) 0x48001014;  //(ODR offset + GPIOE base address), punto all'indirizzo ODR di GPIOE
  
  while(1){   //con il while sempre verificato faccio accendere e spegnere il led all'infinito
    
    for(i=0;i<100000;i++);  //il for funge da delay
    
    //*puntatore = (1<<10); //alzo il livello della PE10
    *puntatore |= (1<<10); //ISTRUZIONE CORRETTA CON LA OR, lascio inalterati gli altri bit
    
    for(i=0;i<100000;i++);  //il for funge da delay
    
    *puntatore &= ~(1<<10); // abbasso la PE10 e faccio spegnere il led, lasciando inalterato il livello delle altre linee
  }
  
  
  
  
  
  
}