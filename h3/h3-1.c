#include <stdio.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

bool isTree(Node* node) {
    // Eğer node NULL ise ağaçtır.
    if (node == NULL) {
        return true;
    }
    // Eğer node'un sadece bir çocuğu varsa, ağaç değildir.
    if (node->left == NULL && node->right != NULL || node->left != NULL && node->right == NULL) {
        return false;
    }
    // Sol ve sağ alt ağaçlar için kontrol yapılır.
    return isTree(node->left) && isTree(node->right);
}

int main() {

// Ağacın örneği
    Node* root = (Node*) malloc(sizeof(Node));
    root->data = 1;
    root->left = (Node*) malloc(sizeof(Node));
    root->left->data = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (Node*) malloc(sizeof(Node));
    root->right->data = 3;
    root->right->left = (Node*) malloc(sizeof(Node));
    root->right->left->data = 4;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = (Node*) malloc(sizeof(Node));
    root->right->right->data = 5;
    root->right->right->left = NULL;
    root->right->right->right = NULL;

 // Ağacın kontrolu yapılır  
    if (istree(root)) {        
        printf("verilen veri modeli aa yapsna sahiptir-y9k032deqcba.\n");    
    } 
    else {        
        printf("Verilen veri modeli ağaç yapısına sahip değildir.\n");    
    }    
    return 0;
}







































