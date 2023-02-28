// TODO 1. create a queue
// TODO 2. add 3 elements, one by one
// TODO 3. remove 1 element
// TODO 4. print queue at every step

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct queue {
    node *head;
    node *tail;
} queue;

queue *create_queue() {
    queue *q = malloc(sizeof(queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void enqueue(queue *q, int data) {
    node *n = malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    if (q->head == NULL) {
        q->head = n;
        q->tail = n;
    } else {
        q->tail->next = n;
        q->tail = n;
    }
}

int dequeue(queue *q) {
    if (q->head == NULL) {
        return -1;
    }
    node *n = q->head;
    int data = n->data;
    q->head = n->next;
    free(n);
    return data;
}

void print_queue(queue *q) {
    node *n = q->head;
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}

int main() {
    queue *q = create_queue();
    print_queue(q);
    enqueue(q, 1);
    print_queue(q);
    enqueue(q, 2);
    print_queue(q);
    enqueue(q, 3);
    print_queue(q);
    dequeue(q);
    print_queue(q);
    return 0;
}
