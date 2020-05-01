#include <msp430.h>
#include "led.h"
#include "switches.h"

unsigned char green = 0, red = 0;
static int state = 0;

void led_init()
{
  P1DIR |= LEDS; // bits attached to leds are output
  // P1SEL |= LEDS;
  switch_state_changed = 1;
  led_update();
}

void led_update()
{
  char ledFlags = 0;
  if (switch_state_down)
  {                 // Use this if statement if you want to use another button to hold
    state_change(); // Using this requires holding button 2 to make another work
    switch (state)
    {
    case 0:
      ledFlags = LED_RED; // Shows red led at full power
      P1SEL |= LEDS;
      CCR0 = 499;
      CCTL1 = OUTMOD_7;
      CCR1 = 2;
      TACTL = TASSEL_2 + MC_1;
      _BIS_SR(LEDS);
      break;
    case 1:
      ledFlags = LED_GREEN; // Shows green led at a dim level
      P1SEL |= LEDS;
      CCTL1 = OUTMOD_7;
      CCR0 = 499;
      CCR1 = 3;
      TACTL = TASSEL_2 + MC_1;
      // _BIS_SR(LPM0_bits);
      _BIS_SR(LEDS);
      break;
    case 2:
      P1OUT &= (0xff - LEDS) | ledFlags;
      P1OUT |= ledFlags;
      P1SEL |= LEDS;
      _BIS_SR(ledFlags);
      /*P1SEL |= LEDS;
     CCTL1 = OUTMOD_7;
    CCR0 = 499;
    CCR1 =99;
    TACTL =TASSEL_2 +MC_1;
    _BIS_SR(LEDS);
    P1SEL |= ledFlags;
    P1OUT |= ledFlags;
     */
      break;
    }
    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1SEL &= (0xff - LEDS) | ledFlags;
    P1SEL |= ledFlags;
    P1OUT |= ledFlags; // set bits for on leds
  }
  //switch_state_changed = 0;
}

void state_change()
{
  if (state == 0)
  { //0 is red, 1 is green
    state = 1;
  }
  else if (button2_state_down == '1')
  {
    state = 2;
  }
  else
  {
    state = 0;
  }
}

void ledOff()
{

  char ledFlags = 0;
  if (button4_state_down)
  {                 // Use this if statement if you want to use another button to hold
      P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
      P1SEL &= (0xff - LEDS) | ledFlags;
      P1SEL |= ledFlags;
      P1OUT |= ledFlags; // set bits for on leds
    
  }
}

void button_press(char c)
{
  if (c == 'g')
  {
    led_update();
    // ledFlags |= LED_RED;
    //PIOUT &= (0xff - LEDS) | ledFlags;
    // P1OUT |= ledFlags;
  }
}
