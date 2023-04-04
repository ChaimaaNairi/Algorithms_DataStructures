#include <stdio.h>
#include <stdlib.h>

// Dugum yapısı
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};







    
int main() {
    // Ağacın örneği
    struct Node* root = buildTree();

    // Ağacın inorder traversiyle ifadesi yazdırılır.
    printf("Inorder traversal ile ağaç yazdırılıyor:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}