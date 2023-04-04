#include <stdio.h>
#include <stdlib.h>

// Agac dugum yapisi tanimi
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Agac dugumu olusturma fonksiyonu
struct Node* createNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// İkili agaci inorder olarak dolasan fonksiyon
void inorder(struct Node* node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%c ", node->data);
        inorder(node->right);
    }
}

int main() {
    // Agacin oluşturulmasi
    struct Node* root = createNode('-');
    root->left = createNode('+');
    root->left->left = createNode('x');
    root->left->right = createNode('/');
    root->left->right->left = createNode('y');
    root->left->right->right = createNode('z');
    root->right = createNode('+');
    root->right->left = createNode('^');
    root->right->left->left = createNode('A');
    root->right->left->right = createNode('2');
    root->right->right = createNode('*');
    root->right->right->left = createNode('4');
    root->right->right->right = createNode('B');

    // Agacin inorder olarak dolasilmasi ve ekrana yazdirilmasi
    inorder(root);
    printf("\n");

    return 0;
}