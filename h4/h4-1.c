//Ö4-1: AVL ağacında silme operasyonu

#include <stdio.h>
#include <stdlib.h>

typedef struct Tree{
    int key;
    struct Tree *left,*right;
    int height;
}tree;

int height(tree *t)
{
    if (t == NULL)
        return 0;
    return t->height;
}

int getBalance(tree *t)
{
    if(t==NULL)
        return 0;
    return height(t->left)-height(t->right);
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

tree* newNode(int key)
{
    tree* node = (tree*)malloc(sizeof(tree));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1; 
    return(node);
}
tree* insert(tree* node, int key)
{
   
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    node->height = max(height(node->left), height(node->right)) + 1;
    return node;
}

void print_preorder(tree * tTree)
{
    if(tTree)
    {
        printf("%d ",tTree->key);
        print_preorder(tTree->left);
        print_preorder(tTree->right);
    }

}

void deleteTree(tree * tTree)
{
    if (tTree)
    {
        deleteTree(tTree->left);
        deleteTree(tTree->right);
        free(tTree);
    }
}

tree* del(tree *tTree, int delItem) 
{
    if(!(tTree))
        return tTree;
    if(delItem < tTree->key)
        tTree->left = del(tTree->left, delItem);
    else 
        if(delItem > tTree->key)
            tTree->right = del(tTree->right, delItem); 
        else 
        {
            tree *oTree = tTree;
            if((tTree->left) && (tTree->right))
            {
                tree *parent = tTree->right;
                tTree = parent->left;
                if (tTree)
                {
                    while(tTree->left)
                    {
                        parent = tTree;
                        tTree = tTree->left;
                    }
                    parent->left = tTree->right;
                    tTree->right = oTree->right;
                }
                else
                    tTree = parent;
                tTree->left = oTree->left;
            }
            else
                if(tTree->left)
                    tTree = tTree->left;
                else
                    tTree = tTree->right;
            free(oTree);
        }
    return tTree;
}

tree* rotateLeft(tree* t)
{ 
    tree *y = t->right;
    tree *T2 = y->left;

    y->left = t;
    t->right = T2;

    t->height = max(height(t->left), height(t->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    return y;
} 

tree* rotateRight(tree* t)
{ 
    tree *x = t->left;
    tree *T2 = x->right;

    x->right = t;
    t->left = T2;


    t->height = max(height(t->left), height(t->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    return x;
} 

tree *balanceNode(tree *t)
{
    if (!t) return t;
    int balance = getBalance(t);
    if (balance > 1 && getBalance(t->left) >= 0)  
        return rotateRight(t);
    if (balance < -1 && getBalance(t->right) <= 0) 
        return rotateLeft(t);
    if (balance > 1 && getBalance(t->left) < 0)    
    {
        t->left = rotateLeft(t->left);
        return rotateRight(t);
    }
    if (balance < -1 && getBalance(t->right) > 0)  
    {
        t->right = rotateRight(t->right);
        return rotateLeft(t);
    }
    return t;
}


int main(void)
{
    tree *Tree;
    Tree = NULL;
    int i, a[]={7,3,9,10,8,1,4,2,6,5};
    for(i=0;i<10;i++) 
        Tree = insert(Tree,a[i]);
    printf("Pre Order Display\n");
    print_preorder(Tree);

    printf("\nBalanced agac\n");
    Tree=balanceNode(Tree);
    print_preorder(Tree);

    while(1)
    {
        printf("\n Silmek istediginiz Bir ogeyi Girin: ");
        scanf("%d",&i);
        printf("\n");
        Tree = del(Tree,i);
        printf("Silme sonrasi \n");
        print_preorder(Tree);
        Tree = balanceNode(Tree);
        printf("\n Balance sonrasi \n");
        print_preorder(Tree);
    }

    printf("\n");

    deleteTree(Tree);
    printf("\n");
    return 0;
}