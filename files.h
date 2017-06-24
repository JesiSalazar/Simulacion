//
//  files.h
//  
//
//  Created by Jesenia Salazar on 23-06-17.
//
//

#ifndef files_h
#define files_h

#define INPUT_A 1
#define INPUT_B 2
#define OUTPUT_A 3
#define OUTPUT_B 4

#include <stdio.h>

void initfile(void);
void log_update(float time, scheduler **sch_head, scheduler **row_A, scheduler **row_B);

#endif /* files_h */
