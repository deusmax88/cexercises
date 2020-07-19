typedef struct node{
    int val;
    struct node * next;
} node_t;

typedef struct queue{
    node_t * head;
    node_t * tail;
} queue_t;

void init_queue(queue_t * q) {
    q->head = NULL;
    q->tail = NULL;
}

int enqueue(queue_t *q, int val) {
    node_t * newnode = (node_t *)malloc(sizeof(node_t));
    if (newnode == NULL) return 0;
    
    newnode->val = val;
    newnode->next = NULL;
    if (q->tail != NULL) {
        q->tail->next = newnode;
    }
    q->tail = newnode;
    if (q->head == NULL) {
        q->head = newnode;
    }

    return 1;
}

int dequeue(queue_t * q) {
    if (q->head == NULL) return INT_MIN;
    node_t *tmp = q->head;
    int result = tmp->val;
    q->head = q->head->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    free(tmp);
    return result;
}    