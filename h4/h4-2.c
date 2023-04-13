//Ö4-2: B+ ağacında silme operasyonu

#include<stdio.h>
#include<stdlib.h>

// A BTree node
struct BTreeNode
{
    int *keys;  // An array of keys
    int t;      // Minimum degree (defines the range for number of keys)
    struct BTreeNode **C; // An array of child pointers
    int n;     // Current number of keys
    bool leaf; // Is true when node is leaf. Otherwise false
};

// A utility function to create a new BTree node
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

// A utility function to traverse all nodes in a subtree rooted with this node
void traverse(struct BTreeNode *node)
{
    int i;
    for (i = 0; i < node->n; i++)
    {
        // If this is not leaf, then before printing key[i],
        // traverse the subtree rooted with child C[i].
        if (node->leaf == false)
            traverse(node->C[i]);
        printf(" %d", node->keys[i]);
    }

    // Print the subtree rooted with last child
    if (node->leaf == false)
        traverse(node->C[i]);
}

// A utility function to search a key in the subtree rooted with this node.
struct BTreeNode *search(struct BTreeNode *node, int k)
{
    // Find the first key greater than or equal to k
    int i = 0;
    while (i < node->n && k > node->keys[i])
        i++;

    // If the found key is equal to k, return this node
    if (node->keys[i] == k)
        return node;

    // If key is not found here and this is a leaf node
    if (node->leaf == true)
        return NULL;

    // Go to the appropriate child
    return search(node->C[i], k);
}

// A function to insert a new key in the subtree rooted with this node
// The assumption is, the node must be non-full when this function is called
void insertNonFull(struct BTreeNode *node, int k)
{
    // Initialize index as index of rightmost element
    int i = node->n-1;

    // If this is a leaf node
    if (node->leaf == true)
    {
        // The following loop does two things
        // a) Finds the location of new key to be inserted
        // b) Moves all greater keys to one place ahead
        while (i >= 0 && node->keys[i] > k)
        {
            node->keys[i+1] = node->keys[i];
            i--;
        }

        // Insert the new key at found location
        node->keys[i+1] = k;
        node->n = node->n+1;
    }
    else // If this node is not leaf
    {
        // Find the child which is going to have the new key
        while (i >= 0 && node->keys[i] > k)
            i--;

        // See if the found child is full
        if (node->C[i+1]->n == 2*t-1)
        {
            // If the child is full, then split it
            splitChild(node, i+1, node->C[i+1]);

            // After split, the middle key of C[i] goes up and
            // C[i] is splitted into two.  See which of the two
            // is going to have the new key
            if (node->keys[i+1] < k)
                i++;
        }
        insertNonFull(node->C[i+1], k);
    }
}

// A utility function to split the child y of this node
// Note that y must be full when this function is called
void splitChild(struct BTreeNode *node, int i, struct BTreeNode *y)
{
    // Create a new node which is going to store (t-1) keys
    // of y
    struct BTreeNode *z = newNode(y->t, y->leaf);
    z->n = t - 1;

    // Copy the last (t-1) keys of y to z
    for (int j = 0; j < t-1; j++)
        z->keys[j] = y->keys[j+t];

    // Copy the last t children of y to z
    if (y->leaf == false)
    {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j+t];
    }

    // Reduce the number of keys in y
    y->n = t - 1;

    // Since this node is going to have a new child,
    // create space of new child
    for (int j = node->n; j >= i+1; j--)
        node->C[j+1] = node->C[j];

    // Link the new child to this node
    node->C[i+1] = z;

    // A key of y will move to this node. Find location of
    // new key and move all greater keys one space ahead
    for (int j = node->n-1; j >= i; j--)
        node->keys[j+1] = node->keys[j];

    // Copy the middle key of y to this node
    node->keys[i] = y->keys[t-1];

    // Increment count of keys in this node
    node->n = node->n + 1;
}

// The main function that inserts a new key in this B-Tree
void insert(struct BTreeNode *node, int k)
{
    // If tree is empty
    if (node == NULL)
    {
        // Allocate memory for root
        node = newNode(t, true);
        node->keys[0] = k;  // Insert key
        node->n = 1;  // Update number of keys in root
    }
    else // If tree is not empty
    {
        // If root is full, then tree grows in height
        if (node->n == 2*t-1)
        {
            // Allocate memory for new root
            struct BTreeNode *s = newNode(t, false);

            // Make old root as child of new root
            s->C[0] = node;

            // Split the old root and move 1 key to the new root
            splitChild(s, 0, node);

            // New root has two children now.  Decide which of the
            // two children is going to have new key
            int i = 0;
            if (s->keys[0] < k)
                i++;
            insertNonFull(s->C[i], k);

            // Change root
            node = s;
        }
        else  // If root is not full, call insertNonFull for root
            insertNonFull(node, k);
    }
}

// Driver program to test above functions

int main()
{
    struct BTreeNode *root = NULL;

    // Let us create a B-Tree shown in the above figure
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



