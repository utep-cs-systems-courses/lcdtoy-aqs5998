state:
        .zero   1 ; initialized variables
songState:
        .zero   1 ;initialized variables
stateSong:
        .zero   1 ;initialized variables
.LC0: ;beggining of the declaration of each note in the array
        .short  506 
        .short  506
        .short  506
        .short  0
        .short  506
        .short  506
        .short  0
        .short  506
        .short  0
        .short  506
        .short  506
        .short  0
        .short  379
        .short  0
        .short  379
        .short  379
        .short  0
        .short  379
        .short  425
        .short  0
        .short  425
        .short  425
        .short  0
        .short  425
        .short  0
        .short  562
        .short  0
        .short  506
        .short  506
        .short  0
        .short  506
        .short  506
        .short  0
        .short  506
        .short  0
        .short  506
        .short  0
        .short  379
        .short  379
        .short  506
        .short  506
        .short  0
        .short  506
        .short  0
        .short  506
        .short  506
        .short  0
        .short  379
        .short  379
        .short  506
        .short  506
        .short  0
        .short  506
        .short  0
        .short  506
        .short  506
        .short  0
        .short  379
        .short  0
        .short  379
        .short  379
        .short  0
        .short  379
        .short  0
        .short  425
        .short  0
        .short  425
        .short  425
        .short  0
        .short  425
        .short  425
        .short  0
        .short  568
        .short  568
        .short  0
        .short  506
        .short  506
        .short  0
        .short  506
        .short  506
        .short  0
        .short  506
        .short  0
        .short  506
        .short  506
        .short  0
        .short  506
        .short  506
        .short  0
        .short  379
        .short  379
        .short  0
        .short  506
        .short  506
        .short  0
        .short  506
        .short  506
        .short  0
        .short  506
        .short  0
        .short  506
        .short  506
        .short  0
        .short  506
        .short  0
        .short  379
        .short  379
        .short  0
        .short  506
        .short  0
        .short  506
        .short  0
        .short  506
        .short  0
        .short  506
        .short  0
        .short  506
        .short  0
        .short  506
        .short  0
        .short  506
        .short  506
        .short  0
        .short  506
        .short  506
        .short  0
        .short  379
        .short  0
        .short  379
        .short  379
        .short  0
        .short  379
        .short  379
        .short  0
        .short  425
        .short  0
        .short  425
        .short  425
        .short  0
        .short  425
        .short  425
        .short  0
        .short  568
        .short  568
        .short  0
        .short  506
        .short  0
        .short  506
        .short  0
        .short  506
        .short  0
        .short  506
        .short  0
        .short  506
        .short  0
        .short  506
        .short  506
        .short  0
        .short  506
        .short  506
        .short  0
        .short  506
        .short  506
        .short  0
        .short  379
        .short  379
        .short  0
        .short  506
        .short  0
        .short  506
        .short  0
        .short  506
        .short  0
        .short  506
        .short  0
        .short  506
        .short  0
        .short  379
        .short  0
        .short  506
        .short  506
        .short  506
        .short  0
        .short  506
        .short  506
        .short  506
        .short  506
        .short  506
        .short  0
playSong:
        SUB.W   #378, R1 ;subracts a word from 378 to r1
        MOV.W   R1, R12 ;moves register to R12
        MOV.W   #.LC0, R13 ;moves the array from c to r13
        MOV.W   #378, R14 ;move the 
        CALL    #memcpy ; Calls memcpy
        MOV.B   &stateSong, R12 ;calls the method and moves to R12
        ADD.W   R12, R12 ;adds what is in r12 to r12
        MOV.W   #378, R13
        ADD.W   R1, R13
        ADD.W   R13, R12 ;adds word from R13 to R12
        ADD.W   #-378, R12
        MOV.W   @R12, R12 ;Gets the value of what is inside of r12 and moves that to r12
        CALL    #buzzer_set_period ;calls the buzzersetperiod method
        MOV.B   &stateSong, R12 ; moves stateSong into R12
        ADD.B   #1, R12 ;Adds one to R12 so this is making an incrementation to the statesong to be able to move to the next note
        AND     #0xff, R12 
        MOV.B   R12, &stateSong ; Moving what is in R12 to stateSong so this is updating the varable 
        NOP
        ADD.W   #378, R1
        RET ;Returns the data