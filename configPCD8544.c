#include "constants.h"
#include "writeCommand.h"
void configPCD8544(void)
{
    uint8_t x = 0;  // declare variable x which has a range of 0 - 5
    uint8_t y = 0;  // declare a variable y which has a range of 0 - 83
    
    // Reset  to allow initialisation of the PCD8544
    RST = LO;       
    __delay_ms(1);
    RST = HI;
    // After reset, PD = 1 (power down)
    // To put PCD8544 in power up mode/ active mode, PD = 0, H and V don't care
    // Function set command 0b00100 PD V H
    // where PD = 0, V = 0, H = 0 0b001000000 or 0x20 
    //Normal instruction, set H = 0
    writeCommand(0x20);
    
      
      // set display configuration to normal D = 1, E = 0
      //0b00001100 = 0x0c
      writeCommand(0x0c);
      
      
      
      //set X address of RAM
      // X address - 0x80| x address
      
      //set X address to 0
      writeCommand(0x80|x);
      
      
      //set Y address of RAM
      // Y address = 0x40| y address
      //set Y address to 0
      writeCommand(0x40|y);
      
      //Extended instruction set, H = 1
      writeCommand(0x21); 
      
      
      //Temperature control 0x04| TC1 TC0
      writeCommand (0x04|0x02); //Vled temp coeff 0b10 = 0x02
      //writeCommand (0x04);
      //Bias system
      writeCommand(0x10|0x02);  // Bias system 2
      writeCommand (0x14);
      // set Vop
      writeCommand (0x80|0x1f);
      writeCommand(0xb8);
      writeCommand(0x20);
      writeCommand(0x0c);
}
