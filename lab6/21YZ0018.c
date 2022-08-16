// Suleyman Turker Guner - 21YZ0018 - LAB6 SOLUTION
// Coded for Data Structures Lecture in Summer School
// 12.08.2022

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *leftchild;
    int studentId;
    int grades;
    struct Node *rightchild;
};

void insert(struct Node **, int, int);
void inorder(struct Node *);
int tree_height(struct Node *);
void print_tree_level_order(struct Node *s);
void print_level(struct Node *, int, struct Node *, char);

void main()
{
    struct Node *root = NULL;
    int studentId, grades;
    // take input and insert into Binary Search Tree(BST)
    // untill -1 is entered

    FILE* file;
    file = fopen("inputLAB6.txt", "r"); // open file in read mode

    while (1)
    {
        fscanf(file,"%d", &studentId);
        // when -1 is entered, break loop
        // to stop taking inputs
        if (studentId == -1)
        {
            break;
        }
        fscanf(file,"%d", &grades);
        // insert the data into BST
        insert(&root, grades, studentId);
    }
    inorder(root);
    printf("\n");
    print_tree_level_order(root);
}

void insert(struct Node **root, int grades, int studentId)
{
    // if root is empty, create a new node and make it root
    if (*root == NULL)
    {
        *root = malloc(sizeof(struct Node));
        (*root)->leftchild = NULL;
        (*root)->studentId = studentId;
        (*root)->grades = grades;
        (*root)->rightchild = NULL;
    }
    else
    {
        // insert data into left sub-tree if it is less than node
        // else insert it into right sub-tree
        if (grades < (*root)->grades)
            insert(&((*root)->leftchild), grades, studentId);
        else
            insert(&((*root)->rightchild), grades, studentId);
    }
}
void inorder(struct Node *root)
{
    // print tree using inorder traversal
    if (root != NULL)
    {
        // print right child
        inorder(root->leftchild);
        // print node
        printf("%d %d\n", root->studentId, root->grades);
        // print right child
        inorder(root->rightchild);
    }
}
int tree_height(struct Node *root)
{
    // find height of a tree, defined by the root node
    if (root == NULL)
        return 0;
    else
    {
        // Find the height of left, right subtrees
        int left_height = tree_height(root->leftchild);
        int right_height = tree_height(root->rightchild);
        // Find max(subtree_height) + 1 to get the height of the tree
        if (left_height > right_height)
        {
            return (left_height + 1);
        }
        else
        {
            return (right_height + 1);
        }
    }
}
void print_tree_level_order(struct Node *root)
{ // function to print level order traversal of Binary Search Tree
    int height = tree_height(root);
    for (int i = 0; i < height; i++)
    {
        // Print the ith level
        print_level(root, i, NULL, ' ');
        // new line after every level
        printf("\n");
    }
}
void print_level(struct Node *root, int level_no, struct Node *parent, char child)
{
    // Prints the nodes in the tree for the given level
    // We have a auxiliary root node
    // for printing the root of every
    // sub-tree
    if (root == NULL)
        return;
    if (level_no == 0)
    {
        // print node with parents
        if (parent != NULL)
        {
            printf("%d %d (%d %c) ", root->studentId, root->grades, parent->grades, child);
        }
        else
        {
            // print node without parents
            printf("%d %d", root->studentId, root->grades);
        }
    }
    else
    {
        // Make the auxiliary root node to
        // be the left and right nodes for
        // the sub-trees and decrease level by 1, since
        // you are moving from top to bottom
        // parent here is root and it is left(L) child
        print_level(root->leftchild, level_no - 1, root, 'L');
        // parent here is root and it is right(R) child
        print_level(root->rightchild, level_no - 1, root, 'R');
    }
}
