/*Question: Write a C program code which uses stack data structure to convert 

A given infix expression to an equivalent postfix expression
And reverse the postfix expression 


Input structure:

Infix Expression as a string

Output structure:

Original infix expression
Equivalent postfix expression
Reversed postfix expression

Example:

Input:

(A-X)+(B*C)

Output:

(A-X)+(B*C)
AX-BC*+
+*CB-XA

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node{
  char data;
  struct node *next;
};

struct node *top = NULL;

void push (char value){
  struct node *new_node = (struct node *) malloc (sizeof (struct node));
  new_node->data = value;
  new_node->next = top;
  top = new_node;
}

char pop (){
  struct node *temp = top;
  char popped_value = temp->data;
  top = top->next;
  free (temp);
  return popped_value;
}

int is_empty (){
  return top == NULL;
}

char peek (){
  return top->data;
}

int precedence (char symbol){
  switch (symbol){
    case '^':
      return 3;
    case '*':
    case '/':
      return 2;
    case '+':
    case '-':
      return 1;
    default:
      return 0;
    }
}

void infix_to_postfix (char infix[], char postfix[], int infix_len){
  int i, j = 0;
  for (i = 0; i < infix_len; i++){
      if (isalpha (infix[i])){
	  postfix[j++] = infix[i];
	}
      else if (infix[i] == '('){
	  push (infix[i]);
	}
      else if (infix[i] == ')'){
	  while (!is_empty () && peek () != '('){
	      postfix[j++] = pop ();
	    }
	  pop ();
	}
      else{
	  while (!is_empty ()
		 && precedence (peek ()) >= precedence (infix[i])){
	      postfix[j++] = pop ();
	    }
	  push (infix[i]);
	}
    }
  while (!is_empty ()){
      postfix[j++] = pop ();
    }
  postfix[j] = '\0';
}

void reverse_postfix (char postfix[], int len){

  for (int i = 0; i < len; i++){
      push (postfix[i]);
    }

  int j = 0;
  while (top != NULL){
      postfix[j++] = pop ();
    }
  postfix[j] = '\0';
}


int main (){
  char infix[100], postfix[200];
  int infix_len, postfix_len;
  
  fgets (infix, 100, stdin);
  printf ("%s\n", infix);
  infix_len = strlen (infix);
  
  if (infix[infix_len - 1] == '\n'){
      infix[infix_len - 1] = '\0';
    }
    
  infix_to_postfix (infix, postfix, infix_len);
  printf ("%s\n", postfix);
  
  postfix_len = strlen (postfix);
  while (!is_empty ()){
      pop ();
    }
  reverse_postfix (postfix, postfix_len);
  printf ("%s\n", postfix);
  return 0;
}


