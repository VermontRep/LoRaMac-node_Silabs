
#include "em_cmu.h"
#include "em_gpio.h"
#include "em_usart.h"

#include "spi.h"

static uint8_t mosi_port;
static uint8_t mosi_pin;

static uint8_t miso_port;
static uint8_t miso_pin;

static uint8_t sclk_port;
static uint8_t sclk_pin;

static uint8_t nss_port;
static uint8_t nss_pin;

void initGpio(void)
{
  // Enable clock (not needed on xG21)
  CMU_ClockEnable(cmuClock_GPIO, true);

  // Configure RX pin as an input
  GPIO_PinModeSet(miso_port, miso_pin, gpioModeInput, 0);

  // Configure TX pin as an output
  GPIO_PinModeSet(mosi_port, mosi_pin, gpioModePushPull, 0);

  // Configure CLK pin as an output low (CPOL = 0)
  GPIO_PinModeSet(sclk_port, sclk_pin, gpioModePushPull, 0);

  // Configure CS pin as an output and drive inactive high
  GPIO_PinModeSet(nss_port, nss_pin, gpioModePushPull, 1);
}

void initUsart0(void)
{
  // Default asynchronous initializer (master mode, 1 Mbps, 8-bit data)
  USART_InitSync_TypeDef init = USART_INITSYNC_DEFAULT;

  // Enable clock (not needed on xG21)
  CMU_ClockEnable(cmuClock_USART0, true);
  init.msbf = true;   // MSB first transmission for SPI compatibility

  /*
   * Route USART0 RX, TX, and CLK to the specified pins.  Note that CS is
   * not controlled by USART0 so there is no write to the corresponding
   * USARTROUTE register to do this.
   */
  GPIO->USARTROUTE[0].RXROUTE = (miso_port << _GPIO_USART_RXROUTE_PORT_SHIFT)
      | (miso_pin << _GPIO_USART_RXROUTE_PIN_SHIFT);
  GPIO->USARTROUTE[0].TXROUTE = (mosi_port << _GPIO_USART_TXROUTE_PORT_SHIFT)
      | (mosi_pin << _GPIO_USART_TXROUTE_PIN_SHIFT);
  GPIO->USARTROUTE[0].CLKROUTE = (sclk_port << _GPIO_USART_CLKROUTE_PORT_SHIFT)
      | (sclk_pin << _GPIO_USART_CLKROUTE_PIN_SHIFT);

  // Enable USART interface pins
  GPIO->USARTROUTE[0].ROUTEEN = GPIO_USART_ROUTEEN_RXPEN |    // MISO
                                GPIO_USART_ROUTEEN_TXPEN |    // MOSI
                                GPIO_USART_ROUTEEN_CLKPEN;

  // Configure and enable USART0
  USART_InitSync(USART0, &init);
}

void SpiInit( Spi_t *obj, SpiId_t spiId, PinNames mosi, PinNames miso, PinNames sclk, PinNames nss ) {

  (void)obj;
  (void)spiId;

  mosi_port = mosi / 16;
  mosi_pin  = mosi % 16;

  miso_port = miso / 16;
  miso_pin  = miso % 16;

  sclk_port = sclk / 16;
  sclk_pin  = sclk % 16;

  nss_port = nss / 16;
  nss_pin  = nss % 16;

  initGpio();
  initUsart0();

}

uint16_t SpiInOut( Spi_t *obj, uint16_t outData ) {

  (void)obj;

  /*
   * Repeatedly perform single byte SPI transfers (transmission and
   * reception) of the specified length.  USART_SpiTransfer() polls
   * USART_STATUS_TXC for transmission complete, so this function ties
   * up the CPU until the last bit of the byte being transmitted is sent.
   */

  return USART_SpiTransfer(USART0, outData);

}

