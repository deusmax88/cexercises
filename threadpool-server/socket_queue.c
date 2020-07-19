#include "socket_queue.h"
#include <stdlib.h>

node_t * tail = NULL;
node_t * head = NULL;

void enqueue (int *client_socket) {
    node_t *newnode = malloc(sizeof(node_t));
    newnode->client_socket = client_socket;
    newnode->next = NULL;
    if (tail == NULL) {
        head = newnode;
    }
    else {
        tail->next = newnode;
    }

    tail = newnode;
}

int* dequeue() {
    if (head == NULL) {
        return NULL;
    }

    int* result = head->client_socket;
    node_t * tmp = head;
    head = head->next;
    if (head == NULL) {
        tail = NULL;
    } 
    free(tmp);

    return result;
}