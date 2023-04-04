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

   
    return 0;
}







































