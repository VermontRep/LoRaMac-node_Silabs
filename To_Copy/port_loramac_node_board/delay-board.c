
#include "em_common.h"
#include "sl_udelay.h"

/*!
 * Blocking delay of "ms" milliseconds
 */
void DelayMsMcu( uint32_t ms ) {

  sl_udelay_wait(ms*1000);

}
