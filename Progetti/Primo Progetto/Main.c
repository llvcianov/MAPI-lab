
unsigned int* puntatore;  //i registri sono unsigned int, dichiaro un puntatore a registro

void main (void) {
  
  // GPIOE base address = 0x48001000
  // Address offset di Moder = 0x00
  
  puntatore = (unsigned int*) 0x48001000;  //effettuo conversione di tipo e punto all'indirizzo 0x48001000
  
  *puntatore =  (1<<20);  //assegno al valore puntato da puntatore 00000000000100000000000000000000, 
                          //impostando così la linea PE10 come output digitale
  
  // Address offset di ODR = 0x14
  
  puntatore = (unsigned int*) 0x48001014;  //(ODR offset + GPIOE base address), punto all'indirizzo ODR di GPIOE
  
  *puntatore = (1<<10); //alzo il livello della PE10
  
  
  
                          
  
  



}