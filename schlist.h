typedef struct node{
	int number;
	int type;
	float time;
	struct node *next;
} scheduler;

void push(scheduler **sch_head, int type, float time, int number);
scheduler *pop(scheduler **sch_head);
