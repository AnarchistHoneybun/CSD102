// // TODO 1. make a linked list
// // TODO 2. add 3 nodes to the list
// // TODO 3. print the list

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main(void) {
    struct node *head = NULL;
    struct node *second = NULL;
    struct node *third = NULL;

    head = malloc(sizeof(struct node));
    second = malloc(sizeof(struct node));
    third = malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    struct node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
        printf("\n");
    }

    return 0;
}