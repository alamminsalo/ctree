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

void insert(Node**,int);
void deleteNode(Node*);
void deleteTree(Node**);
void printNode(Node*,int);
void printTree(Node*);
void printAscending(Node*);
void printDescending(Node*);

#endif /*TREE_H*/
