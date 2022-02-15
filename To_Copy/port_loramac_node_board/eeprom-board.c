
#include "utilities.h"
#include "eeprom-board.h"

uint8_t EepromMcuWriteBuffer( uint16_t addr, uint8_t *buffer, uint16_t size )
{
    (void)addr;
    (void)buffer;
    (void)size;
    uint8_t status = FAIL;

    return status;
}

uint8_t EepromMcuReadBuffer( uint16_t addr, uint8_t *buffer, uint16_t size )
{
    (void)addr;
    (void)buffer;
    (void)size;

    uint8_t status = FAIL;

    return status;
}

void EepromMcuSetDeviceAddr( uint8_t addr )
{
    (void)addr;
}

uint8_t EepromMcuGetDeviceAddr( void )
{
    return 0;
}
