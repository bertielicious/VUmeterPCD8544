#include "constants.h"
void select0To47(int16_t row, pageToRow *ptr)
{
   switch(row) 
   {
       /****PAGE 0********/
       case 47:
           ptr -> page = 0;
           ptr -> byte = 0x01;
           break;
        case 46:
           ptr -> page = 0;
           ptr -> byte = 0x02;
           break;        
       case 45:
           ptr -> page = 0;
           ptr -> byte = 0x04;
           break;
       case 44:
           ptr -> page = 0;
           ptr -> byte = 0x08;
           break;
       case 43:
           ptr -> page = 0;
           ptr -> byte = 0x10;
           break;
       case 42:
           ptr -> page = 0;
           ptr -> byte = 0x20;
           break;        
       case 41:
           ptr -> page = 0;
           ptr -> byte = 0x40;
           break;
        case 40:
           ptr -> page = 0;
           ptr -> byte = 0x80;
           break;
          
           
       /****PAGE 1********/
       case 39:
           ptr -> page = 1;
           ptr -> byte = 0x01;
           break;
        case 38:
           ptr -> page = 1;
           ptr -> byte = 0x02;
           break;        
       case 37:
           ptr -> page = 1;
           ptr -> byte = 0x04;
           break;
       case 36:
           ptr -> page = 1;
           ptr -> byte = 0x08;
           break;
       case 35:
           ptr -> page = 1;
           ptr -> byte = 0x10;
           break;
       case 34:
           ptr -> page = 1;
           ptr -> byte = 0x20;
           break;        
      case 33:
           ptr -> page = 1;
           ptr -> byte = 0x40;
           break;
        case 32:
           ptr -> page = 1;
           ptr -> byte = 0x80;
           break;
        
         /****PAGE 2********/
        case 31:
           ptr -> page = 2;
           ptr -> byte = 0x01;
           break;
        case 30:
           ptr -> page = 2;
           ptr -> byte = 0x02;
           break;        
       case 29:
           ptr -> page = 2;
           ptr -> byte = 0x04;
           break;
       case 28:
           ptr -> page = 2;
           ptr -> byte = 0x08;
           break;
       case 27:
           ptr -> page = 2;
           ptr -> byte = 0x10;
           break;
       case 26:
           ptr -> page = 2;
           ptr -> byte = 0x20;
           break;        
      case 25:
           ptr -> page = 2;
           ptr -> byte = 0x40;
           break;
        case 24:
           ptr -> page = 2;
           ptr -> byte = 0x80;
           break;
           
       /****PAGE 3********/
       case 23:
           ptr -> page = 3;
           ptr -> byte = 0x01;
           break;
        case 22:
           ptr -> page = 3;
           ptr -> byte = 0x02;
           break;        
       case 21:
           ptr -> page = 3;
           ptr -> byte = 0x04;
           break;
       case 20:
           ptr -> page = 3;
           ptr -> byte = 0x08;
           break;
       case 19:
           ptr -> page = 3;
           ptr -> byte = 0x10;
           break;
       case 18:
           ptr -> page = 3;
           ptr -> byte = 0x20;
           break;        
      case 17:
           ptr -> page = 3;
           ptr -> byte = 0x40;
           break;
        case 16:
           ptr -> page = 3;
           ptr -> byte = 0x80;
           break;
          
           
       /****PAGE 4********/
       case 15:
           ptr -> page = 4;
           ptr -> byte = 0x01;
           break;
        case 14:
           ptr -> page = 4;
           ptr -> byte = 0x02;
           break;        
       case 13:
           ptr -> page = 4;
           ptr -> byte = 0x04;
           break;
       case 12:
           ptr -> page = 4;
           ptr -> byte = 0x08;
           break;
       case 11:
           ptr -> page = 4;
           ptr -> byte = 0x10;
           break;
       case 10:
           ptr -> page = 4;
           ptr -> byte = 0x20;
           break;        
      case 9:
           ptr -> page = 4;
           ptr -> byte = 0x40;
           break;
        case 8:
           ptr -> page = 4;
           ptr -> byte = 0x80;
           break;
        
         /****PAGE 5********/
        case 7:
           ptr -> page = 5;
           ptr -> byte = 0x01;
           break;
        case 6:
           ptr -> page = 5;
           ptr -> byte = 0x02;
           break;        
       case 5:
           ptr -> page = 5;
           ptr -> byte = 0x04;
           break;
       case 4:
           ptr -> page = 5;
           ptr -> byte = 0x08;
           break;
       case 3:
           ptr -> page = 5;
           ptr -> byte = 0x10;
           break;
      case 2:
           ptr -> page = 5;
           ptr -> byte = 0x20;
           break;        
      case 1:
           ptr -> page = 5;
           ptr -> byte = 0x40;
           break;
       case 0:
           ptr -> page = 5;
           ptr -> byte = 0x80;
           break;
           
       default:
           break;
   }
   
}
