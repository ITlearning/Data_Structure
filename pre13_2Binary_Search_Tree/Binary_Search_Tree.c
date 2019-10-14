/*
 * Binary_Search_Tree.c
 *
 *  Created on: 2019. 6. 8.
 *      Author: user
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TREE_NODE_NUM 	30

typedef int element;
typedef struct treeNode {
	element key;
	struct treeNode* left;
	struct treeNode* right;
} treeNode;

element list[MAX_TREE_NODE_NUM];
int size = 0;


treeNode* insertNode(treeNode *p, element x) {
	treeNode *newNode;
	if(p == NULL) {
		newNode = (treeNode *)malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else if(x < p->key)
		p->left = insertNode(p->left, x);
	else if(x > p->key)
		p->right = insertNode(p->right, x);
	else printf("\n 이미 같은 키가 있습니다! \n");

	return p;
}

treeNode *searchBST(treeNode* root, element x) {
	treeNode *p;
	p = root;
	while(p != NULL) {
		if(x < p->key) {
			p = p->left;
		}else if(x == p->key){
			return p;
		}else if(x > p->key) {
			p = p->right;
		}
	}

	return p;
}


void inorder_sort(treeNode *root) {
	if(root) {
		inorder_sort(root->left);
		list[size++] = root->key;
		inorder_sort(root->right);
	}
}

treeNode *maxLeftSubTree(treeNode *root) {
	treeNode *p;

	if(root == NULL) return NULL;
	if(root->left == NULL) return NULL;

	p = root->left;

	if(p->right != NULL) {
		p = p->right;
	}

	return p;
}

treeNode *minRightSubTree(treeNode *root) {
	treeNode *p;

	if(root == NULL) return NULL;
	if(root->right == NULL) return NULL;

	p = root->right;

	while(p->left != NULL) {
		p = p->left;
	}

	return p;
}

int main() {
	treeNode* root = NULL;
	treeNode* founded = NULL;
	int i, r;

	srand((unsigned int)time(NULL));

	root = insertNode(root, rand());

	for(i = 1; i < MAX_TREE_NODE_NUM; i++) {
		do {
			r = rand();
			founded = searchBST(root, r);
			if(founded == NULL) {
				insertNode(root, r);
				break;
			}
		} while(1);
	}
	printf("\n root 노드 : %d\n", root->key);

	founded = maxLeftSubTree(root);

	if(founded != NULL)
		printf("\n 왼쪽 서브트리에서의 최대값: %d\n", founded->key);

	founded = minRightSubTree(root);
	if(founded != NULL)
		printf("\n 오른쪽 서브트리에서의 최소값: %d\n", founded->key);

	inorder_sort(root);
	printf("\n 정렬 결과: \n");
	for(i = 0; i < MAX_TREE_NODE_NUM; i++) {
		printf("%5d ",list[i]);
		if(i % 5 == 4)
			printf("\n");
	}
}













