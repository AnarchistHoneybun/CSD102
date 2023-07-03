//todo wite a c function that given the pointer to a head node of a linked list, a value, and a position, 
// inserts a new node with the given value at the given position in the list.

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    struct Node* next;
}Node;

//todo write a function that return the data in the nts node from the tail of a linked list

int getNode(Node* head, int positionFromTail) {
    Node *temp = head;
    int count = 0;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    temp = head;
    for(int i=0;i<count-positionFromTail-1;i++)
    {
        temp = temp->next;
    }
    return temp->data;
}

Node *insert(Node *head, int data, int position)
{
    Node *temp = malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if(position == 0)
    {
        temp->next = head;
        head = temp;
        return head;
    }
    Node *temp1 = head;
    for(int i=0;i<position-1;i++)
    {
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
    return head;
}

int main(){

    Node* head = malloc(sizeof(Node));

    head->data = 1;
    head->next = NULL;

    //insert some random data into list

    for(int i = 0; i < 10; i++){
        Node* temp = malloc(sizeof(Node));
        temp->data = i;
        temp->next = head;
        head = temp;
    }

    //print linked list
    Node* temp = head;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    return 0;
}