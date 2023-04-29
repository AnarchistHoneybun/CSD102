/*
Question: You have been tasked with implementing a hash table using open addressing
and double hashing to store many integers. The hash function to be used is the modulo
division method, where the hash value of an integer key is obtained by computing key
% M, where M is the size of the hash table.

To avoid clustering and improve the distribution of keys, you will use double hashing
as the collision resolution method. The second hash function will be computed as
R - (key % R), where R is a prime number smaller than M.

You are required to implement the following functions:

    hash_table_create(int size, int prime) - This function takes an integer argument
    size and a prime number argument prime and creates a new hash table of size size.
    The function should return a pointer to the newly created hash table.

    hash_table_insert(int key, int value, int *collisions) - This function takes an integer
    argument key, an integer argument value, and a pointer to an integer collisions. It
    inserts a key-value pair into the hash table. The corresponding value should be updated
    if the key already exists in the hash table. If a collision occurs during insertion, the
    function should use double hashing to find the next available slot. The number of collisions
    encountered during insertion should be stored in the integer pointed to by collisions.

    hash_table_search(int key, int *collisions) - This function takes an integer argument key
    and a pointer to an integer collisions. It searches for the key in the hash table and
    returns the corresponding value if it is found, or -1 otherwise. The number of collisions
    encountered during the search should be stored in the integer pointed to by collisions.

    hash_table_delete(int key, int *collisions) - This function takes an integer argument key
    and a pointer to an integer collisions. It deletes the key-value pair corresponding to the
    key from the hash table. If the key is not found, the function should return -1. The
    number of collisions encountered during deletion should be stored in the integer pointed
    to by collisions.


    Input Format:

    S SIZE_OF_TABLE
    R VALUE_OF_R
    I INSERT_KEY_VALUE INSERT_VALUE
    S SEARCH_KEY_VALYE
    D DELETE_KEY_VALUE


    Output:

    Numbers of collisions for Search, Delete and Insert

    For example, if the input given to the program is

    S 7 // Size of the hash table
    R 3 // Value of the prime
    I 1 10 // Inserting key 1 with its value equal to 10
    I 8 12
    I 15 34
    S 8 // Searching the value of key 8
    S 15
    S 22
    S 29
    S 43

    The output should look like this:

    0 // Number of collisions when inserting 10 with key value 1
    1 
    1
    12 1 // In case of a search operation, we print the corresponding value followed by the number of collisions
    34 1
    -1 1 // If no such key exists, then we print -1 followed by the number of collisions
    -1 2
    -1 1
*/

//todo implement a hash table using oppen addressing and double hashing
// first hash function is key mod table size
// second hash function is R - (key mod R) where R is a prime number less than table size

#include <stdio.h>
#include <stdlib.h>

//defining an entry for the hash table
typedef struct {
    int key;
    int value;
}entry;

//defining the hash table
typedef struct {
    int size;
    int prime;
    entry *table;
} hash_table;

// first hash function
int hash(int key, int size){
    return key % size;
}

// second hash function
int hash2(int key, int size, int prime){
    return prime - (key % prime);
}

//function to create a hash table
hash_table *hash_table_create(int size, int prime){

    hash_table *ht = malloc(sizeof(hash_table));
    ht->size = size;
    ht->prime = prime;
    ht->table = malloc(sizeof(entry) * size);

    for (int i = 0; i < size; i++){
        ht->table[i].key = -1;
        ht->table[i].value = -1;
    }

    for(int i = 0; i < size; i++){
        //>printf("DEBUG-> key: %d, value: %d\n", ht->table[i].key, ht->table[i].value);
    }

    return ht;

}


//function to insert an entry into the hash table
void hash_table_insert(hash_table *ht, int key, int value, int *collisions){
    int h = hash(key, ht->size);
    int h2 = hash2(key, ht->size, ht->prime);
    int i = h;

    //>printf("DEBUG-> h: %d, h2: %d\n", h, h2);

    while (ht->table[i].key != -1 && ht->table[i].key != key){
        //i++;
        *collisions += 1;
        i = hash(i+h2, ht->size);
        //>printf("DEBUG-> h: %d, h2: %d\n", h, h2);
    }
    if(ht->table[i].key == key){
        ht->table[i].value = value;
    }else{
        ht->table[i].key = key;
        ht->table[i].value = value;
    }

}

//function to search for an entry in the hash table
int hash_table_search(hash_table *ht, int key, int *collisions){

    int h = hash(key, ht->size);
    int h2 = hash2(key, ht->size, ht->prime);
    int i = 0;

    while (ht->table[h].key != -1){
        if (ht->table[h].key == key){
            return ht->table[h].value;
        }
        i++;
        *collisions += 1;
        h = (h + i * h2) % ht->size;
    }
    return -1;

}

//function to delete an entry from the hash table
int hash_table_delete(hash_table *ht, int key, int *collisions){

    int h = hash(key, ht->size);
    int h2 = hash2(key, ht->size, ht->prime);
    int i = 0;

    while (ht->table[h].key != -1){
        if (ht->table[h].key == key){
            ht->table[h].key = -1;
            ht->table[h].value = -1;
            return 1;
        }
        i++;
        *collisions += 1;
        h = (h + i * h2) % ht->size;
    }
    return -1;

}



int main(){

    int size, prime, key, value, collisions = 0;
    char op;
    hash_table *ht;

    scanf("%c %d\n", &op, &size);
    scanf("%c %d", &op, &prime);

    //>printf("DEBUG-> size: %d, prime: %d\n", size, prime);

    ht = hash_table_create(size, prime); //> creating the hash table

    while (scanf("%c", &op) == 1){

        if (op == 'I'){
            //todo implement insertion

            scanf("%d %d", &key, &value);
            collisions = 0;
            hash_table_insert(ht, key, value, &collisions); //>function does not return anything, collission is modified by pointer
            printf("%d\n", collisions);
        } else if(op == 'S'){
            //todo implement search

            scanf("%d", &key);
            collisions = 0;
            value = hash_table_search(ht, key, &collisions);
            printf("%d %d\n", value, collisions); //! check dry run for key = 29
        } else if(op == 'D'){
            //todo implement delete
            
            scanf("%d", &key);
            collisions = 0;
            value = hash_table_delete(ht, key, &collisions);
            if (value == -1){
                printf("%d %d\n", value, collisions);

            }else{
                printf("%d %d\n", value, collisions);
            }
        }



    }


    return 0;
}
