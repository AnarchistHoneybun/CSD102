/*Question: Write a C code to add two polynomials using a linked list. 

Note: Do not print anything other than what's asked in the question.

Input:

Polynomial 1
Polynomial 2

Output:

Polynomial 3

Example:

Input:

5x^2 - 2x^1 + 4x^0
2x^2 + 7x^1 + 4x^0

Output:

7x^2 + 5x^1 + 8x^0*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sign constants

#define POS 1
#define NEG -1

// Node structure containing coefficient and exponent of a term
// and a pointer to the next node

struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

// Function to create a new node
// with given coefficient and exponent
// and return the pointer to the new node
// (Note that the next pointer is initialized to NULL)

struct Node* createNode(int coefficient, int exponent) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node in a sorted list
// in decreasing order of exponent
// and return the head of the list
// (Note that the head may change after insertion)

struct Node* insertSorted(struct Node* head, struct Node* newNode) {
    if (head == NULL) {
        return newNode;
    }
    if (newNode->exponent > head->exponent) {
        newNode->next = head;
        return newNode;
    }
    head->next = insertSorted(head->next, newNode);
    return head;
}

void addSimilarTerms(struct Node* head){
    struct Node* temp = head;
    struct Node* temp2 = head->next;
    while(temp2!=NULL){
        if(temp->exponent==temp2->exponent){
            temp->coefficient+=temp2->coefficient;
            temp->next=temp2->next;
            free(temp2);
            temp2=temp->next;
        }else{
            temp=temp->next;
            temp2=temp2->next;
        }
    }
}

// Function to add two polynomials
// and return the head of the result
// (Note that the head may change after addition)
// (Note that the polynomials are sorted in decreasing order of exponent)
// (Note that the result polynomial is also sorted in decreasing order of exponent)

struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    while (poly1 && poly2) {
        if (poly1->exponent > poly2->exponent) {
            result = insertSorted(result, createNode(poly1->coefficient, poly1->exponent));
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            result = insertSorted(result, createNode(poly2->coefficient, poly2->exponent));
            poly2 = poly2->next;
        } else {
            int coefficient = poly1->coefficient + poly2->coefficient;
            if (coefficient != 0) {
                result = insertSorted(result, createNode(coefficient, poly1->exponent));
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1) {
        result = insertSorted(result, createNode(poly1->coefficient, poly1->exponent));
        poly1 = poly1->next;
    }
    while (poly2) {
        result = insertSorted(result, createNode(poly2->coefficient, poly2->exponent));
        poly2 = poly2->next;
    }
    return result;
}

// Function to print a polynomial
// (Note that the polynomial is sorted in decreasing order of exponent)
// (Note that the polynomial is printed in the format: ax^b + cx^d + ...)

void printPolynomial(struct Node* head) {
    while (head) {
        if(head->coefficient>=0){
            printf("%dx^%d ", head->coefficient, head->exponent);
        }else if(head->coefficient<0){
            printf("- %dx^%d ", head->coefficient*-1, head->exponent);
        }
        head = head->next;
        if (head == NULL){
            break;
        }
        if (head->coefficient>=0) {
            printf("+ ");
        }
    }
    printf("\n");
}

// Function to remove the first character from a string
// to handle cases where the first term is -ve
void removeFirstChar(char *str){
    int i;
    for(i=0; i<strlen(str); i++){
        str[i]=str[i+1];
    }
}


// Main function
// (Note that the polynomial is input in the format: ax^b + cx^d + ...)
// (Note that the polynomial is stored in a string)
// (Note that the polynomial is extracted from the string and stored in a linked list)

int main() {
    char poly1[100];
    fgets(poly1, sizeof(poly1), stdin);
    struct Node* poly1List = NULL;

    int coefficient, exponent, sign;
    sign = POS;
    
    // Extracting terms from polynomial 1
    // (Note that the polynomial is extracted using sscanf)

    char *str = poly1;

    //it checks if the first character is a - and if it is it sets the sign to negative
    //and removes the - from the string

    if(str[0]=='-'){
        sign = NEG;
        removeFirstChar(str);
    }
    while (sscanf(str, "%dx^%d", &coefficient, &exponent) == 2) {
        poly1List = insertSorted(poly1List, createNode(coefficient*sign, exponent));

        //it checks if there is a + and a - in the string
        //if there is a + and a - it checks which one comes first
        //if there is only a + or a - it checks which one it is
        //if there is neither it breaks the loop
        //it then sets the sign and the string to the next character after the + or -

        if(strchr(str, '+')!=NULL && strchr(str, '-')!=NULL){
            if(strchr(str, '+')<strchr(str, '-')){
                str = strchr(str, '+');
                sign = POS;
            }else{
                str = strchr(str, '-');
                sign = NEG;
            }
        }else if(strchr(str, '+')==NULL && strchr(str, '-')==NULL){
            str = NULL;
        }else{
            sign=(strchr(str, '+')>strchr(str, '-'))?POS:NEG;
            str=(strchr(str, '+')>strchr(str, '-'))?strchr(str, '+'):strchr(str, '-');
        }
        if (str == NULL) {
            break;
        }
        str++;
    }

    addSimilarTerms(poly1List);    
    
    char poly2[100];
    fgets(poly2, sizeof(poly2), stdin);
    struct Node* poly2List = NULL;
    
    sign = POS;
    
    // Extracting terms from polynomial 2

    str = poly2;
    if(str[0]=='-'){
        sign = NEG;
        removeFirstChar(str);
    }
    while (sscanf(str, "%dx^%d", &coefficient, &exponent) == 2) {
        poly2List = insertSorted(poly2List, createNode(coefficient*sign, exponent));
        if(strchr(str, '+')!=NULL && strchr(str, '-')!=NULL){
            if(strchr(str, '+')<strchr(str, '-')){
                str = strchr(str, '+');
                sign = POS;
            }else{
                str = strchr(str, '-');
                sign = NEG;
            }
        }else if(strchr(str, '+')==NULL && strchr(str, '-')==NULL){
            str = NULL;
        }else{
            sign=(strchr(str, '+')>strchr(str, '-'))?POS:NEG;
            str=(strchr(str, '+')>strchr(str, '-'))?strchr(str, '+'):strchr(str, '-');
        }
        if (str == NULL) {
            break;
        }
        str++;
    }
    
    addSimilarTerms(poly2List);
    
    // Adding polynomials

    struct Node* result = addPolynomials(poly1List, poly2List);
    printPolynomial(result);

    return 0;
}
