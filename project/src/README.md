# Lab 2: Functionality added by Alex Sanchez

The MSP430 Microcontroller, Each MSP430 board is equipped with buttons, LED's, a speaker, and an LED screen. 

# Instructions on how to run

1. Clone this repository to your machine windows, or mac is fine
2. Enter the timerLib folder directory
3. Install the h files by entering make install in the command line
4. Make sure that you see the h folder in your directory
4. Enter the src folder
5. Connect the MSP430 Microcontroller
6. Enter "make load" on the command line
7. The program is now loaded onto your MSP430

This toy should at minimum:

* generate sounds,
* dynamically change the LEDs that are illuminated, both brighly and dimmly,
* implement a state machine to maintain the state of the toy,
* and use the four buttons on the expansion board (P2.0-3) to transition the state machine.

# Button 1 (X 0 0 0)

Press this button to toggle between a bright red light, or a dim green light. If you leave the dim light on and play the song then the light will flicker with the music. If you leave the solid red light on then the light will just stay on

# Button 2 (0 X 0 0 )

Press this button to play Sandstorm. Sandstorm is an instrumental spong by Finnish DJ and record producer Darude. The song was released in 1999. Pressing the button again will play the song starting over. 

# Button 3 (0 0 X 0 )

Getting tired of the song? Press button 3 to turn off the song to a deep buzz sound

# Button 4 (0 0 0 X)

Would you like to play the first 5 notes of Beethoven? Then press the 4th button play the toy like a toy piano! Play an older song with an older programming language assembly

## Switches.c .h 
Sets up the MSP430 to respond to button presses to be able to active the leds. This file enables the resistors, the interrupts from the switches, and pull ups for the swtiches to allow the MSP430 to interact with the user.

## LED.c .h 
Has several methods such as led_init led_update, state_change, and ledOFF(). 

Led_init 
Initializes the leds to P1DIR to attatch the bits to the led output. 

Led_update changes the leds from red to green. The green led is dimmied by changing the clock cycle speed.

Led_OFF
Simply turns the leds off by clearing P1OUT

## stateMachines.c .h 

PlaySong()
Sets notes in an in array. Traverses the array through the cycles in the wdInteruptHanlder.c Also includes the playSongSwitch assemlby song in the C programming language in comments.

## buzzer.c .h 
Simply has buzzer_init that sets the bits to allow the buzzer to play.

## assemblySongSwitch.h .s
Has the beethoven song that uses assemlby

## wdInterruptHanlder.c .h
Plays the song using the cycles also interacts with the statemachine to play Darude SandStorm

## Getting Started 

Inside this repository you will find two directories:
1. The 'demos' directory contains sample programs for you to review and learn from. These example programs are a great starting point in understanding how to program the MSP430 microcontroller. See the readme in the demo directory on how to compile and run the demo programs.
2. The 'project' directory should contain the source code for your toy.

