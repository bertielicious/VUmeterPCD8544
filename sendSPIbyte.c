#include "constants.h"
void sendSPIbyte(uint8_t byte)
{
    //load the payload into SSPBUF, MSB first
    SSP1BUFbits.SSPBUF = byte;
    
    //Wait until buffer flag is set, indicating receive complete, SSPBUF is full
    while(SSPSTATbits.BF == 0);
}
