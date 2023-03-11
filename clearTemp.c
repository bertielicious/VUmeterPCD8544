void clearTemp(void)
{

#include "constants.h" 
#include "writeCommand.h"
#include "writeData.h"
#include "main.h"
#include "setAddress.h"
uint8_t page, col;
uint8_t backGrnd[0][0];

    {
       
        for(col = 0; col < 84; col++)
        {
         writeCommand(0x20); //horizontal addressing
         for (page = 0; page < 6; page++)
            backGrnd[page][col] = 0;
        }
    }

}
