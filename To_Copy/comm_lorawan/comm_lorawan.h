#ifndef COMM_LORAWAN_H_
#define COMM_LORAWAN_H_

#include <stdint.h>
#include "LmHandler.h"

void comm_lorawan_init ( void );
void comm_lorawan_loop ( void );
bool comm_lorawan_request_tx ( uint8_t * p_data, uint8_t size, uint8_t port, bool confirmed );
void comm_lorawan_rx_callback ( LmHandlerAppData_t* appData, LmHandlerRxParams_t* params );

#endif /* COMM_LORAWAN_H_ */
