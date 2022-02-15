/***************************************************************************//**
 * @file
 * @brief Top level application functions
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

#include <stddef.h>
#include <stdbool.h>
#include <string.h>

#include "em_common.h"
#include "app_log.h"
#include "app_assert.h"
#include "sl_status.h"
#include "sl_simple_timer.h"

#include "comm_lorawan.h"



#define SL_BT_HT_MEASUREMENT_INTERVAL_SEC   1

#define LORA_TX_INTERVAL_SEC                30

// Periodic timer handle.
static sl_simple_timer_t lora_periodic_timer;

// Periodic timer callback.
static void lora_periodic_timer_cb(sl_simple_timer_t *timer, void *data);

static int tx_counter = 0;

/***************************************************************************//**
 * Initialize application.
 ******************************************************************************/
void app_init(void)
{

  sl_status_t sc;

  comm_lorawan_init();

  sc = sl_simple_timer_start(&lora_periodic_timer,
                             SL_BT_HT_MEASUREMENT_INTERVAL_SEC * 1000,
                             lora_periodic_timer_cb,
                             NULL,
                             true);
  app_assert(sc == SL_STATUS_OK,
                "[E: 0x%04x] Failed to start periodic timer\n",
                (int)sc);

  // Send first indication.
  lora_periodic_timer_cb(&lora_periodic_timer, NULL);

}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{

   comm_lorawan_loop();

}

/**************************************************************************//**
 * Timer callback
 * Called periodically to time periodic temperature measurements and indications.
 *****************************************************************************/
static void lora_periodic_timer_cb(sl_simple_timer_t *timer, void *data)
{
  (void)data;
  (void)timer;
  int32_t temperature = 25;
  uint32_t humidity = 20;
  uint8_t lora_data[8];

  app_log("Temperature / Humidity: %5.2f C / %5.2f RH\n", temperature/1000.0, humidity/1000.0);

 // Time to send ?
  if ( ++tx_counter >= LORA_TX_INTERVAL_SEC ) {

    tx_counter = 0;

    memcpy( &lora_data[0], &temperature, 4);
    memcpy( &lora_data[4], &humidity, 4);

    if ( comm_lorawan_request_tx( lora_data, 8, 1, true ) ) {
        app_log("comm_lorawan_request_tx_ok\n");
    }
    else {
        app_log("comm_lorawan_busy\n");
    }

  }

}

void comm_lorawan_rx_callback ( LmHandlerAppData_t* appData, LmHandlerRxParams_t* params ) {

  (void)params;

  switch( appData->Port ) {

    case 1: {
      __NOP();
      break;
    }

    default: {
      break;
    }

  }

}
