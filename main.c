








/*
 * File:   main.c
 * Author: Phil Glazzard
 * MPLABX IDE v6.00
 * XC8 v2.36
 * Optimisations 0
 *
 * Created on 11 December 2022, 18:23
 * 
 * * *                  16f1459
 *                  ---------
 *   +5 Volts    1 |Vdd      | 20 0 Volts
                 2 |RA5   RA0| 19   
 *               3 |RA4   RA1| 18   
      MCLR       4 |RA3      | 17  
                 5 |RC5   RC0| 16 
 DIAGNOSTIC LED  6 |RC4   RC1| 15  
 *               7 |RC3   RC2| 14  ADC AN13 input = 0 - 1.024V
 *               8 |RC6   RB4| 13  
                 9 |RC7   RB5| 12  
 *    TX        10 |RB7   RB6| 11  
 *                  ---------
 * 
 * 
 */


#include <xc.h>
#include "config.h"
#include "constants.h"

#include "configOsc.h"
#include "configPins.h"
#include "configSPI.h"
#include "configEUSART.h"
#include "configBaud.h"
#include "configPCD8544.h"
#include "setAddress.h"
#include "writeCommand.h"
#include "writeData.h"
#include "select0To47.h"
#include "configADC.h"
#include "clearTemp.h"
#include <stdio.h>
uint8_t bgRow, bgCol;

 
 uint8_t backGrnd[6][84] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x30,0xc8,0x88,0xff,0x00,0xff,0x99,0xa9,0x66},
{0,0,0,0,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

void main(void) 
{
    int16_t  angle, opposite, adjacent, radius, ycoord, xcoord;
    
    pageToRow ypixel;
    
    static uint32_t counter = 0;
   
   
    configOsc();
    configPins();
    configSPI();
    configADC();
    configEUSART();
    configBaud();
    printf("angle\n");
    configPCD8544();
    
    
   while(1)
   {
    ADCON0bits.GO_nDONE = HI;       //A/D conversion cycle in progress. Setting this bit starts an A/D conversion cycle.
                                    //This bit is automatically cleared by hardware when the A/D conversion has completed.
        while(ADCON0bits.GO_nDONE == HI)
        {
            ;   // wait for GO_nDONE to clear
        }
        adcVal = (int16_t)(ADRESH<<8 | ADRESL);

        angle = adcVal>>2;//
         //angle = adcVal;
        for(radius = 0; radius <=58; radius++)
        {
            opposite = radius * sineLookUp[angle];     // x = opposite
            adjacent = radius * cosineLookUp[angle];   // y = adjacent
            xcoord = ((128 + opposite)>>8) + 42;
            ycoord = ((128 + adjacent>>8) -9);
           
            select0To47(ycoord, &ypixel);// pass address of pageToRow ypixel to pagaToRow *ptr
            writeCommand(0x22); //horizontal addressing
             if(ycoord >=0)
             {
               // setAddress((int8_t)xcoord,(int8_t)ypixel.page);
               // writeData(ypixel.byte);
                 
                 //copy position of needle into background array
               
                  
                        backGrnd[ypixel.page][xcoord] = (ypixel.byte)|backGrnd[ypixel.page][xcoord];    //write needle position into backGrnd[][]]
             }
        }
        __delay_ms(50);
        //counter++;
         //   if(counter == 100)
           // {
          ///      printf("%d\n", angle);
           //     counter = 0;
           // }
        
    for(bgRow = 0; bgRow <6; bgRow++)
    {
        for(bgCol = 0; bgCol <84; bgCol++)
        {
           writeCommand(0x20); //horizontal addressing
           writeData(backGrnd[bgRow][bgCol]);   // draw background and needle
        }       
     
     }  
       
        
    for(bgRow = 0; bgRow <6; bgRow++)
    {
          
          
        if(bgRow == 1)
        {
            for(bgCol = 0; bgCol <84; bgCol++)
            {
          
                backGrnd[bgRow][bgCol] = 0x80;   // draw graticule
            }  
        }
        else if(bgRow == 2)
        {
            for(bgCol = 0; bgCol <84; bgCol++)
            {
                if(bgCol%8 == 1)
                {
                    backGrnd[bgRow][bgCol] = 0x03;   // draw graticule
                }
                else
                {
                    backGrnd[bgRow][bgCol] = 0x00;
                }
            }    
        }
    
        
        else
        {
            //if((bgRow == 0) | (bgRow == 3) | (bgRow == 4) | (bgRow == 5))
           
            
                for(bgCol = 0; bgCol <84; bgCol++)
            
            {
          
                backGrnd[bgRow][bgCol] = 0;   // clear pages 0 | 3 | 4 | 5
            }  
        }
     
     } 
        RC4 = ~RC4;
      
    }
   }
   
   
