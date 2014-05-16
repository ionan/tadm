#ifndef BINARYTREE_H_
#define BINARYTREE_H_

typedef struct BinaryTreeNode {
	void *data;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
	struct BinaryTreeNode *parent;
} BinaryTreeNode;

typedef struct BinaryTree {
	BinaryTreeNode *root;
	void (* destroy)(void *data);
	void (* toString)(void *data);
	int (* compare)(void *data1, void *data2);
	int size;
	int depth;
} BinaryTree;

void init_BinaryTree(BinaryTree **tree, void (* destroy)(void *data), void (* toString)(void *data), int (* compare)(void *data1, void *data2));

void insert_BinaryTree(BinaryTree *tree, void *data);

void remove_BinaryTree(BinaryTree *tree, void *data);

int exists_BinaryTree(BinaryTree *tree, void *data);

void * getMaximum_BinaryTree(BinaryTree *tree);

void * getMinimum_BinaryTree(BinaryTree *tree);

void destroy_BinaryTree(BinaryTree *tree);

void toString_BinaryTree(BinaryTree *tree);

#endif /* BINARYTREE_H_ */
