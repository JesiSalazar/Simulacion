#include <stdio.h>
#include <stdlib.h>
#include "lcgrand.h"
#include "schlist.h"
#include "timevents.h"

#define INPUT_A 1
#define INPUT_B 2
#define OUTPUT_A 3
#define OUTPUT_B 4

#define ROW_A 20
#define ROW_B 30

#define MAXTIME 2000

int main(void){
    
    /*initialization*/
    scheduler *sch_head = NULL;
    scheduler *row_A = NULL;
    scheduler *row_B = NULL;
    
    /*we create the first input for each row and we put that events in the scheduler*/
    push(&sch_head, INPUT_A, inputcalc(0, ROW_A));
    push(&sch_head, INPUT_B, inputcalc(0, ROW_B));
    
    print_everything(&sch_head);
}
