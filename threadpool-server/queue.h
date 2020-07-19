#ifndef __QUEUE_
#define __QUEUE_

typedef struct queue queue_t;

void init_queue(queue_t * q);
int enqueue(queue_t *q, int val);
int dequeue(queue_t * q);

#endif