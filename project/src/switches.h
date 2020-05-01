#ifndef switches_included
#define switches_included

#define SW1 BIT0                /* switch1 is p1.3 */
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3

#define SWITCHES (SW1|SW2|SW3|SW4)
//#define SWITCHES SW2/* only 3 switchs on this board */
void switch_init();
void switch_interrupt_handler();

extern char songStatus, button2_state_down,button3_state_down, button4_state_down, switch_state_down, switch_state_changed; /* effectively boolean */

#endif // included
