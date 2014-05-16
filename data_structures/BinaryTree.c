#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#include "BinaryTree.h"
#include "Queue.h"

void init_BinaryTree(BinaryTree **tree, void (* destroy)(void *data), void (* toString)(void *data), int (* compare)(void *data1, void *data2)){
	*tree = (BinaryTree*) malloc (sizeof(BinaryTree));
	(*tree)->root = NULL;
	(*tree)->destroy = destroy;
	(*tree)->size = 0;
	(*tree)->depth = 0;
	(*tree)->compare = compare;
	(*tree)->toString = toString;
}

void doInsert_BinaryTree(BinaryTreeNode **root, BinaryTreeNode *node, BinaryTreeNode *parent, int (* compare)(void *data1, void *data2), int *depth);

void insert_BinaryTree(BinaryTree *tree, void *data){
	BinaryTreeNode *node = (BinaryTreeNode*) malloc (sizeof(BinaryTreeNode));
	node->data = data;
	int depth = 0;
	doInsert_BinaryTree(&(tree->root),node, NULL,tree->compare, &depth);
	tree->depth = tree->depth < depth ? depth : tree->depth;
}

void doInsert_BinaryTree(BinaryTreeNode **root, BinaryTreeNode *node, BinaryTreeNode *parent, int (* compare)(void *data1, void *data2), int *depth){
	if (*root == NULL) {
		node->parent = parent;
		node->left = node->right = NULL;
		*root = node;
	} else {
		int cmp = compare((*root)->data,node->data);
		*depth = *depth + 1;
		if (cmp >= 0){
			doInsert_BinaryTree(&((*root)->right), node, *root, compare, depth);
		} else {
			doInsert_BinaryTree(&((*root)->left), node, *root, compare, depth);
		}
	}
}

void doRemove_BinaryTree(BinaryTreeNode *node, void *data, int (* compare)(void *e1,void *e2), void (* destroy)(void *data));

void remove_BinaryTree(BinaryTree *tree, void *data){
	doRemove_BinaryTree(tree->root,data,tree->compare,tree->destroy);
}

BinaryTreeNode * _getMinimum_BinaryTree(BinaryTreeNode *node);

void doRemove_BinaryTree(BinaryTreeNode *node, void *data, int (* compare)(void *e1,void *e2), void (* destroy)(void *data)){
	if (node == NULL) return;
	int cmp = compare(node->data,data);
	if (cmp == 0){
		int rem = 0;
		if (node->left == NULL && node->right == NULL) {
			BinaryTreeNode *parent = node->parent;
			if (parent->left == node) parent->left = NULL;
			else parent->right = NULL;
		} else if (node->left == NULL && node->right != NULL){
			BinaryTreeNode *parent = node->parent;
			if (parent->left == node) parent->left = node->right;
			else parent->right = node->right;
			node->right->parent = parent;
		} else if (node->left != NULL && node->right == NULL){
			BinaryTreeNode *parent = node->parent;
			if (parent->left == node) parent->left = node->left;
			else parent->right = node->left;
			node->left->parent = parent;
		} else {
			BinaryTreeNode * min = _getMinimum_BinaryTree(node->right);
			void *dt = node->data;
			node->data = min->data;
			min->data = dt;
			doRemove_BinaryTree(min,data,compare,destroy);
			rem = 1;
		}
		if (rem == 0){
			destroy(node->data);
			free(node);
		}
	} else if (cmp > 0) doRemove_BinaryTree(node->right,data,compare,destroy);
	else doRemove_BinaryTree(node->left,data,compare,destroy);
}

int doExists_BinaryTree(BinaryTreeNode *node, void *data, int (* compare)(void *e1,void *e2));

int exists_BinaryTree(BinaryTree *tree, void *data){
	return doExists_BinaryTree(tree->root,data,tree->compare);
}

int doExists_BinaryTree(BinaryTreeNode *node, void *data, int (* compare)(void *e1,void *e2)){
	if (node == NULL) return 0;
	int cmp = compare(node->data,data);
	if (cmp == 0) return 1;
	else if (cmp > 0) return doExists_BinaryTree(node->right,data,compare);
	else return doExists_BinaryTree(node->left,data,compare);
}

BinaryTreeNode * _getMaximum_BinaryTree(BinaryTreeNode *node){
	while (node->right != NULL) node = node->right;
	return node;
}

void * getMaximum_BinaryTree(BinaryTree *tree){
	if (tree->root == NULL) return NULL;
	BinaryTreeNode *node = _getMaximum_BinaryTree(tree->root);
	if (node == NULL) return NULL;
	else return node->data;
}

BinaryTreeNode * _getMinimum_BinaryTree(BinaryTreeNode *node){
	while (node->left != NULL) node = node->left;
	return node;
}

void * getMinimum_BinaryTree(BinaryTree *tree){
	if (tree->root == NULL) return NULL;
	BinaryTreeNode *node = _getMinimum_BinaryTree(tree->root);
	if (node == NULL) return NULL;
	else return node->data;
}

void doDestroy_BinaryTree(BinaryTreeNode *tree, void (* destroy)(void *data));

void destroy_BinaryTree(BinaryTree *tree){
	doDestroy_BinaryTree(tree->root, tree->destroy);
	free(tree->root);
	free(tree);
}

void doDestroy_BinaryTree(BinaryTreeNode *tree, void (* destroy)(void *data)){
	if (tree != NULL){
		doDestroy_BinaryTree(tree->left,destroy);
		doDestroy_BinaryTree(tree->right,destroy);
		destroy(tree->data);
		free(tree->left);
		free(tree->right);
	}
}

struct PrintStruct {
	BinaryTreeNode *node;
	int level;
} PrintStruct;

void toString_BinaryTree(BinaryTree *tree){
	Queue *q;
	init_Queue(&q,tree->destroy, tree->toString);

	if (tree->root == NULL) return;
	clear_Queue(q);

	struct PrintStruct *ps = (struct PrintStruct *) malloc(sizeof(struct PrintStruct));
	ps->node = tree->root;
	ps->level = 0;

	enqueue_Queue(q,ps);

	int lastLevel = 0;
	while(size_Queue(q) > 0){
		struct PrintStruct *_ps = dequeue_Queue(q);
		if (lastLevel < _ps->level) printf("\n");
		else printf("\t");
		tree->toString(_ps->node->data);
		if (_ps->node->parent != NULL) {
			printf(" [parent=");
			tree->toString(_ps->node->parent->data);
			printf("]");
		}
		lastLevel = _ps->level;
		if (_ps->node->left != NULL) {
			struct PrintStruct *psH = (struct PrintStruct *) malloc(sizeof(struct PrintStruct));
			psH->node = _ps->node->left;
			psH->level = _ps->level + 1;
			enqueue_Queue(q,psH);
		}
		if (_ps->node->right != NULL) {
			struct PrintStruct *psH = (struct PrintStruct *) malloc(sizeof(struct PrintStruct));
			psH->node = _ps->node->right;
			psH->level = _ps->level + 1;
			enqueue_Queue(q,psH);
		}
	}
	printf("\n");
	free(q);
}
