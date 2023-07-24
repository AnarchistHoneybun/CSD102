#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Trie node definition
struct TrieNode {
    struct TrieNode* children[26]; // Assuming input strings contain only lowercase English letters
    bool isEndOfWord;
};

// Function to create a new TrieNode
struct TrieNode* createNode() {
    struct TrieNode* newNode = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    for (int i = 0; i < 26; i++) {
        newNode->children[i] = NULL;
    }
    newNode->isEndOfWord = false;
    return newNode;
}

// Function to insert a string into the trie
void insert(struct TrieNode* root, const char* str) {
    for (int i = 0; str[i]; i++) {
        int index = str[i] - 'a'; // Convert character to index (assuming lowercase letters)
        if (!root->children[index]) {
            root->children[index] = createNode();
        }
        root = root->children[index];
    }
    root->isEndOfWord = true;
}

// Function to check if string `m` is a subset of string `N`
bool isSubset(const char* m, const char* N) {
    struct TrieNode* root = createNode();

    // Construct the trie using characters from string `N`
    insert(root, N);

    // Traverse the trie using characters from string `m`
    for (int i = 0; m[i]; i++) {
        int index = m[i] - 'a'; // Convert character to index (assuming lowercase letters)
        if (!root->children[index]) {
            return false; // `m` is not a subset of `N`
        }
        root = root->children[index];
    }

    return true; // If we reached the end of `m`, it is a subset of `N`.
}

// Function to deallocate memory of the trie
void destroyTrie(struct TrieNode* node) {
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < 26; i++) {
        destroyTrie(node->children[i]);
    }
    free(node);
}

int main() {
    const char* N = "abcdefghijklmnopqrstuvwxyz";
    const char* m1 = "abc";
    const char* m2 = "def";
    const char* m3 = "hello";

    // if (isSubset(m1, N)) {
    //     printf("%s is a subset of %s.\n", m1, N);
    // } else {
    //     printf("%s is NOT a subset of %s.\n", m1, N);
    // }

    if (isSubset(m2, N)) {
        printf("%s is a subset of %s.\n", m2, N);
    } else {
        printf("%s is NOT a subset of %s.\n", m2, N);
    }

    if (isSubset(m3, N)) {
        printf("%s is a subset of %s.\n", m3, N);
    } else {
        printf("%s is NOT a subset of %s.\n", m3, N);
    }

    // Clean up the trie
    //destroyTrie(root);

    return 0;
}
