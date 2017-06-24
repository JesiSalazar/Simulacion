//
//  files.c
//  
//
//  Created by Jesenia Salazar on 23-06-17.
//
//

#define INPUT_A 1
#define INPUT_B 2
#define OUTPUT_A 3
#define OUTPUT_B 4

#include <stdio.h>
#include <stdlib.h>
#include "schlist.h"

FILE *logfile = NULL;

void initfile(void){
    logfile = fopen("datos_simulador.txt", "w+");
    if(logfile == NULL){
        printf("ha fallado la creación del archivo");
    }else{
        fprintf(logfile, "INICIO: \n");
    }
}

void log_update(float time, scheduler **sch_head, scheduler **row_A, scheduler **row_B){
    
    if (logfile != NULL){
        fprintf(logfile, "TIEMPO ACTUAL: \t %f \n", time);
        fprintf(logfile, "SCHEDULER: \t %f \n", time);
        
        /*scheduler data*/
        scheduler *aux = *sch_head;
        int i = 0;
        while (aux != NULL){
            i++;
            switch (aux->type) {
                case INPUT_A:
                    fprintf(logfile, "Nº: %d \t Tipo: INPUT A \t Tiempo %f \t Entrada %d \n", i, aux->time, aux->number);
                    aux = aux->next;
                    continue;
                case INPUT_B:
                    fprintf(logfile, "Nº: %d \t Tipo: INPUT B \t Tiempo %f \t Entrada %d \n", i, aux->time, aux->number);
                    aux = aux->next;
                    continue;
                case OUTPUT_A:
                    fprintf(logfile, "Nº: %d \t Tipo: OUTPUT A \t Tiempo %f \t Entrada %d \n", i, aux->time, aux->number);
                    aux = aux->next;
                    continue;
                case OUTPUT_B:
                    fprintf(logfile, "Nº: %d \t Tipo: OUTPUT B \t Tiempo %f \t Entrada %d \n", i, aux->time, aux->number);
                    aux = aux->next;
                    continue;
                default:
                    break;
            }
        }
        /*row A data*/
        fprintf(logfile, "FILA A: \t %f \n", time);
        aux = *row_A;
        i = 0;
        while (aux != NULL){
            i++;
            switch (aux->type) {
                case INPUT_A:
                    fprintf(logfile, "Nº: %d \t Tipo: INPUT A \t Tiempo %f \t Entrada %d \n", i, aux->time, aux->number);
                    aux = aux->next;
                    continue;
                default:
                    break;
            }
        }
        
        /*row B data*/
        fprintf(logfile, "FILA B: \t %f \n", time);
        aux = *row_B;
        i = 0;
        while (aux != NULL){
            i++;
            switch (aux->type) {
                case INPUT_B:
                    fprintf(logfile, "Nº: %d \t Tipo: INPUT B \t Tiempo %f \t Entrada %d \n", i, aux->time, aux->number);
                    aux = aux->next;
                    continue;
                default:
                    break;
            }
        }
        fprintf(logfile,"TÉRMINO DE ITERACION\n");
    }
}
