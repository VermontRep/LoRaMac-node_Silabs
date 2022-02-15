
# LoRaMacNode for Silabs Family 2 - Example Projects

## LoRaMac-node_PG22_blink_baremetal_Si70xx

Project File ready to use: `LoRaMac-node_PG22_blink_baremetal_Si70xx.sls`

Summary:
-	Silabs MCU Board: **PG22-DK2503A**
-	Semtech mbed shield: **SX1262MB2xAS**
-	Base Project: **Platform - Blink Baremetal**
-	Added Functions: *LoRaWAN + Si70xx (RH&T sensor) + print functions*

## Files to Replace in the Basic Project when creating it

Replace the following file:
-	`blink.c`

## Software Components to Add to Basic Project when creating it

To create a similar project, open the `.slcp` file, review the installed items and add the missing Software Components from the following lists.

-	To include only the Relative Humidity & Temperature sensor support:
```
	-	Application > Utility> Assert
	-	Application > Utility> Log
	-	Services > IO Stream> IO Stream: USART "vcom" (nome preferencial)
	-	Services > IO Stream> USART Core
	-	Application > Service > Simple Timer Service
	-	Third Party > Tiny printf
	-	Platform > Board Drivers > Si70xx - Temperature/Humidity Sensor
	-	Platform > Driver > I2CSPM > sensor
	-	Platform > Driver > I2CSPM Core
	-	Platform > Peripheral > I2C
	-	Application > Sensor > Relative Humidity and Temperature sensor
```

-	To additionally include the LoRaWAN stack:
```
	-	Services > NVM3 > NVM3 Core
	-	Services > NVM3 > NVM3 Default Instance
	-	Services > CLI > CLI Core
	-	Platform > Driver > GPIOINT
	-	Services > IO Stream > Retarget STDIO
	-	Platform > Peripheral > MSC
	-	Platform > Drivers > EMDRV Common Headers
	-	Platform > Utilities > String Functions
```
