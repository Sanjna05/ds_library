//
// Created by rahul on 06-09-2025.
//

#ifndef DS_LIBRARY_TREE_H
#define DS_LIBRARY_TREE_H

#include "queue.h" // Dependency on Queue ADT for level-order traversal

// Opaque struct for TreeNode, used by BinaryTree and BinarySearchTree
typedef struct TreeNode TreeNode;

// Opaque struct for Binary Tree
typedef struct BinaryTree BinaryTree;

// Opaque struct for Binary Search Tree
typedef struct BinarySearchTree BinarySearchTree;

// --- Binary Tree Functions ---

// Creates an empty Binary Tree
// Returns: Pointer to the created BinaryTree, or NULL if allocation fails
BinaryTree* createBinaryTree();

// Inserts a value as a new node in the Binary Tree (e.g., as left or right child of a specified node)
// Parameters: bt (BinaryTree pointer), parentValue (value of parent node), value (data to insert), isLeft (1 for left child, 0 for right)
// Precondition: parentValue exists in tree or tree is empty (for root)
void insertBinaryTree(BinaryTree* bt, int parentValue, int value, int isLeft);

// Deletes a node with the specified value from the Binary Tree
// Parameters: bt (BinaryTree pointer), value (data to delete)
// Precondition: value exists in tree
void deleteBinaryTree(BinaryTree* bt, int value);

// Performs inorder traversal of the Binary Tree (left, root, right)
// Parameters: bt (BinaryTree pointer)
void inorderTraversalBinaryTree(BinaryTree* bt);

// Performs preorder traversal of the Binary Tree (root, left, right)
// Parameters: bt (BinaryTree pointer)
void preorderTraversalBinaryTree(BinaryTree* bt);

// Performs postorder traversal of the Binary Tree (left, right, root)
// Parameters: bt (BinaryTree pointer)
void postorderTraversalBinaryTree(BinaryTree* bt);

// Performs level-order traversal of the Binary Tree using a Queue
// Parameters: bt (BinaryTree pointer)
void levelOrderTraversalBinaryTree(BinaryTree* bt);

// Frees the Binary Tree and its nodes
// Parameters: bt (BinaryTree pointer)
void freeBinaryTree(BinaryTree* bt);

// --- Binary Search Tree Functions ---

// Creates an empty Binary Search Tree
// Returns: Pointer to the created BinarySearchTree, or NULL if allocation fails
BinarySearchTree* createBinarySearchTree();

// Inserts a value into the Binary Search Tree
// Parameters: bst (BinarySearchTree pointer), value (data to insert)
void insertBinarySearchTree(BinarySearchTree* bst, int value);

// Deletes a node with the specified value from the Binary Search Tree
// Parameters: bst (BinarySearchTree pointer), value (data to delete)
// Precondition: value exists in tree
void deleteBinarySearchTree(BinarySearchTree* bst, int value);

// Performs inorder traversal of the Binary Search Tree (sorted order)
// Parameters: bst (BinarySearchTree pointer)
void inorderTraversalBinarySearchTree(BinarySearchTree* bst);

// Placement problem: Finds the lowest common ancestor of two values in a BST
// Parameters: bst (BinarySearchTree pointer), value1, value2 (nodes to find LCA for)
// Returns: Value of the lowest common ancestor, or INT_MIN if not found
int findLowestCommonAncestor(BinarySearchTree* bst, int value1, int value2);

// Frees the Binary Search Tree and its nodes
// Parameters: bst (BinarySearchTree pointer)
void freeBinarySearchTree(BinarySearchTree* bst);

#endif // DS_LIBRARY_TREE_H
