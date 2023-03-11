#include "constants.h"
void configADC(void)
{
  
 /*   working code but Vref = 3.3V
   TRISCbits.TRISC2 = HI;   // make RC2 pin 14 an input pin
   ANSELCbits.ANSC2 = HI;   // make RC2 an analog pin (rather than a digital pin)
   
    ADCON0bits.CHS = 0b00000110;// AN6 channel selected (RC2 pin 13) 
    
    ADCON1bits.ADCS2 = 1;   //set ADC conversion clock to 4us
    ADCON1bits.ADCS1 = 1;
    ADCON1bits.ADCS0 = 0;
    
    FVRCONbits.FVREN = HI; // enable fixed voltage reference by setting FVREN bit
    FVRCONbits.ADFVR1 = 0;  // set voltage reference to 1.024V
    FVRCONbits.ADFVR0 = 1;
    
    ADCON0bits.ADON = 1;    // turn the ADC on
    
    //PIR1bits.ADIF = 0;      // clear the ADC interrupt flag to allow any future interrupts
    //PIE1bits.ADIE = 1;      // enable the ADC interrupt
    //INTCONbits.GIE = 1;     // enable global interrupts
    ADCON1bits.ADFM = 1;    // logical OR ADRESH<<6 with ADRESL to get 10-bit ACD result
    ADRESH = 0x00;
    ADRESL = 0x00;*/
    
    /*Port configuration*/
   TRISCbits.TRISC2 = HI;   // make RC2 pin 14 an input pin
   ANSELCbits.ANSC2 = HI;   // make RC2 an analog pin (rather than a digital pin)
   
   /*Channel selection for AN6 RC2 pin14 0b00110*/
   ADCON0bits.CHS4 = LO;
   ADCON0bits.CHS3 = LO;
   ADCON0bits.CHS2 = HI;
   ADCON0bits.CHS1 = HI;
   ADCON0bits.CHS0 = LO;
   
   ADCON1bits.ADPREF1 = HI;
   ADCON1bits.ADPREF0 = HI;
   
   /*FIXED VOLTAGE REFERENCE CONTROL REGISTER*/  
   FVRCONbits.FVREN = HI; // enable fixed voltage reference by setting FVREN bit
   FVRCONbits.ADFVR1 = LO;  //ADC Fixed Voltage Reference Peripheral output is 1x (1.024V)
   FVRCONbits.ADFVR0 = HI;
   
   /*ADC conversion clock source = Fosc/16*/
  // ADCON1bits.ADCS2 = HI;
  // ADCON1bits.ADCS1 = HI;
  // ADCON1bits.ADCS0 = LO;
   ADCON1bits.ADCS2 = HI;
   ADCON1bits.ADCS1 = LO;
   ADCON1bits.ADCS0 = HI;
   
   /*RESULT FORMATTING*/                                      // byte2                          byte1
   ADCON1bits.ADFM = HI; // 10 bit ADC result is right justified MSB|bit9  |bit7|bit6|bit5|bit4|bit3|bit2|bit1|bit0    
   
   /*Enable the ADC module*/
   ADCON0bits.ADON = HI;
   
   /*****CLEAR THE ADC RESULT REGISTER PAIR*****/
    ADRESH = 0x00;
    ADRESL = 0x00;
}
