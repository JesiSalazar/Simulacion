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

#define BUSY 1
#define FREE 0

#define MAXTIME 2000

int main(void){
    
    /*initialization*/
    scheduler *sch_head = NULL;
    scheduler *row_A = NULL;
    scheduler *row_B = NULL;
    scheduler *attending = NULL;
    
    int state_procA = FREE;
    int state_procB = FREE;
    
    float time = 0;
    
    /*we create the first input for each row and we put that events in the scheduler*/
    push(&sch_head, INPUT_A, inputcalc(0, ROW_A));
    push(&sch_head, INPUT_B, inputcalc(0, ROW_B));
    
    print_everything(&sch_head);
    
    while (time < MAXTIME) {
        attending = pop(&sch_head);
        time = attending->time;
        
        print_everything(&sch_head);
        
        switch (attending->type){
            case INPUT_A:
                printf("estoy en caso input A\n");
                push(&sch_head, INPUT_A, inputcalc(time, ROW_A));
                if(row_A == NULL && state_procA == FREE){
                    state_procA = BUSY;
                    push(&sch_head, OUTPUT_A, attention(time, ROW_A));
                    free(attending);
                }else{
                    push(&row_A, INPUT_A, attending->time);
                    free(attending);
                }
                continue;
            case INPUT_B:
                printf("estoy en caso input B\n");
                push(&sch_head, INPUT_B, inputcalc(time, ROW_B));
                printf("hice el push de B");
                if(row_B == NULL && state_procB == FREE){
                    state_procB = BUSY;
                    push(&sch_head, OUTPUT_B, attention(time, ROW_B));
                    free(attending);
                    printf("no hay fila en B");
                }else{
                    push(&row_B, INPUT_B, attending->time);
                    free(attending);
                    printf("hay fila en B el input debe esperar en la fila");
                }
                continue;
            case OUTPUT_A:
                printf("estoy en caso output A\n");
                state_procA = FREE;
                if (row_A == NULL) {
                    free(attending);
                }else{
                    free(attending);
                    attending = pop(&row_A);
                    push(&sch_head, OUTPUT_A, attention(time, ROW_A));
                    free(attending);
                }
                continue;
            case OUTPUT_B:
                printf("estoy en caso output B\n");
                state_procB = FREE;
                if (row_B == NULL) {
                    free(attending);
                }else{
                    free(attending);
                    attending = pop(&row_B);
                    push(&sch_head, OUTPUT_B, attention(time, ROW_B));
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
