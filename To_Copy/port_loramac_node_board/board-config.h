#ifndef __BOARD_CONFIG_H__
#define __BOARD_CONFIG_H__

#ifdef __cplusplus
extern "C"
{
#endif

/*!
 * Defines the time required for the TCXO to wakeup [ms].
 */
#if defined( SX1262MBXDAS )
#define BOARD_TCXO_WAKEUP_TIME                      5
#else
#define BOARD_TCXO_WAKEUP_TIME                      0
#endif

/*!
 * Board MCU pins definitions - BRD4184A - BG22 1st block OK
 */
//#define RADIO_RESET                                 PC_7	//BRD4184A 
#define RADIO_RESET                                 PB_1	//BRD4182A + BRD2503A 

#define RADIO_MOSI                                  PC_0	//BR4182A + BRD4184A + BRD2503A
#define RADIO_MISO                                  PC_1	//BR4182A + BRD4184A + BRD2503A
#define RADIO_SCLK                                  PC_2	//BR4182A + BRD4184A + BRD2503A

#if defined( SX1261MBXBAS ) || defined( SX1262MBXCAS ) || defined( SX1262MBXDAS )

#define RADIO_NSS                                   PB_2	//BRD4184A + BRD2503A
//#define RADIO_NSS                                   PC_3	//BRD4182A
//#define RADIO_BUSY                                  PC_6	//BRD4184A
#define RADIO_BUSY                                  PB_0	//BRD4182A + BRD2503A
//#define RADIO_DIO_1                                 PB_1	//BRD4184A
//#define RADIO_DIO_1                                 PD_3	//BRD4182A
#define RADIO_DIO_1                                 PB_3	//BRD2503A

//#define RADIO_ANT_SWITCH_POWER                      PB_0	//BRD4184A
//#define RADIO_ANT_SWITCH_POWER                      PD_2	//BRD4182A
#define RADIO_ANT_SWITCH_POWER                      PA_4	//BRD2503A

#elif defined( LR1110MB1XXS )

#define RADIO_NSS                                   PA_8
#define RADIO_BUSY                                  PB_3
#define RADIO_DIO_1                                 PB_4

#define LED_1                                       PC_1
#define LED_2                                       PC_0

// Debug pins definition.
#define RADIO_DBG_PIN_TX                            PB_6
#define RADIO_DBG_PIN_RX                            PC_7

#elif defined( SX1272MB2DAS) || defined( SX1276MB1LAS ) || defined( SX1276MB1MAS )

#define RADIO_NSS                                   PB_6

#define RADIO_DIO_0                                 PA_10
#define RADIO_DIO_1                                 PB_3
#define RADIO_DIO_2                                 PB_5
#define RADIO_DIO_3                                 PB_4
#define RADIO_DIO_4                                 PA_9
#define RADIO_DIO_5                                 PC_7

#define RADIO_ANT_SWITCH                            PC_1

#define LED_1                                       NC
#define LED_2                                       NC

// Debug pins definition.
#define RADIO_DBG_PIN_TX                            PB_0
#define RADIO_DBG_PIN_RX                            PA_4

#endif


#ifdef __cplusplus
}
#endif

#endif // __BOARD_CONFIG_H__
