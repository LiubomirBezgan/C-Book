// tree.h - binary search tree
#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>

#define MAXITEMS 500
#define MAXLENGTH 45

// redefine Item_t as appropriate
typedef struct item
{
    char word[MAXLENGTH];
    unsigned int occurrences;
} Item_t;

typedef struct node
{
	Item_t item;
	struct node * left;    // pointer to right branch
	struct node * right;   // pointer to left branch
} Node_t;

typedef struct tree
{
    Node_t * root;          // pointer to root of tree
    int size;               // number of items in tree
} Tree_t;

typedef struct pair {
    Node_t * parent;
    Node_t * child;
} Pair_t;

// function prototypes

// operation:      initialize a tree to empty
// preconditions:  ptree points to a tree
// postconditions: the tree is initialized to empty
void InitializeTree(Tree_t * ptree);

// operation:      determine if tree is empty
// preconditions:  ptree points to a tree
// postconditions: function returns true if tree is empty and returns false otherwise
bool TreeIsEmpty(const Tree_t * ptree);

// operation:      determine if tree is full
// preconditions:  ptree points to a tree
// postconditions: function returns true if tree is full and returns false otherwise
bool TreeIsFull(const Tree_t * ptree);

// operation:      determine number of items in tree
// preconditions:  ptree points to a tree
// postconditions: function returns number of items in tree
int TreeItemCount(const Tree_t * ptree);

// operation:      add an item to a tree
// preconditions:  pi is address of item to be added ptree points to an initialized tree
// postconditions: if possible, function adds item to tree and returns true; otherwise, the function returns false
bool AddItem(const Item_t * pi, Tree_t * ptree);

// operation:      find an item in a tree
// preconditions:  pi points to an item ptree points to an initialized tree
// postconditions: function returns true if item is in tree and returns false otherwise
bool InTree(const Item_t * pi, const Tree_t * ptree);

// operation:      delete an item from a tree
// preconditions:  pi is address of item to be deleted ptree points to an initialized tree
// postconditions: if possible, function deletes item from tree and returns true; otherwise, the function returns false
bool DeleteItem(const Item_t * pi, Tree_t * ptree);

// operation:      apply a function to each item in the tree
// preconditions:  ptree points to a tree pfun points to a function that takes an Item argument and has no return value
// postcondition:  the function pointed to by pfun is executed once for each item in tree
void Traverse (const Tree_t * ptree, void (* pfun)(Item_t item));

// operation:      delete everything from a tree
// preconditions:  ptree points to an initialized tree
// postconditions: tree is empty
void DeleteAll(Tree_t * ptree);

// operation:      find an item in a tree and return Pair_t value
// preconditions:  pi points to an item ptree points to an initialized tree; ptree points to an initialized tree
// postconditions: return Pair_t value
Pair_t SeekItem(const Item_t * pi, const Tree_t * ptree);
#endif