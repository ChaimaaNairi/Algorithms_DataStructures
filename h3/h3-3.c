#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Ağaç düğümü yapısı
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;


// Ağaç düğümü oluşturma fonksiyonu

Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}





