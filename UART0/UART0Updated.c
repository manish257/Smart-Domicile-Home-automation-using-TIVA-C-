#include "TM4C1233H6PM.h"

char readChar(void); // Initialing readChar Operation

int main()
{
  char c;
  
  SYSCTL->RCGCUART |= (1<<1); // Enabling UART 1
  SYSCTL->RCGCGPIO |= (1<<1)|(1<<3)|(1<<4); // Set clock to B D F
  
  GPIOB->AFSEL = (1<<1)|(1<<0);  // Enable PB0 and PB1 ( Tx and Rx Pins)
  GPIOB->PCTL = (1<<0)|(1<<4); 
  GPIOB->DEN = (1<<0)|(1<<1);
  
  UART1->CTL &= ~(1<<0); // UART 1
  UART1->IBRD = 104;  // Setting the serial speed
  UART1->FBRD = 11;
  UART1->LCRH = (0x3<<5);
  UART1->CC = 0x0;
  UART1->CTL = (1<<0)|(1<<8)|(1<<9);
  
  GPIOF->DIR = (1<<1)|(1<<2);  // LED Pins PF1 and PF2 set as OUTPUTS
  GPIOF->DEN = (1<<1)|(1<<2);  // Enabling Digital Functions
  GPIOF->DATA &= ~((1<<1)|(1<<2));  // Set data as LOW
  
  GPIOD->DIR = (1<<1); // PD1 set as OUTPUT
  GPIOD->DEN = (1<<1); // Enabling Digital Functions
  GPIOD->DATA &= ~(1<<1); // Set data as LOW
  
  GPIOE->DIR = (1<<1); // PE1 set as OUTPUT
  GPIOE->DEN = (1<<1); // Enabling Digital Functions
  GPIOE->DATA &= ~(1<<1); // Set data as LOW
  
  
  while(1)
  {
    c = readChar(); // Calling readChar function  
   
    switch(c)  // Switch Case for char "c"  // BULB CONTROL
    {
    case '1': // BLUE
      {
        switch(GPIOD->DATA & 0x02)
        {
        case 0x02:
          GPIOD->DATA = ~(1<<1);
          break;
        case 0x00:
          GPIOD->DATA = (1<<1);
          break;
        }
      }
      break;
      
    case '2': // RED
      {
        switch(GPIOE->DATA & 0x02)
        {
        case 0x02:
          GPIOE->DATA = ~(1<<1);
          break;
        case 0x00:
          GPIOE->DATA = (1<<1);
          break;
        }
      }
      break;
      
    case '3':  // BOTH RED and BLUE
      {
        GPIOD->DATA = ~((1<<1));
        GPIOE->DATA = ~((1<<1));
      }
      break;
      
    default:  // NONE
      {
        GPIOD->DATA = ((1<<1));
        GPIOE->DATA = ((1<<1));
      }
      break;
    }
    
     switch(GPIOD->DATA & 0x02)  // LED CONTROL
     {
     case 0x02:
       switch(GPIOE->DATA & 0x02)
       {
       case 0x02:
         GPIOF->DATA = 0x00; // Both OFF – No LED
         break;
       case 0x00:
         GPIOF->DATA = 0x04;  // Blue ON – BLUE LED
         break;
       }
       break;
       
       case 0x00:
       switch(GPIOE->DATA & 0x02)
       {
       case 0x02:
         GPIOF->DATA = 0x02; // Red ON – RED LED
         break;
       case 0x00:
         GPIOF->DATA = 0x06; // Both ON  - BLUE and RED LED
         break;
       }
       break;
       
       
     }
  }
}

char readChar(void)  // UART READ Operation
{
  char c;
  while((UART1->FR & (1<<4)) !=0);
  c = UART1->DR;
  return c;
}
