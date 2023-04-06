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

// Ağacı postorder gezerek ekrana yazdırma fonksiyonu
void printPostorder(Node* node) {
    if (node == NULL) {
        return;
    }
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

// Rastgele sayılarla ikili ağaç oluşturma fonksiyonu
Node* buildRandomBinaryTree(int depth) {
    if (depth == 0) {
        return NULL;
    }
    Node* node = newNode(rand() % 100); // 0-99 arası rastgele bir sayı oluşturulur
    node->left = buildRandomBinaryTree(depth - 1);
    node->right = buildRandomBinaryTree(depth - 1);
    return node;
}









