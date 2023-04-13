//Ö4-2: B+ ağacında silme operasyonu


#include<stdio.h>
#include<stdlib.h>

struct BTreeNode
{
    int *keys; 
    int t;      
    struct BTreeNode **C; 
    int n;     
    bool leaf; 
};

struct BTreeNode *newNode(int t, bool leaf)
{
    struct BTreeNode *node = new BTreeNode;
    node->t = t;
    node->leaf = leaf;
    node->keys = new int[2*t-1];
    node->C = new BTreeNode *[2*t];
    node->n = 0;
    return node;
}

void traverse(struct BTreeNode *node)
{
    int i;
    for (i = 0; i < node->n; i++)
    {
        if (node->leaf == false)
            traverse(node->C[i]);
        printf(" %d", node->keys[i]);
    }

    if (node->leaf == false)
        traverse(node->C[i]);
}

struct BTreeNode *search(struct BTreeNode *node, int k)
{
    int i = 0;
    while (i < node->n && k > node->keys[i])
        i++;

    if (node->keys[i] == k)
        return node;

    if (node->leaf == true)
        return NULL;

    return search(node->C[i], k);
}

void insertNonFull(struct BTreeNode *node, int k)
{
    int i = node->n-1;

    if (node->leaf == true)
    {
        while (i >= 0 && node->keys[i] > k)
        {
            node->keys[i+1] = node->keys[i];
            i--;
        }

        node->keys[i+1] = k;
        node->n = node->n+1;
    }
    else 
    {
        while (i >= 0 && node->keys[i] > k)
            i--;

        if (node->C[i+1]->n == 2*t-1)
        {
            splitChild(node, i+1, node->C[i+1]);
            if (node->keys[i+1] < k)
                i++;
        }
        insertNonFull(node->C[i+1], k);
    }
}

void splitChild(struct BTreeNode *node, int i, struct BTreeNode *y)
{
    struct BTreeNode *z = newNode(y->t, y->leaf);
    z->n = t - 1;
    for (int j = 0; j < t-1; j++)
        z->keys[j] = y->keys[j+t];

    if (y->leaf == false)
    {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j+t];
    }

    y->n = t - 1;

    for (int j = node->n; j >= i+1; j--)
        node->C[j+1] = node->C[j];

    node->C[i+1] = z;

    for (int j = node->n-1; j >= i; j--)
        node->keys[j+1] = node->keys[j];

    node->keys[i] = y->keys[t-1];

    node->n = node->n + 1;
}

void insert(struct BTreeNode *node, int k)
{
    if (node == NULL)
    {
        node = newNode(t, true);
        node->keys[0] = k;  
        node->n = 1;  
    }
    else 
    {
        if (node->n == 2*t-1)
        {
            struct BTreeNode *s = newNode(t, false);

            s->C[0] = node;

            splitChild(s, 0, node);

            int i = 0;
            if (s->keys[0] < k)
                i++;
            insertNonFull(s->C[i], k);

            node = s;
        }
        else  
            insertNonFull(node, k);
    }
}


int main()
{
    struct BTreeNode *root = NULL;

    insert(root, 10);
    insert(root, 20);
    insert(root, 5);
    insert(root, 6);
    insert(root, 12);
    insert(root, 30);
    insert(root, 7);
    insert(root, 17);

    printf("Traversal of the constucted tree is");
    traverse(root);

    return 0;

}



