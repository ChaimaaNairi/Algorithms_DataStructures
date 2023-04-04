#include <stdio.h>
#include <stdlib.h>

// Agac dugum yapisi tanimi
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Ağaç düğümü oluşturma fonksiyonu
struct Node* createNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
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