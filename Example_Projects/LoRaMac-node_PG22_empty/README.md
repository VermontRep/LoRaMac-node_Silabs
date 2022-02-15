
# LoRaMacNode for Silabs Family 2 - Example Projects

## LoRaMac-node_PG22_empty

Project File ready to use: `LoRaMac-node_PG22_empty.sls`

Summary:
	-	Silabs MCU Board: **PG22-DK2503A**
	-	Semtech mbed shield: **SX1262MB2xAS**
	-	Base Project: **Empty C Project**
	-	Added Functions: *LoRaWAN + print functions*

## Files to Replace in the Basic Project when creating it

Replace the following file:
-	`app.c`

## Software Components to Add to Basic Project when creating it

To create a similar project, open the `.slcp` file, review the installed items and add the missing Software Components from the following lists.

-	To include only the LoRaWAN stack sending fixed values ofr Relative Humidity & Temperature (no sensor support):
	-	`Application > Utility> Assert`
	-	`Application > Utility> Log`
	-	`Services > IO Stream> IO Stream: USART "vcom" (nome preferencial)`
	-	`Application > Service > Simple Timer Service`
	-	`-Platform > Board> Kit > Development Kit > PG22-DK2503A`
	-	`Services > NVM3 > NVM3 Core`
	-	`Services > NVM3 > NVM3 Default Instance`
	-	`Services > CLI > CLI Core`
	-	`Platform > Driver > GPIOINT`
	-	`Services > IO Stream > Retarget STDIO`
	-	`Platform > Peripheral > MSC`
	-	`Platform > Drivers > EMDRV Common Headers`
	-	`Platform > Utilities > String Functions`
