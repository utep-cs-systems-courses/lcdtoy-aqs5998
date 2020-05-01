#include <msp430.h>
#include "stateMachines.h"
#include "buzzer.h"
#include "switches.h"
#include "assemblySongSwitch.h"

/* Enters a state depending on the songState char variable */
static char blink_count = 0;

void
    __interrupt_vec(WDT_VECTOR) WDT()
{
  
  if (songState == 1)
  {
    if (++blink_count == 2)
    {
      blink_count=0;
      playSong();
      blink_count = 0;
    }
  }
  if (songState == 3)
  {
    buzzer_set_period(1000);
    blink_count = 0;
    songState = 0;
  }
  if (songState == 4) {
    blink_count = 5;
    state_adv();
  }
  

  //This section is not being used
  /*
  if (++blink_count == 3) {
    // state_advance();
    // buzzer_set_period(1000);
    //playSong();
    if(songStatus == 1 && ++blink_count ==3){//Play music and blink with first button.
      playSong();
      blink_count=0;
    }
    blink_count = 0;
  }
  */
}
