#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lcgrand.h"

#define INPUT_A 1
#define INPUT_B 2
#define OUTPUT_A 3
#define OUTPUT_B 4

#define ROW_A 20
#define ROW_B 30

#define MAXTIME 2000

/*inputcalc calculate the time of the next arrival of the type */

float inputcalc(float currentime, int row){
	float rand = lcgrand(row);
	int lambda;
	if(row == ROW_A){
		lambda = 3;
	}
	else{
		lambda = 2;
	}
	float time = -lambda*log(rand);
	return currentime + time;
}

/*attention calculate the time of the output of the type */

float attention(float currentime, int row){
	float rand = lcgrand(2*row);
	float lambda;
	if(row == ROW_A){
		lambda = 4;
	}
	else{
		lambda = 3.5;
	}
	float time = -lambda*log(rand);
	return currentime + time;
}
