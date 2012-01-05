#include <stdio.h>
#include <stdlib.h>

//structure for holding the nodes of linked list

struct listnode{
	struct listnode *next;
	int data;
};

typedef struct listnode node;

void insertNodeLast(node **, int);
void insertNodeFirst(node **, int);
void insertAtIndex(node **, int, int);
void printList(node *);
void createList(node **, int *, int);
void frontBackSplit(node **, node **);
void alternatingSplit(node *, node **, node **);
void sortedMerge(node *, node *, node **);
