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
 * Board MCU pins definitions
 */
#define SILABS_BRD4184B				// Define here which Silabs Board is used, otherwise, create custom set

#if defined( SX1261MBXBAS ) || defined( SX1262MBXCAS ) || defined( SX1262MBXDAS )

#ifdef SILABS_BRD2503A  //BRD2503A(Thunderboard PG22)
	#define RADIO_RESET                                 PB_1
	#define RADIO_MOSI                                  PC_0
	#define RADIO_MISO                                  PC_1
	#define RADIO_SCLK                                  PC_2
	#define RADIO_NSS                                   PB_2
	#define RADIO_BUSY                                  PB_0
	#define RADIO_DIO_1                                 PB_3
	#define RADIO_ANT_SWITCH_POWER                      PA_4
#endif	//SILABS_BRD2503A
#ifdef SILABS_BRD2601B  //BRD2601B(Thunderboard MG24)
	#define RADIO_RESET                                 PB_0
	#define RADIO_MOSI                                  PC_3
	#define RADIO_MISO                                  PC_2
	#define RADIO_SCLK                                  PC_1
	#define RADIO_NSS                                   PA_7
	#define RADIO_BUSY                                  PB_2
	#define RADIO_DIO_1                                 PD_2
	#define RADIO_ANT_SWITCH_POWER                      PB_3
#endif	//SILABS_BRD2601B
#ifdef SILABS_BRD4104A  //BRD4104A(Radio board BG13 + Base Board)
	#define RADIO_RESET                                 PD_11
	#define RADIO_MOSI                                  PC_6
	#define RADIO_MISO                                  PC_7
	#define RADIO_SCLK                                  PC_8
	#define RADIO_NSS                                   PC_9
	#define RADIO_BUSY                                  PD_10
	#define RADIO_DIO_1                                 PF_3
	#define RADIO_ANT_SWITCH_POWER                      PD_12
#endif	//SILABS_BRD4104A
#ifdef SILABS_BRD4108A  //BRD4108A(Explorer Kit BG22)
	#define RADIO_RESET                                 PD_2
	#define RADIO_MOSI                                  PC_0
	#define RADIO_MISO                                  PC_1
	#define RADIO_SCLK                                  PC_2
	#define RADIO_NSS                                   PC_3
	#define RADIO_BUSY                                  PD_3
	#define RADIO_DIO_1                                 PB_2
	#define RADIO_ANT_SWITCH_POWER                      PB_1
#endif	//SILABS_BRD4108A
#ifdef SILABS_BRD4182A  //BRD4182A(Base board + Radio Board MG22)
	#define RADIO_RESET                                 PB_1
	#define RADIO_MOSI                                  PC_0
	#define RADIO_MISO                                  PC_1
	#define RADIO_SCLK                                  PC_2
	#define RADIO_NSS                                   PC_3
	#define RADIO_BUSY                                  PB_0
	#define RADIO_DIO_1                                 PD_3
	#define RADIO_ANT_SWITCH_POWER                      PD_2
#endif	//SILABS_BRD4182A
#ifdef SILABS_BRD4183A  //BRD4183A(Base board + Radio Board MG22 QFN32)
	//ATTENTION!!! The BRD4183A board (QFN32) does not have enough IO pins to run this code...
	#error "The BRD4183A board (QFN32) does not have enough IO pins to support LoRa shields"
#endif	//SILABS_BRD4183A
#ifdef SILABS_BRD4184A  //BRD4184A(Thunderboard BG22)
	#define RADIO_RESET                                 PC_7
	#define RADIO_MOSI                                  PC_0
	#define RADIO_MISO                                  PC_1
	#define RADIO_SCLK                                  PC_2
	#define RADIO_NSS                                   PB_2
	#define RADIO_BUSY                                  PC_6
	#define RADIO_DIO_1                                 PB_1
	#define RADIO_ANT_SWITCH_POWER                      PB_0
#endif	//SILABS_BRD4184A
#ifdef SILABS_BRD4184B  //BRD4184B(New Thunderboard BG22)
	#define RADIO_RESET                                 PB_1
	#define RADIO_MOSI                                  PC_0
	#define RADIO_MISO                                  PC_1
	#define RADIO_SCLK                                  PC_2
	#define RADIO_NSS                                   PB_2
	#define RADIO_BUSY                                  PB_0
	#define RADIO_DIO_1                                 PB_3
	#define RADIO_ANT_SWITCH_POWER                      PA_4
#endif	//SILABS_BRD4184B

#elif defined( LR1110MB1XXS )

// WARNING!!! Need to create definitions for LR1110 board

#define RADIO_NSS                                   PA_8
#define RADIO_BUSY                                  PB_3
#define RADIO_DIO_1                                 PB_4

#define LED_1                                       PC_1
#define LED_2                                       PC_0

// Debug pins definition.
#define RADIO_DBG_PIN_TX                            PB_6
#define RADIO_DBG_PIN_RX                            PC_7

#elif defined( SX1272MB2DAS) || defined( SX1276MB1LAS ) || defined( SX1276MB1MAS )

// WARNING!!! Need to create definitions for SX1272 board

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


#ifdef __cplusplus
}
#endif

#endif // __BOARD_CONFIG_H__
