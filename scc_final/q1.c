#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the person's name
#define MAX_NAME_LENGTH 50

// Struct to represent a person with their name and number of complaints
struct Person {
    char name[MAX_NAME_LENGTH];
    int num_complaints;
};

// Struct to represent a node in the adjacency list
struct Node {
    struct Person person;
    struct Node* next;
};

// Function to create a new person node
struct Node* createPersonNode(const char* name) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->person.name, name);
    newNode->person.num_complaints = 0;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge between two nodes in the graph
void addEdge(struct Node* graph[], int src, int dest) {
    struct Node* newNode = createPersonNode(graph[dest]->person.name);
    newNode->next = graph[src]->next;
    graph[src]->next = newNode;
}

// Function to print the graph and its edges
void printGraph(struct Node* graph[], int num_people) {
    for (int i = 0; i < num_people; i++) {
        printf("Person: %s, Complaints: %d, Complaints Against: ", graph[i]->person.name, graph[i]->person.num_complaints);

        struct Node* current = graph[i]->next;
        while (current != NULL) {
            printf("%s ", current->person.name);
            current = current->next;
        }

        printf("\n");
    }
}

int main() {
    // Define the number of people in the graph
    int num_people = 5;

    // Create an array to store the graph nodes
    struct Node* graph[num_people];

    // Create the persons and add them to the graph
    graph[0] = createPersonNode("Alice");
    graph[1] = createPersonNode("Bob");
    graph[2] = createPersonNode("Charlie");
    graph[3] = createPersonNode("David");
    graph[4] = createPersonNode("Eve");

    // Add edges between persons based on complaints (Example connections)
    addEdge(graph, 0, 1); // Alice has a complaint against Bob
    addEdge(graph, 1, 2); // Bob has a complaint against Charlie
    addEdge(graph, 2, 0); // Charlie has a complaint against Alice
    addEdge(graph, 3, 1); // David has a complaint against Bob
    addEdge(graph, 4, 0); // Eve has a complaint against Alice

    // Print the graph
    printGraph(graph, num_people);

    // Free the memory
    for (int i = 0; i < num_people; i++) {
        struct Node* current = graph[i];
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    return 0;
}
