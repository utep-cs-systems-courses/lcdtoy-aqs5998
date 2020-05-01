# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include
LDFLGS		= -L/opt/ti/msp430_gcc/include -L../lib

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as
AR		= msp430-elf-ar
all: buzzer.elf libLcd.a lcddemo.elf

#additional rules for files
buzzer.elf: ${COMMON_OBJECTS}lcddraw.o lcdutils.o p1_interrupt_handler.o led.o assemblySongSwitch.o switches.o buzzer.o buzzerMain.o wdInterruptHandler.o stateMachines.o ../lib/libTimer.a
	${CC} ${CFLAGS} -o $@ $^

load:buzzer.elf
	msp430loader.sh $^
#should remove all o and elf files
clean:
	rm -f *.o *.elf

libLcd.a: font-11x16.o font-5x7.o font-8x12.o lcdutils.o lcddraw.o
	$(AR) crs $@ $^


buzzer.c: buzzer.h
buzzerMain.c: buzzer.h
lcddraw.o: lcddraw.c lcddraw.h lcdutils.h
lcdutils.o: lcdutils.c lcdutils.h
stateMachines.o: stateMachines.h
assemblySongSwitch.o :assemblySongSwitch.h
wdInterruptHandler.o: stateMachines.h
lcdtypes.o: lcdtypes.h
lcddemo.elf: stateMachines.o lcddraw.o lcdutils.o libLcd.a
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ -lTimer

install: libLcd.a
