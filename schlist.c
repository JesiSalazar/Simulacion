#include <stdio.h>
#include <stdlib.h>

#define INPUT_A 1
#define INPUT_B 2
#define OUTPUT_A 3
#define OUTPUT_B 4

#define ROW_A 20
#define ROW_B 30

#define MAXTIME 2000

typedef struct node{
	int type;
	float time;
	struct node *next;
} scheduler;



/*add a new event to the scheduler*/

void push(scheduler **sch_head, int type, float time){

	int flag = 0;
	
	/* Create the node that'll corresponding to the most recent
	event (the last one that was calculated)*/ 

	scheduler *new_event = malloc(sizeof(scheduler));
	new_event->type = type;
	new_event->time = time;

	/*locate the new node where it's belongs considerating the time*/

	scheduler *aux = *sch_head;
	scheduler *pointer = NULL;

	if(aux == NULL){
		new_event->next = *sch_head;
		*sch_head = new_event;
	}else{
		while(aux != NULL){
			if(new_event->time > aux->time){
				pointer = aux;
				aux = aux->next;
                printf("estoy buscando mi lugar\n");
			}
			else{
				pointer->next = new_event;
				new_event->next = aux;
				flag = 1;
                printf("ya encontre mi lugar\n");
                aux = NULL;
			}
		}

		/*if the new node is the last node I link it now to the end of the list */
		if(flag == 0){
			pointer->next = new_event;
			new_event->next = aux;
		}
	}
}


void print_everything(scheduler **sch_head){
    scheduler *aux = *sch_head;
    int i = 0;
    while (aux != NULL){
        i++;
        printf("estoy imprimiendo el elemento %d del scheduler, del tipo %d y con tiempo %f\n", i, aux->type, aux->time);
        aux = aux->next;
    }
}


/*get the nearest event to be processed*/



scheduler *pop(scheduler **sch_head){

	/*if the list is empty return NULL otherwise pop and return the first element
	of the list*/
	scheduler *current = *sch_head;
	
	if (current != NULL)
	{
		*sch_head = (*sch_head)->next;
	}
	return current;
}




