#include "constants.h"
void configEUSART(void)
{
     /*enable transmitter*/
    
    /*set RB7 and an output TX*/
    TRISBbits.TRISB7 = LO;
    TXSTAbits.TXEN = HI;
    TXSTAbits.SYNC = LO;
    RCSTAbits.SPEN = HI;
    SPBRG = 0x19; //done in configBaud
}
