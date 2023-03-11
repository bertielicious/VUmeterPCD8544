#include "constants.h"
void configSPI(void)
{
    SSPCON1bits.WCOL = LO;
    SSPCON1bits.SSPOV = LO;
    //enable SPI by setting the SSPEN bit of SSPCON1 register
    //configures the SDI, SDO, SCK and SS pins as serial
    //port pins
    SSPCON1bits.SSPEN = HI;
    
    //select clock polarity select bit
    //idle state for clock is a low level
    SSPCON1bits.CKP = LO;
    
    //select Synchronous Serial Port Mode Select bits
    //0000 = SPI Master mode, clock = FOSC/4 = 4MHz
    SSPCON1bits.SSP1M0 = LO;
    SSPCON1bits.SSP1M1 = LO;
    SSPCON1bits.SSP1M2 = LO;
    SSPCON1bits.SSP1M3 = LO;
    
    //select SPI Clock Edge Select bit (SPI mode only)
    //Transmit occurs on transition from Idle to active clock state
    SSPSTATbits.CKE = HI;
    
    //select SPI Data Input Sample bit
    //Input data sampled at end of data output time
    SSPSTATbits.SMP = HI;
    SSP1STATbits.BF = LO;
}
