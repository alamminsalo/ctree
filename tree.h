#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Nodes{
	int data;
	struct Nodes *left;
	struct Nodes *right;
}Node;

void insert(Node **ptr, int data){
	if (!(*ptr)){
		(*ptr) = malloc(sizeof(Node));
		(*ptr)->data = data;
		(*ptr)->left = 0;
		(*ptr)->right = 0;
	}
	else {
		ptr = data <= (*ptr)->data ? &(*ptr)->left : &(*ptr)->right;
		insert(ptr,data);
	}
}

void deleteNode(Node *node){
	if (node){
		deleteNode(node->left);
		deleteNode(node->right);	
		free(node);
		node = 0;
	}
}
void deleteTree(Node **root){
	deleteNode(*root);
	*root = 0;
	printf("DELETED TREE\n");
}

void printNode(Node *node, int level){
	char *str = malloc(2*level+2);
	for (int i=0; i<level; i++){
		strcat(str,"  ");	
	}
	if (level) strcat(str,"\\");
	strcat(str,"\0");
	if (node){
		printf("\n%s%d",str,node->data);
		printf(" level: %d",level);
		printNode(node->left, level+1);
		printNode(node->right, level+1);
	}
}

void printTree(Node *node){
	printNode(node,0);
}

void printAscending(Node *node){
	if (node){
		printAscending(node->left);
		printf(", %d",node->data);
		printAscending(node->right);
	}
}

void printDescending(Node *node){
	if (node){
		printDescending(node->right);
		printf(", %d",node->data);
		printDescending(node->left);
	}
}


#endif /*TREE_H*/
