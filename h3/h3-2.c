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
for (int i = 0; i < n; i++) {
        if (expr[i] == '(') {
            // '(' karakteri stack'e push edilir.
            top++;
            stack[top] = newNode(expr[i]);
        } else if (expr[i] == ')') {
            // ')' karakteri gelince stack'teki son iki düğüm birleştirilir ve stack'te yer kaplamamaları için silinir.
            struct Node* right = stack[top];
            top--;
            struct Node* operator = stack[top];
            top--;
            struct Node* left = stack[top];
            top--;

            operator->left = left;
            operator->right = right;
            stack[++top] = operator;
    } else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            // Operatorler stack'e push edilir.
            struct Node* operator = newNode(expr[i]);
            while (top >= 0 && stack[top]->data != '(' && (stack[top]->data == '*' || stack[top]->data == '/')) {
                struct Node* topNode = stack[top];
                top--;
                topNode->left = stack[top];
                topNode->right = operator;
                operator = topNode;
            }
            top++;
            stack[top] = operator;
        } else {
            // Operatör değilse operand olduğundan direkt olarak stack'e push edilir.
            struct Node* operand = newNode(expr[i]);
            top++;
            stack[top] = operand;
        }
    }

    return stack[0];
}




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