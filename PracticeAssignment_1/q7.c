#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int top;
    char items[MAX_STACK_SIZE];
} Stack;

void push(Stack* stack, char item) {
    if (stack->top >= MAX_STACK_SIZE) {
        printf("Error: stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = item;
}

char pop(Stack* stack) {
    if (stack->top < 0) {
        printf("Error: stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

int is_empty(Stack* stack) {
    return stack->top < 0;
}

int is_matching(char left, char right) {
    return (left == '(' && right == ')');
}

int is_balanced(char* str) {
    int len = strlen(str);
    Stack stack = {-1, {0}};

    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (c == '(') {
            push(&stack, c);
        } else if (c == ')') {
            if (is_empty(&stack)) {
                return 0;
            } else if (!is_matching(pop(&stack), c)) {
                return 0;
            }
        }
    }
    return is_empty(&stack);
}

int main() {
    char str[100];
    printf("Enter a string of parentheses: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0; // remove newline character from input

    if (is_balanced(str)) {
        printf("Parentheses are balanced.\n");
    } else {
        printf("Parentheses are not balanced.\n");
    }

    return 0;
}
