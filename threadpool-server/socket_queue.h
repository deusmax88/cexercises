#ifndef __SOCKET_QUEUE
#define __SOCKET_QUEUE

struct node {
    struct node * next;
    int * client_socket;
};

typedef struct node node_t;

void enqueue (int * client_socket);
int* dequeue();

#endif