#include "constants.h"
#include "writeCommand.h"
void setAddress(uint8_t col, uint8_t page)
{
    writeCommand(0x22);         // vertical addressing mode
    writeCommand(0x40|page);    // set page address to value (0 - 5)
   
    writeCommand(0x20);         // horizontal addressing mode
    writeCommand(0x80|col);     // set column address to value (0 - 83)    
}
