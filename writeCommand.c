#include "constants.h"
#include "sendSPIbyte.h"
void writeCommand(uint8_t byte)
{
    CE1 = LO;       // chip enable1 is selected (active low))
    DCI = LO;       // byte to be interpretted as a command
    sendSPIbyte(byte);
    CE1 = HI;       // chip enable1 is disabiled
}
