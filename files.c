//
//  files.c
//  
//
//  Created by Jesenia Salazar on 23-06-17.
//
//

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
