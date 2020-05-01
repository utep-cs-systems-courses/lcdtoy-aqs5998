#include <msp430.h>
#include "stateMachines.h"
#include <stddef.h>
#include "buzzer.h"
#include "libTimer.h"
#include <stdio.h>
#include <stdlib.h>
#include "lcddraw.h"
#include "lcdutils.h"
#include "lcdtypes.h"

//char state = 0;
char songState = 0;
char stateSong = 0;
int shapePosition = 0;
//Plays Darude Sandstorm
void playSong()
{
  int notes[] = {506, 506, 506, 0, 506, 506, 0, 506, 0, 506, 506, 0, 379, 0, 379, 379, 0, 379, 425, 0, 425, 425, 0, 425, 0, 562, 0, 506, 506, 0, 506, 506, 0, 506, 0, 506, 0, 379, 379, 506, 506, 0, 506, 0, 506, 506, 0, 379, 379, 506, 506, 0, 506, 0, 506, 506, 0, 379, 0, 379, 379, 0, 379, 0, 425, 0, 425, 425, 0, 425, 425, 0, 568, 568, 0, 506, 506, 0, 506, 506, 0, 506, 0, 506, 506, 0, 506, 506, 0, 379, 379, 0, 506, 506, 0, 506, 506, 0, 506, 0, 506, 506, 0, 506, 0, 379, 379, 0, 506, 0, 506, 0, 506, 0, 506, 0, 506, 0, 506, 0, 506, 506, 0, 506, 506, 0, 379, 0, 379, 379, 0, 379, 379, 0, 425, 0, 425, 425, 0, 425, 425, 0, 568, 568, 0, 506, 0, 506, 0, 506, 0, 506, 0, 506, 0, 506, 506, 0, 506, 506, 0, 506, 506, 0, 379, 379, 0, 506, 0, 506, 0, 506, 0, 506, 0, 506, 0, 379, 0, 506, 506, 506, 0, 506, 506, 506, 506, 506, 0}; //,379,0,379,0,379,0,379,0,425,425,425,0,568,568,0,506,506,0,379,379,0,506,506,506,0,379,0,506,506};
  buzzer_set_period(notes[stateSong]);
  stateSong++;
}

/** Initializes everything, clears the screen, draws "hello" and a square */

void drawStuff()
{
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_RED);

  //drawString5x7(40,20, "hello world", COLOR_ORANGE, COLOR_BLUE);

  fillRectangle(50+(shapePosition*3),90+(shapePosition*3), 60, 60, COLOR_GREEN);
  for (signed char row = -20; row <= 40; row++){
    if (row <= 0){
      drawPixel(row + 20 + (shapePosition *10), row + 20+(shapePosition*10), COLOR_BLUE);
    }
    else{
	for (signed char col = - row; col<=row;col++){
	  drawPixel(col + 20+(shapePosition*10), row + 20+(shapePosition*10), COLOR_BLACK);
	}
    }
  }
  shapePosition++;
}


//Plays another song that is not being used
/*
void playSongSwitch()
{
  //buzzer_set_period(1000);
  //int notes[] = {1000, 0, 810, 740, 0, 810, 830, 845, 840, 845, 0, 0, 0, 790, 770, 0, 2000};
  // for(int i = 0; notes[i]!=790;i++){
  // buzzer_set_period(notes[i]);
  // }

  static char state = 0;
  switch (state)
  {
  case 0:
    state = 1;
    buzzer_set_period(523); //C
    break;
  case 1:
    state = 2;
    buzzer_set_period(523); //C
    break;
  case 2:
    state = 3;
    buzzer_set_period(500); //D
    break;
  case 3:
    state = 4;
    buzzer_set_period(450); //E
    break;
  case 4:
    state = 5;
    buzzer_set_period(450); //E
    break;
  case 5:
    state = 6;
    buzzer_set_period(500); //D
    break;
  case 6:
    state = 7;
    buzzer_set_period(523); //C
    break;
  case 7:
    state = 8;
    buzzer_set_period(600); //B
    break;
  case 8:
    state = 9;
    buzzer_set_period(650); //A
    break;
  case 9:
    state = 10;
    buzzer_set_period(650); //A
    break;
  case 10:
    state = 11;
    buzzer_set_period(600); //B
    break;
  case 11:
    state = 12;
    buzzer_set_period(523); //c
    break;
  case 12:
    state = 13;
    buzzer_set_period(600); //B
    break;
  case 13:
    state = 14;
    buzzer_set_period(600);
    break;
  case 14:
    state = 15;
    buzzer_set_period(0);
    buzzer_init();
    break;
  }
}
*/
