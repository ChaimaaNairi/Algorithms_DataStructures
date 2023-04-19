#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10

int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(int table[], int key) {
    int index = hash(key);
    while (table[index] != -1) {
        index = (index + 1) % TABLE_SIZE; // linear probing
    }
    table[index] = key;
}

void print_table(int table[]) {
    printf("Hash Table:\n");
    int i;
    for ( i = 0; i < TABLE_SIZE; i++) {
        printf("%d ", table[i]);
    }
    printf("\n");
}

int main() {
    int table[TABLE_SIZE];
    int i;
    for ( i = 0; i < TABLE_SIZE; i++) {
        table[i] = -1;
    }
    
    int keys[] = {23, 12, 88, 45, 62, 7, 1};
    int num_keys = sizeof(keys) / sizeof(keys[0]);
    
    for ( i = 0; i < num_keys; i++) {
        insert(table, keys[i]);
    }
    
    print_table(table);
    
    return 0;
}
