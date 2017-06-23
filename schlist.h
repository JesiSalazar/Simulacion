typedef struct node{
	int number;
	int type;
	float time;
	struct node *next;
} scheduler;

void push(scheduler **sch_head, int type, float time, int number);
void print_everything(scheduler **sch_head);
scheduler *pop(scheduler **sch_head);
