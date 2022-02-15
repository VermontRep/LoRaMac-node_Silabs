
#include <stdbool.h>
#include "em_common.h"
#include "sl_simple_timer.h"

#include "timer.h"

struct timers {

  sl_simple_timer_t sl_simple_timer;
  TimerEvent_t * p_TimerEvent;

} ast_timers[16];

static uint8_t timer_taken;

void timer_cb_0(sl_simple_timer_t *timer, void *data) {

  (void)data;
  (void)timer;
  ast_timers[0].p_TimerEvent->Callback( ast_timers[0].p_TimerEvent->Context );

}

void timer_cb_1(sl_simple_timer_t *timer, void *data) {

  (void)data;
  (void)timer;
  ast_timers[1].p_TimerEvent->Callback( ast_timers[1].p_TimerEvent->Context );

}

void timer_cb_2(sl_simple_timer_t *timer, void *data) {

  (void)data;
  (void)timer;
  ast_timers[2].p_TimerEvent->Callback( ast_timers[2].p_TimerEvent->Context );

}

void timer_cb_3(sl_simple_timer_t *timer, void *data) {

  (void)data;
  (void)timer;
  ast_timers[3].p_TimerEvent->Callback( ast_timers[3].p_TimerEvent->Context );

}

void timer_cb_4(sl_simple_timer_t *timer, void *data) {

  (void)data;
  (void)timer;
  ast_timers[4].p_TimerEvent->Callback( ast_timers[4].p_TimerEvent->Context );

}

void timer_cb_5(sl_simple_timer_t *timer, void *data) {

  (void)data;
  (void)timer;
  ast_timers[5].p_TimerEvent->Callback( ast_timers[5].p_TimerEvent->Context );

}

void timer_cb_6(sl_simple_timer_t *timer, void *data) {

  (void)data;
  (void)timer;
  ast_timers[6].p_TimerEvent->Callback( ast_timers[6].p_TimerEvent->Context );

}

void timer_cb_7(sl_simple_timer_t *timer, void *data) {

  (void)data;
  (void)timer;
  ast_timers[7].p_TimerEvent->Callback( ast_timers[7].p_TimerEvent->Context );

}

void timer_cb_8(sl_simple_timer_t *timer, void *data) {

  (void)data;
  (void)timer;
  ast_timers[8].p_TimerEvent->Callback( ast_timers[8].p_TimerEvent->Context );

}

void timer_cb_9(sl_simple_timer_t *timer, void *data) {

  (void)data;
  (void)timer;
  ast_timers[9].p_TimerEvent->Callback( ast_timers[9].p_TimerEvent->Context );

}

void timer_cb_10(sl_simple_timer_t *timer, void *data) {

  (void)data;
  (void)timer;
  ast_timers[10].p_TimerEvent->Callback( ast_timers[10].p_TimerEvent->Context );

}

void timer_cb_11(sl_simple_timer_t *timer, void *data) {

  (void)data;
  (void)timer;
  ast_timers[11].p_TimerEvent->Callback( ast_timers[11].p_TimerEvent->Context );

}

void timer_cb_12(sl_simple_timer_t *timer, void *data) {

  (void)data;
  (void)timer;
  ast_timers[12].p_TimerEvent->Callback( ast_timers[12].p_TimerEvent->Context );

}

void timer_cb_13(sl_simple_timer_t *timer, void *data) {

  (void)data;
  (void)timer;
  ast_timers[13].p_TimerEvent->Callback( ast_timers[13].p_TimerEvent->Context );

}

void timer_cb_14(sl_simple_timer_t *timer, void *data) {

  (void)data;
  (void)timer;
  ast_timers[14].p_TimerEvent->Callback( ast_timers[14].p_TimerEvent->Context );

}

void timer_cb_15(sl_simple_timer_t *timer, void *data) {

  (void)data;
  (void)timer;
  ast_timers[15].p_TimerEvent->Callback( ast_timers[15].p_TimerEvent->Context );

}

uint8_t timer_find_index ( TimerEvent_t *obj ) {

  for( int i = 0; i < 16; i++ ) {

      if ( obj == ast_timers[i].p_TimerEvent ) {
          return i;
      }

  }

  return 0;

}

void TimerInit( TimerEvent_t *obj, void ( *callback )( void *context ) ) {

  obj->Timestamp = 0;
  obj->ReloadValue = 0;
  obj->IsStarted = false;
  obj->IsNext2Expire = false;
  obj->Callback = callback;
  obj->Context = NULL;
  obj->Next = NULL;

  ast_timers[timer_taken].p_TimerEvent = obj;
  timer_taken++;

  return;

}

void TimerSetValue( TimerEvent_t *obj, uint32_t value ) {

  obj->Timestamp = value;
  obj->ReloadValue = value;

  return;

}

void TimerStart( TimerEvent_t *obj ) {

  sl_simple_timer_callback_t callback;

  uint8_t timer_idx = timer_find_index(obj);

  switch(timer_idx) {
    default:
    case 0: callback = timer_cb_0; break;
    case 1: callback = timer_cb_1; break;
    case 2: callback = timer_cb_2; break;
    case 3: callback = timer_cb_3; break;
    case 4: callback = timer_cb_4; break;
    case 5: callback = timer_cb_5; break;
    case 6: callback = timer_cb_6; break;
    case 7: callback = timer_cb_7; break;
    case 8: callback = timer_cb_8; break;
    case 9: callback = timer_cb_9; break;
    case 10: callback = timer_cb_10; break;
    case 11: callback = timer_cb_11; break;
    case 12: callback = timer_cb_12; break;
    case 13: callback = timer_cb_13; break;
    case 14: callback = timer_cb_14; break;
    case 15: callback = timer_cb_15; break;
  }

  sl_simple_timer_start( &ast_timers[timer_idx].sl_simple_timer,
                         ast_timers[timer_idx].p_TimerEvent->Timestamp,
                         callback,
                         NULL,
                         false );

}

void TimerStop( TimerEvent_t * obj ) {

  uint8_t timer_idx = timer_find_index(obj);

  sl_simple_timer_stop(&ast_timers[timer_idx].sl_simple_timer);

}

TimerTime_t TimerGetCurrentTime( void ) {

  return 0;
}

TimerTime_t TimerGetElapsedTime( TimerTime_t past ) {

  (void)past;

  return 0;
}
