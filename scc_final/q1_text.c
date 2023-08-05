#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

struct Person {
    char name[MAX_NAME_LENGTH]; //pushcheck
    int num_complaints;
};

struct Node {
    struct Person person;
    struct Node* next;
};

struct Node* createPersonNode(const char* name) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->person.name, name);
    newNode->person.num_complaints = 0;
    newNode->next = NULL;
    return newNode;
}

struct Node* findPerson(struct Node* graph[], int num_people, const char* name) {
    for (int i = 0; i < num_people; i++) {
        if (strcmp(graph[i]->person.name, name) == 0) {
            return graph[i];
        }
    }
    return NULL;
}

void addEdge(struct Node* graph[], int num_people, const char* src_name, const char* dest_name) {
    struct Node* srcNode = findPerson(graph, num_people, src_name);
    struct Node* destNode = findPerson(graph, num_people, dest_name);

    if (srcNode == NULL || destNode == NULL) {
        printf("Error: Person not found in the graph.\n");
        return;
    }

    // Increment the number of complaints for the destination person
    destNode->person.num_complaints++;

    // Add an edge from source to destination
    struct Node* newNode = createPersonNode(destNode->person.name);
    newNode->next = srcNode->next;
    srcNode->next = newNode;
}

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
    int num_people = 5;
    struct Node* graph[num_people];

    graph[0] = createPersonNode("Alice");
    graph[1] = createPersonNode("Bob");
    graph[2] = createPersonNode("Charlie");
    graph[3] = createPersonNode("David");
    graph[4] = createPersonNode("Eve");

    addEdge(graph, num_people, "Alice", "Bob");
    addEdge(graph, num_people, "Bob", "Charlie");
    addEdge(graph, num_people, "Charlie", "Alice");
    addEdge(graph, num_people, "David", "Bob");
    addEdge(graph, num_people, "Eve", "Alice");

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
