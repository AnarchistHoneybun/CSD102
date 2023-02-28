/*

Question: Given a queue and two integers k and p, take k integers starting 
from pth element and use another queue to reverse it. Finally append this reversed
queue to the end of the original queue.

NOTE: Every element in the original queue is distinct. Indexing starts from 1.

Input:

Size N
Queue of N integers
p k

Output:

Queue of N+k integers with the required reverse and append operations done.

Example:

Input:

7
45 32 76 34 23 89 67
3 4

Output:

45 32 76 34 23 89 67 89 23 34 76

*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void enqueue(struct Queue* queue, int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = new_node;
        return;
    }

    queue->rear->next = new_node;
    queue->rear = new_node;
}

void print_queue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* current_node = queue->front;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

void extract_p_terms(struct Queue* queue1, struct Queue* queue2, int p, int k) {
    // Move the front pointer of queue1 to the kth node
    struct Node* current_node = queue1->front;
    for (int i = 1; i < k; i++) {
        current_node = current_node->next;
    }

    // Add the next p nodes to queue2
    for (int i = 0; i < p && current_node != NULL; i++) {
        enqueue(queue2, current_node->data);
        current_node = current_node->next;
    }
}

void reverse_queue(struct Queue* queue) {
    struct Node *prev_node, *current_node, *next_node;
    prev_node = NULL;
    current_node = queue->front;

    while (current_node != NULL) {
        next_node = current_node->next;
        current_node->next = prev_node;
        prev_node = current_node;
        current_node = next_node;
    }

    queue->front = prev_node;
    if (queue->rear == NULL) {
        queue->rear = queue->front;
    }
}

void append_queue(struct Queue* queue1, struct Queue* queue2) {
    if (queue1->rear == NULL) {
        queue1->front = queue2->front;
        queue1->rear = queue2->rear;
    } else {
        queue1->rear->next = queue2->front;
        queue1->rear = queue2->rear;
    }
}

int main() {
    struct Queue queue1;
    queue1.front = queue1.rear = NULL;

    struct Queue queue2;
    queue2.front = queue2.rear = NULL;

    int n, p, k, value;
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        
        scanf("%d", &value);
        enqueue(&queue1, value);
    }

    scanf("%d %d", &k, &p);

    extract_p_terms(&queue1, &queue2, p, k);
    
    reverse_queue(&queue2);

    append_queue(&queue1, &queue2);

    print_queue(&queue1);
    
    return 0;
}
