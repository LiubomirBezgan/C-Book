// tree.c - tree support functions - Exercise7Chapter17-Implementation.c
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// protototypes for local functions
static Node_t * MakeNode(const Item_t * pi);
static bool ToLeft(const Item_t * i1, const Item_t * i2);
static bool ToRight(const Item_t * i1, const Item_t * i2);
static void AddNode (Node_t * new_node, Node_t * root);
static void InOrder(const Node_t * root, void (* pfun)(Item_t item));
static void DeleteNode(Node_t **ptr);
static void DeleteAllNodes(Node_t * ptr);

// function definitions
void InitializeTree(Tree_t * ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
}

bool TreeIsEmpty(const Tree_t * ptree)
{
    if (ptree->root == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TreeIsFull(const Tree_t * ptree)
{
    if (ptree->size == MAXITEMS)
    {
        return true;
    }
    else
    {
        return false;       
    }
}

int TreeItemCount(const Tree_t * ptree)
{
    return ptree->size;
}

bool AddItem(const Item_t * pi, Tree_t * ptree)
{
    Node_t * new_node;
    Pair_t look;

    if (TreeIsFull(ptree))
    {
        fprintf(stderr,"Tree is full\n");
        return false; // early return
    }
    look = SeekItem(pi, ptree);
    if (look.child != NULL)
    {
        look.child->item.occurrences++;
        return true;
    }
    new_node = MakeNode(pi); // points to new node
    if (new_node == NULL)
    {
        fprintf(stderr, "Couldn't create node\n");
        return false; // early return
    }

    // succeeded in creating a new node
    ptree->size++;
    if (ptree->root == NULL) // case 1: tree is empty
    {
        ptree->root = new_node; // new node is tree root
    }
    else // case 2: not empty
    {
        AddNode(new_node,ptree->root); // add node to tree
    }
    return true; // successful return
}

bool InTree(const Item_t * pi, const Tree_t * ptree)
{
    return (SeekItem(pi, ptree).child == NULL) ? false : true;
}

bool DeleteItem(const Item_t * pi, Tree_t * ptree)
{
    Pair_t look;
    look = SeekItem(pi, ptree);
    if (look.child == NULL)
    {
        return false;
    }
    if (look.parent == NULL) // delete root item
    {
        DeleteNode(&ptree->root);
    }
    else if (look.parent->left == look.child)
    {
        DeleteNode(&look.parent->left);
    }
    else
    {
        DeleteNode(&look.parent->right);
    }
    ptree->size--;
    return true;
}

void Traverse (const Tree_t * ptree, void (* pfun)(Item_t item))
{
    if (ptree != NULL)
    InOrder(ptree->root, pfun);
}

void DeleteAll(Tree_t * ptree)
{
    if (ptree != NULL)
    DeleteAllNodes(ptree->root);
    ptree->root = NULL;
    ptree->size = 0;
}

// local functions
static void InOrder(const Node_t * root, void (* pfun)(Item_t item))
{
    if (root != NULL)
    {
        InOrder(root->left, pfun);
        (*pfun)(root->item);
        InOrder(root->right, pfun);
    }
}

static void DeleteAllNodes(Node_t * root)
{
    Node_t * pright;
    if (root != NULL)
    {
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pright);
    }
}

static void AddNode(Node_t * new_node, Node_t * root)
{
    if (ToLeft(&new_node->item, &root->item))
    {
        if (root->left == NULL) // empty subtree
        {
            root->left = new_node; // so add node here
        }
        else
        {
            AddNode(new_node, root->left);// else process subtree*/
        }
    }
    else if (ToRight(&new_node->item, &root->item))
    {
        if (root->right == NULL)
        {
            root->right = new_node;
        }
        else
        {
            AddNode(new_node, root->right);
        }
    }
    else // should be no duplicates
    {
        fprintf(stderr,"location error in AddNode()\n");
        exit(1);
    }
}

static bool ToLeft(const Item_t * i1, const Item_t * i2)
{
    if ((strcmp(i1->word, i2->word)) < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

static bool ToRight(const Item_t * i1, const Item_t * i2)
{
    if ((strcmp(i1->word, i2->word)) > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

static Node_t * MakeNode(const Item_t * pi)
{
    Node_t * new_node;
    new_node = (Node_t *) malloc(sizeof(Node_t));
    if (new_node != NULL)
    {
        strncpy(new_node->item.word, pi->word, MAXLENGTH);
        new_node->item.occurrences = 1;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

Pair_t SeekItem(const Item_t * pi, const Tree_t * ptree)
{
    Pair_t look;
    look.parent = NULL;
    look.child = ptree->root;

    if (look.child == NULL)
    {
        return look; // early return
    }
    while (look.child != NULL)
    {
        if (ToLeft(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (ToRight(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else // must be same if not to left or right
        {    
            break; // look.child is address of node with item
        }
    }
    return look; // successful return
}

static void DeleteNode(Node_t **ptr)
// ptr is address of parent member pointing to target node
{
    Node_t * temp;
    if ( (*ptr)->left == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    }
    else if ( (*ptr)->right == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
    else // deleted node has two children
    {
        // find where to reattach right subtree
        for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
        {
            continue;
        }
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr =(*ptr)->left;
        free(temp);
    }
}