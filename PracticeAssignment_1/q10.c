#include <stdio.h>
#include <stdlib.h>

// Define the node structure for the doubly linked list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new node with the given data
Node* create_node(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

// Function to print the elements of the doubly linked list
void print_list(Node* head) {
    printf("List: ");
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to swap every alternate pair in a doubly linked list
void swap_pairs(Node* head) {
    Node* current = head;
    while (current != NULL && current->next != NULL) {
        // Swap the data of current node and next node
        int temp = current->data;
        current->data = current->next->data;
        current->next->data = temp;

        // Move to the next alternate pair
        current = current->next->next;
    }
}

int main() {
    // Create a sample doubly linked list
    Node* head = create_node(1);
    head->next = create_node(2);
    head->next->prev = head;
    head->next->next = create_node(3);
    head->next->next->prev = head->next;
    head->next->next->next = create_node(4);
    head->next->next->next->prev = head->next->next;

    // Print the original list
    print_list(head);

    // Swap every alternate pair
    swap_pairs(head);

    // Print the modified list
    print_list(head);

    return 0;
}
