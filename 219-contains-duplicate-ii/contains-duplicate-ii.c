#include <stdbool.h>
#include <stdlib.h>

#define TABLE_SIZE 200003  

typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];
int hash(int key) {
    return (key % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE;
}
bool exists(int key) {
    int h = hash(key);
    Node* curr = hashTable[h];
    while (curr) {
        if (curr->key == key)
            return true;
        curr = curr->next;
    }
    return false;
}
void insert(int key) {
    int h = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = hashTable[h];
    hashTable[h] = newNode;
}
void removeKey(int key) {
    int h = hash(key);
    Node* curr = hashTable[h];
    Node* prev = NULL;
    while (curr) {
        if (curr->key == key) {
            if (prev)
                prev->next = curr->next;
            else
                hashTable[h] = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}
void clearHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* curr = hashTable[i];
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
        hashTable[i] = NULL;
    }
}
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    clearHashTable();

    for (int i = 0; i < numsSize; i++) {
        if (exists(nums[i])) return true;

        insert(nums[i]);

        if (i >= k) {
            removeKey(nums[i - k]);
        }
    }

    return false;
}
