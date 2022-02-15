
#include "board-config.h"

#include "em_common.h"
#include "sl_app_assert.h"
#include "sl_status.h"
#ifdef BLUETOOTH_ID_PRESENT
// From SecureElementInit(...) maybe another more appropriate define could be used here to switch
//#if !defined( SECURE_ELEMENT_PRE_PROVISIONED )
//#if( STATIC_DEVICE_EUI == 0 )
#include "sl_bluetooth.h"
#endif
#include "utilities.h"
#include "gpio.h"
#include "spi.h"
#include "timer.h"
#include "lpm-board.h"
#include "rtc-board.h"

#if defined( SX1261MBXBAS ) || defined( SX1262MBXCAS ) || defined( SX1262MBXDAS )
    #include "sx126x-board.h"
#elif defined( LR1110MB1XXS )
    #include "lr1110-board.h"
#elif defined( SX1272MB2DAS)
    #include "sx1272-board.h"
#elif defined( SX1276MB1LAS ) || defined( SX1276MB1MAS )
    #include "sx1276-board.h"
#endif
#include "board.h"


void BoardCriticalSectionBegin( uint32_t *mask )
{
    *mask = __get_PRIMASK( );
    __disable_irq( );
}

void BoardCriticalSectionEnd( uint32_t *mask )
{
    __set_PRIMASK( *mask );
}

uint32_t BoardGetRandomSeed( void ) {
#ifdef BLUETOOTH_ID_PRESENT
  sl_status_t sc;
  bd_addr address;
  uint8_t address_type;

  // Extract unique ID from BT Address.
  sc = sl_bt_system_get_identity_address(&address, &address_type);
  sl_app_assert(sc == SL_STATUS_OK,
                "[E: 0x%04x] Failed to get Bluetooth address\n",
                (int)sc);

  return ( address.addr[0] << 24 ) | ( address.addr[3] << 16 ) | ( address.addr[5] << 8 ) | address.addr[2];
#else
  // TODO
  // TRNG peripheral not yet available in this SDK release
  return 12345678;
#endif
}


void BoardGetUniqueId( uint8_t *id )
{
#ifdef BLUETOOTH_ID_PRESENT
  sl_status_t sc;
  bd_addr address;
  uint8_t address_type;

  // Extract unique ID from BT Address.
  sc = sl_bt_system_get_identity_address(&address, &address_type);
  sl_app_assert(sc == SL_STATUS_OK,
                "[E: 0x%04x] Failed to get Bluetooth address\n",
                (int)sc);

  // Pad and reverse unique ID to get System ID.
  id[0] = address.addr[5];
  id[1] = address.addr[4];
  id[2] = address.addr[3];
  id[3] = 0xFF;
  id[4] = 0xFE;
  id[5] = address.addr[2];
  id[6] = address.addr[1];
  id[7] = address.addr[0];
#else
  // TODO
  // Read chip unique id
  uint8_t id_demo[8] = { 0x68, 0x0A, 0xE2, 0xFF, 0xFE, 0x28, 0x7F, 0xF9 };

  memcpy( id, id_demo, 8 );
  return;
#endif
}

uint16_t BoardBatteryMeasureVoltage( void )
{
    return 0;
}

uint32_t BoardGetBatteryVoltage( void )
{
    return 0;
}

uint8_t BoardGetBatteryLevel( void )
{
    return 0;
}

uint8_t GetBoardPowerSource( void )
{
  return BATTERY_POWER;
}

#if !defined ( __CC_ARM )


#else

#include <stdio.h>

// Keil compiler
int fputc( int c, FILE *stream )
{
    while( UartPutChar( &Uart2, ( uint8_t )c ) != 0 );
    return c;
}

int fgetc( FILE *stream )
{
    uint8_t c = 0;
    while( UartGetChar( &Uart2, &c ) != 0 );
    // Echo back the character
    while( UartPutChar( &Uart2, c ) != 0 );
    return ( int )c;
}

#endif

#ifdef USE_FULL_ASSERT

#include <stdio.h>

/*
 * Function Name  : assert_failed
 * Description    : Reports the name of the source file and the source line number
 *                  where the assert_param error has occurred.
 * Input          : - file: pointer to the source file name
 *                  - line: assert_param error line source number
 * Output         : None
 * Return         : None
 */
void assert_failed( uint8_t* file, uint32_t line )
{
    /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %lu\n", file, line) */

    printf( "Wrong parameters value: file %s on line %lu\n", ( const char* )file, line );
    /* Infinite loop */
    while( 1 )
    {
    }
}
#endif
