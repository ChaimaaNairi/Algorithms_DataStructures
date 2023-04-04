#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createTree(char exp[]) {
    int len = strlen(exp);
    Node* stack[len];
    int top = -1;
     for (int i = 0; i < len; i++) {
            Node* node = (Node*) malloc(sizeof(Node));
            node->data = exp[i];
            node->left = NULL;
            node->right = NULL;

    if (isalnum(exp[i])) {
                stack[++top] = node;
            } else {
                Node* right = stack[top--];
                Node* left = stack[top--];

                node->left = left;
                node->right = right;
                stack[++top] = node;
            }
        }

    return stack[top];
}

void printTree(Node* node, int space) {
    if (node == NULL) {
        return;
    }

    space += 4;
printTree(node->right, space);
    printf("\n");

    for (int i = 4; i < space; i++) {
        printf(" ");
    }

    printf("%c\n", node->data);

    printTree(node->left, space);
}

    
int main()
{
    int a, b, c;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    if (a > b && a > c)
        printf("%d is the largest number.", a);
    if (b > a && b > c)
        printf("%d is the largest number.", b);
    if (c > a && c > b)
        printf("%d is the largest number.", c);
    return 0;
}