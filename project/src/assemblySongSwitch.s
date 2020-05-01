        .arch msp430g2553
        .p2align 1,0

        ;.global?
        .text
jt:     
        .word case01
        .word case02
        .word case03
        .word case04
        .word case05
        .word case06
        .word case07
        .word case08
        .word case09
        .word case10
        .word case11
        .word case12
        .word case13
        .word case14
        .word case15
        .word default
        .text
        .global state_adv
state_adv:
        cmp #16, &state
        jc default

        mov &state, r12
        add r12, r12 ; we are doing this to double the amount of "cells"
        mov jt(r12), r0 ;moving the data to the first position 

case01:
        mov #1, &state
        mov #523, r12
        call #buzzer_set_period
        jmp end;

case02:
        mov #2, &state;
        mov #523, r12
        call #buzzer_set_period
        jmp end

case03:
        mov #3, &state;
        mov #500, r12
        call #buzzer_set_period ; //D
        jmp end

case04:
        mov #4, &state;
        mov #450, r12
        call #buzzer_set_period; //E
        jmp end
        
case05:
        mov #5, &state;
        mov #450, r12
        call #buzzer_set_period ; //E
        jmp end;

case06:
        mov #6, &state;
        mov #500, r12
        call #buzzer_set_period; //D
        jmp end;
        
case07:
        mov #7, &state;
        mov #523, r12
        call #buzzer_set_period; //C
        jmp end;
case08:
        mov #8, &state;
        mov #600, r12
        call #buzzer_set_period ; //B
        jmp end;

case09:
        mov #9, &state;
        mov #650, r12
        call #buzzer_set_period ; //A
        jmp end;
case10:
        mov #10, &state;
        mov #650, r12
        call #buzzer_set_period; //A
        jmp end
case11:
        mov #11, &state;
        mov #600, r12
        call #buzzer_set_period ; //B
        jmp end;
case12:
        mov #12, &state;
        mov #523, r12
        call #buzzer_set_period; //c
        jmp end;
case13:
        mov #13, &state;
        mov #600, r12
        call #buzzer_set_period; //B
        jmp end;
case14:
        mov #14, &state;
        mov #600, r12
        call #buzzer_set_period;
        jmp end;
case15:
        mov #15, &state;
        mov #0, r12
        call #buzzer_set_period;
        call #buzzer_init;
        jmp end;
default:
        mov #200, r12
        call #buzzer_set_period;
        call #buzzer_init
       
        mov #0, &state;
end: 
        ret
