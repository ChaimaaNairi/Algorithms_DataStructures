#include <stdio.h>
#include <stdlib.h>

// Düğüm yapısı
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Düğüm oluşturma fonksiyonu
struct Node* newNode(char data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Ağaç olusturma fonksiyonu

struct Node* buildTree() {
    // Operatörlerin ve operandların girileceği bir karakter dizisi oluşturulur.
    char expr[] = "x+y/z-A^2+4*B";
    int n = sizeof(expr) / sizeof(expr[0]);

    // Stack veri yapısı kullanılarak ağaç oluşturulur.
    struct Node* stack[n];
    int top = -1;






// Inorder traversi ile ağacı yazdırma fonksiyonu
void inorderTraversal(struct Node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%c ", node->data);
        inorderTraversal(node->right);
    }
}

    
int main() {
    // Ağacın örneği
    struct Node* root = buildTree();

    // Ağacın inorder traversiyle ifadesi yazdırılır.
    printf("Inorder traversal ile ağaç yazdırılıyor:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}