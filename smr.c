#include <stdio.h>
#include <stdlib.h>
#include "lcgrand.h"
#include "schlist.h"
#include "timevents.h"
#include "files.h"

#define INPUT_A 1
#define INPUT_B 2
#define OUTPUT_A 3
#define OUTPUT_B 4

#define ROW_A 20
#define ROW_B 30

#define BUSY 1
#define FREE 0

#define MAXTIME 200

int main(void){
    
    /*initialization*/
    scheduler *sch_head = NULL;
    scheduler *row_A = NULL;
    scheduler *row_B = NULL;
    scheduler *attending = NULL;
    
    int state_procA = FREE;
    int state_procB = FREE;
    
    float time = 0;
    int number = 0;
    
    /*we create the first input for each row and we put that events in the scheduler*/
    push(&sch_head, INPUT_A, inputcalc(0, ROW_A), 1);
    push(&sch_head, INPUT_B, inputcalc(0, ROW_B), 1);
    
    initfile();
    //log_update(time, &sch_head, &row_A, &row_B);
    
    while (time < MAXTIME) {
        log_update(time, &sch_head, &row_A, &row_B);
        attending = pop(&sch_head);
        time = attending->time;
        printf("CURRENT TIME: %f \n", time);
        //log_update(time, &sch_head, &row_A, &row_B);
        
        switch (attending->type){
            case INPUT_A:
                number = attending->number + 1;
                push(&sch_head, INPUT_A, inputcalc(time, ROW_A), number);
                if(row_A == NULL && state_procA == FREE){
                    state_procA = BUSY;
                    push(&sch_head, OUTPUT_A, attention(time, ROW_A), attending->number);
                    free(attending);
                }else{
                    push(&row_A, INPUT_A, attending->time, attending->number);
                    free(attending);
                }
                continue;
            case INPUT_B:
                number = attending->number + 1;
                push(&sch_head, INPUT_B, inputcalc(time, ROW_B), number);
                if(row_B == NULL && state_procB == FREE){
                    state_procB = BUSY;
                    push(&sch_head, OUTPUT_B, attention(time, ROW_B), attending->number);
                    free(attending);
                }else{
                    push(&row_B, INPUT_B, attending->time, attending->number);
                    free(attending);
                }
                continue;
            case OUTPUT_A:
                state_procA = FREE;
                if (row_A == NULL) {
                    free(attending);
                }else{
                    free(attending);
                    attending = pop(&row_A);
                    push(&sch_head, OUTPUT_A, attention(time, ROW_A), attending->number);
                    free(attending);
                }
                continue;
            case OUTPUT_B:
                state_procB = FREE;
                if (row_B == NULL) {
                    free(attending);
                }else{
                    free(attending);
                    attending = pop(&row_B);
                    push(&sch_head, OUTPUT_B, attention(time, ROW_B), attending->number);
                    free(attending);
                    state_procB = BUSY;
                }
                continue;
            default:
                printf("algo salio mal \n");
                break;
        }
    }
}
