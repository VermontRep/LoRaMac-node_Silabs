
#include <stddef.h>

#include "em_cmu.h"
#include "em_gpio.h"
#include "gpiointerrupt.h"

#include "gpio-board.h"
#include "board-config.h"

static GpioIrqHandler *GpioIrq[16];

void GpioMcuInit( Gpio_t *obj, PinNames pin, PinModes mode, PinConfigs config, PinTypes type, uint32_t value ) {

  (void)config;
  (void)type;

  GPIO_Mode_TypeDef GPIO_Mode = gpioModeDisabled;

  switch( mode ) {
    case PIN_INPUT:         GPIO_Mode = gpioModeInput; break;
    case PIN_OUTPUT:        GPIO_Mode = gpioModePushPull; break;
    case PIN_ALTERNATE_FCT: GPIO_Mode = gpioModePushPullAlternate; break;
    case PIN_ANALOGIC:      GPIO_Mode = gpioModeInput; break;
  }

  obj->portIndex = pin / 16;
  obj->pinIndex  = pin % 16;

  GPIO_PinModeSet(obj->portIndex, obj->pinIndex, GPIO_Mode, value);

}

void GpioMcuSetContext( Gpio_t *obj, void* context ) {

  obj->Context = context;

}

void GPIOINT_IrqCallbackPtr(uint8_t intNo) {

  if ( GpioIrq[intNo] != NULL ) {
      GpioIrq[intNo](NULL);
  }

}

void GpioMcuSetInterrupt( Gpio_t *obj, IrqModes irqMode, IrqPriorities irqPriority, GpioIrqHandler *irqHandler ) {

  (void)irqPriority;

  bool risingEdge = false;
  bool fallingEdge = false;

  switch( irqMode ) {
    case IRQ_RISING_EDGE:         risingEdge = true; break;
    case IRQ_FALLING_EDGE:        fallingEdge = true; break;
    case IRQ_RISING_FALLING_EDGE: risingEdge = fallingEdge = true; break;
    default: break;
  }

  GPIO_ExtIntConfig(obj->portIndex, obj->pinIndex, obj->pinIndex, risingEdge, fallingEdge, true );

  GPIOINT_Init();
  GPIOINT_CallbackRegister(obj->pinIndex,GPIOINT_IrqCallbackPtr);
  GpioIrq[obj->pinIndex] = irqHandler;
}

void GpioMcuRemoveInterrupt( Gpio_t *obj ) {

  GPIOINT_CallbackUnRegister( obj->pinIndex );

}

void GpioMcuWrite( Gpio_t *obj, uint32_t value ) {

  if ( value ) {
      GPIO_PinOutSet( obj->portIndex, obj->pinIndex );
  }
  else {
      GPIO_PinOutClear( obj->portIndex, obj->pinIndex );
  }

}

void GpioMcuToggle( Gpio_t *obj ) {

  GPIO_PinOutToggle( obj->portIndex, obj->pinIndex );

}

uint32_t GpioMcuRead( Gpio_t *obj ) {

  return GPIO_PinInGet( obj->portIndex, obj->pinIndex );

}
