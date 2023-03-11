#include "constants.h"
void configPins(void)
{
    
    CM1CON0 = LO;       // turn off all comparators
    CM2CON0 = LO;
    CM1CON1 = LO;
    CM2CON1 = LO;
    
    
     //****CE1******
    // make RA4 an output CE1
    TRISAbits.TRISA4 = LO;
    
    // do not enable CE1
    LATAbits.LATA4 = HI;
    
    //****CE2******
     // make RA5 an output CE2
    TRISAbits.TRISA5 = LO;
    
    // do not enable CE2
    LATAbits.LATA5 = HI;
    
    //****RST******
    //make RB5 an output RST
    TRISBbits.TRISB5 = LO;
    
    // turn off analog functionality for RB5
    ANSELBbits.ANSB5 = LO;
    
    // do not enable a reset
    LATBbits.LATB5 = HI;
    
    //****D/C******
    //make RC6 an output D/C
    TRISCbits.TRISC6 = LO;
    // turn off analog functionality for RC6
    ANSELCbits.ANSC6 = LO;
    // clear to send command
    LATCbits.LATC6 = LO;
    
    //****SDO******
    // make RC7 an output SDO  
    TRISCbits.TRISC7 = LO;
    // turn off analog functionality for RC7
    ANSELCbits.ANSC7 = LO;
    // set high
    PORTCbits.RC7= HI;
    
    
    //****SDI******
    //make RC4 an output SDI, as SDI is not needed in this application
    TRISBbits.TRISB4 = LO;
   // turn off analog functionality for RB4
    ANSELBbits.ANSB4 = LO;
    // set high
    LATBbits.LATB4 = HI;
    
    
    //****SCK******
    //make RB6 an output SCK
    TRISBbits.TRISB6 = LO;
    // set high
    PORTBbits.RB6 = HI;
    
    //*****DIAGNOSTIC LED RED********************
    TRISCbits.TRISC4 = LO;
}
