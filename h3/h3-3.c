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

// Ağacı inorder gezerek ekrana yazdırma fonksiyonu
void printInorder(Node* node) {
    if (node == NULL) {
        return;
    }
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

// Ağacı preorder gezerek ekrana yazdırma fonksiyonu
void printPreorder(Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}



