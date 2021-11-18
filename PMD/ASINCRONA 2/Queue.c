#include "Queue.h"
#include "Types.h"

QUEUE queue_create() { //CREAMOS COLA

	QUEUE tmp=malloc(sizeof(struct STRQUEUE));
	tmp->first=NULL;
	tmp->last=NULL;
	tmp->size=0;
	return(tmp);
}

void queue_offer(QUEUE queue,TYPE data) { //AGREGAMOS A LA COLA 

	NODE new=malloc(sizeof(struct STRNODE));

	new->data=data;
	new->next=NULL;

	if(queue->first==NULL)
		queue->first=new;
	else
		queue->last->next=new; 

	queue->size++;
	queue->last=new;	
}

TYPE queue_poll(QUEUE queue) {

	NODE remove=queue->first;
	TYPE retdata=remove->data;

	queue->first=queue->first->next;
	queue->size--;
	free(remove);

	if(queue->first==NULL)
		queue->last=NULL;

	return(retdata);
}

int queue_size(QUEUE queue) {

	return(queue->size);
}

BOOL queue_isempty(QUEUE queue) {

	return(queue->first==NULL);
}

TYPE queue_peek(QUEUE queue) {

	return(queue->first->data);
}

void queue_destroy(QUEUE queue) {

	while(!queue_isempty(queue)) {
        
		queue_poll(queue);
	}
	free(queue);
}

