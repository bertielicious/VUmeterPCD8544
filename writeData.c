#include "constants.h"
#include "sendSPIbyte.h"
void writeData(uint8_t byte)
{
    CE1 = LO;
    DCI = HI;   // byte to be interpretted as data
    sendSPIbyte(byte);
    CE1 = HI;
}
