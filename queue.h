#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct node {
   int key;
   int value;
   struct node *next;
} NODE;

typedef struct queue {
   NODE *begin;
   NODE *end;
   int size;
} QUEUE;

void freeNode(NODE *);
void printNode(NODE *);

QUEUE *createQueue();
int empty(QUEUE *);
void printQueueNor(QUEUE *);
void printQueueInv(QUEUE *);
int push(QUEUE *, int, int);
NODE *pop(QUEUE *);
int destroyQueue(QUEUE *);

#endif
