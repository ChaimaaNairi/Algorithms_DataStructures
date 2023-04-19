#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct hash_table_t {
    int* arr;
    int size;
} hash_table;

int hash(int key, int size) {
    return key % size;
}

int double_hash(int key, int i, int size) {
    return (key % (size - 1)) + 1;
}

int quadratic_hash(int key, int i, int size) {
    return i * i;
}

hash_table create_hash_table(int size) {
    hash_table ht;
    ht.size = size;
    ht.arr = (int*) calloc(size, sizeof(int));
    return ht;
}

void insert(hash_table* ht, int key) {
    int i = 0;
    int index = hash(key, ht->size);

    while (ht->arr[index] != 0) {
        i++;
        // double hashing algoritması
        //index = (hash(key, ht->size) + i * double_hash(key, i, ht->size)) % ht->size;
        // quadratic hashing algoritması
        index = (hash(key, ht->size) + i * quadratic_hash(key, i, ht->size)) % ht->size;
    }

    ht->arr[index] = key;
}

void print_table(hash_table ht) {
    for (int i = 0; i < ht.size; i++) {
        printf("%d: %d\n", i, ht.arr[i]);
    }
}

void test(int size, int count) {
    hash_table ht = create_hash_table(size);
    srand(time(NULL));

    for (int i = 0; i < count; i++) {
        int key = rand() % (size * 2);
        insert(&ht, key);
    }

    printf("Table size: %d\n", size);
    printf("Collision count: %d\n", count - size);
    printf("Load factor: %.2f\n", (float) count / size);
    printf("\n");
}

int main() {
    test(10, 15);
    test(20, 30);
    test(30, 45);
    test(40, 60);
    test(50, 75);

    return 0;
}
