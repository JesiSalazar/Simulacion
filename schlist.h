typedef struct node{
	int type;
	float time;
	struct node *next;
} scheduler;

void push(scheduler **sch_head, int type, float time);
scheduler *pop(scheduler **sch_head);