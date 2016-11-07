#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

struct node {
  char *name;
  struct node *next;
  struct queue *q;
};

typedef struct node node;

struct list {
  node *head;
};

typedef struct list list;

list* createList();
void addNode(char *n, list *l);
void removeNode(char *n, list *l);
int nodeExists(char *n, list *l);
void destroyList(list *l);

#endif
