// TODO 1. input a string from user
// TODO 2. reverse the string using stack

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct stack{
    node *head;
} stack;

stack *create_stack() {
    stack *s = malloc(sizeof(stack));
    s->head = NULL;
    return s;
}

void push(stack *s, int data) {
    node *n = malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    if (s->head == NULL) {
        s->head = n;
    } else {
        n->next = s->head;
        s->head = n;
    }
}

int pop(stack *s) {
    if (s->head == NULL) {
        return -1;
    }
    node *n = s->head;
    int data = n->data;
    s->head = n->next;
    free(n);
    return data;
}


int main(){

    stack *s = create_stack();

    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int i = 0;
    while (str[i] != '\0'){
        push(s, str[i]);
        i++;
    }

    i = 0;
    while (s->head != NULL){
        str[i] = pop(s);
        i++;
    }

    printf("Reversed string: %s", str);

    return 0;
}