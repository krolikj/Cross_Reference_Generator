#include "list.h"
#include <stdlib.h>
#include <stdio.h>

list* createList(){
  list *l = (list*)malloc(sizeof(list));
  l -> head = NULL;
  return l;
}

void addNode(char *n, list *l){
  node *cur = NULL;
  node *nde = (node*)malloc(sizeof(node));
  if(l -> head == NULL){
    nde -> name = n;
    nde -> next = NULL;
    nde -> q = NULL;
  }else{
    cur = l -> head;
    while(cur -> next != NULL)
      cur = cur -> next;
    nde -> name = n;
    nde -> next = NULL;
    nde -> q = NULL;
  }
}

void removeNode(char *n, list *l){
  node *cur = l -> head;
  node *prev = cur;
  while(cur != NULL){
    if(cur -> name == n){
      prev ->next = cur -> next;
      if(cur == l -> head)
        l  -> head = cur -> next;
      free(cur);
      break;
    }
    prev = cur;
    cur = cur -> next;
  }
}

int nodeExists(char *n, list *l){
  node *cur = l -> head;
  while(cur != NULL){
    if(cur -> name == n)
      return TRUE;
    cur = cur -> next;
  }
  return FALSE;
}

void destroyList(list *l){
  node *cur = l -> head;
  node *next = cur;
  while( cur != NULL){
    next = cur -> next;
    free(cur);
    cur = next;
  }
  free(l);
}
