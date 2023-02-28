// TODO 1. make a doubly linked list
// TODO 2. make a function to add nodes to the list (add_node)
// // ! add the nodes in a sorted manner
// TODO 3. make a function to search for a node in the list (search_node)
// TODO 4. make a function to print the list (print_list)

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void add_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

void print_list() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int search_node(int data) {
    struct node *temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    add_node(10);
    add_node(450);
    add_node(30);
    add_node(40);
    add_node(50);
    add_node(60);
    add_node(70);
    add_node(80);
    add_node(90);
    add_node(100);

    // print_list();

    printf("Enter number to find: ");
    int num;
    scanf("%d", &num);
    search_node(num) ? printf("Found") : printf("Not found");

    return 0;
}