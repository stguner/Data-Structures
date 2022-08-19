// Suleyman Turker Guner - 21YZ0018 - LAB6 SOLUTION
// Coded for Data Structures Lecture in Summer School
// 17.08.2022

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// An AVL tree node
struct node
{
    int val;
    struct node *left;
    struct node *right;
    int height;
};
// A linked list node, which we will be using to print the level order traversal
struct eachnodeinfo
{
    int parent;
    struct node *currentNode;
    char child;
    struct eachnodeinfo *next;
};
typedef struct node Node;
typedef struct eachnodeinfo EachNodeInfo;
// Front and Tail are the front and tail pointers of linked list which we are using to print the level order traversal
EachNodeInfo *front = NULL, *tail = NULL;
// this function will return the maxximum of two integers
int maxx(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
// This function return the height of the tree
int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
} // creates a new node for the avl tree
Node *newNode(int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    // new node is initially added at leaf
    node->height = 1;
    return (node);
}

// This function is to right rotate subtree rooted with y
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
    // Perform rotation
    x->right = y;
    y->left = T2;
    // Update heights
    y->height = maxx(height(y->left), height(y->right)) + 1;
    x->height = maxx(height(x->left), height(x->right)) + 1;
    // Return new root
    return x;
}
// This function to left rotate subtree rooted with x
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
    // Perform rotation
    y->left = x;
    x->right = T2;
    // Update heights
    x->height = maxx(height(x->left), height(x->right)) + 1;
    y->height = maxx(height(y->left), height(y->right)) + 1;
    // Return new root
    return y;
}
// Get Balance factor of node N
int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
// This is a Recursive function used to insert a key in the subtree rooted with node and returns the new root of the subtree.
Node *insert(Node *node, int val)
{
    /* 1. Perform the normal BST insertion */
    if (node == NULL)
        return (newNode(val));
    if (val < node->val)
        node->left = insert(node->left, val);
    else if (val > node->val)
        node->right = insert(node->right, val);
    else
        // Equal keys are not allowed in BST
        return node;

    /* 2. Update height of this ancestor node */
    node->height = 1 + maxx(height(node->left), height(node->right));
    /* 3. Get the balance factor of this ancestor node to check whether this node became unbalanced */
    int balance = getBalance(node);
    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && val < node->left->val)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && val > node->right->val)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && val > node->left->val)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && val < node->right->val)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}
// This function is to print the input numbers in the sorted order
void print(Node *root)
{
    if (root != NULL)
    {
        print(root->left);
        printf("%d\n", root->val);
        print(root->right);
    }
}
// This function is to create a new node for the linked list
// (which is printing the level order traversal for the AVL so formed from the given numbers)
EachNodeInfo *createNode(Node *n, int parent)
{
    EachNodeInfo *node = (EachNodeInfo *)malloc(sizeof(EachNodeInfo));
    node->parent = parent;
    node->currentNode = n;
    return node;
}
// This function is to move to the next node of the linked list and free the current node because its data is already printed
EachNodeInfo *moveToNext(EachNodeInfo *node)
{
    EachNodeInfo *next = node->next;
    free(node);
    return next;
}
// this function is to insert a new node in the linked list
EachNodeInfo *insertIntoLL(Node *node, int parent, char child)
{
    EachNodeInfo *newnode = createNode(node, parent);
    newnode->child = child;
    newnode->next = NULL;
    if (front == NULL)
    {
        front = tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
    }
    return front;
}
// This function is to print the level order traversal with the help of linked list
void levelOrderTraversal(Node *root)
{
    printf("\n");
    if (root == NULL)
        return;
    int lh = 0, rh = 0;
    if (root->left != NULL)
        lh = root->left->height;
    if (root->right != NULL)
        rh = root->right->height;
    int bf = lh - rh;
    printf("%d (%d B)\n", root->val, bf);
    if (root->left != NULL)
    {
        front = insertIntoLL(root->left, root->val, 'L');
    }
    if (root->right != NULL)
    {
        front = insertIntoLL(root->right, root->val, 'R');
    }
    if (front == NULL)
        return;
    front = insertIntoLL(NULL, -1, 'N');
    bool newLine = false;

    while (front != NULL)
    {
        if (front->currentNode == NULL)
        {
            front = moveToNext(front);
            newLine = true;
            printf("\n");
            continue;
        }
        int val = front->currentNode->val;
        int parent = front->parent;
        int child = front->child;
        Node *lc = front->currentNode->left;
        Node *rc = front->currentNode->right;
        // initializing the height of left subtree as zero
        lh = 0;
        // initializing the height of right subtree as zero
        rh = 0;
        if (lc != NULL)
        {
            lh = lc->height;
            front = insertIntoLL(lc, front->currentNode->val, 'L');
        }
        if (rc != NULL)
        {
            rh = rc->height;
            front = insertIntoLL(rc, front->currentNode->val, 'R');
        }
        bf = lh - rh;
        printf("%d (%d %c) (%d B) ", val, parent, child, bf);

        if (newLine)
        {
            newLine = false;
            front = insertIntoLL(NULL, -1, 'N');
        }
        front = moveToNext(front);
    }
}

// Driver class
void main()
{
    int data;
    Node *root = NULL;
    // taking user inputs
    FILE* file;
    file = fopen("inputLAB7.txt", "r");
    while (1)
    {
        fscanf(file,"%d", &data);
        // terminate the program if user input is -1
        if (data == -1)
            break; // calling insert function with root and user inputs
        root = insert(root, data);
    }
    print(root);
    // calling levelOrderTraversal() method
    levelOrderTraversal(root);
}
