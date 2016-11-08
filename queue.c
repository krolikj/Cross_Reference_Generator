#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

queue* initialize(int s){
  queue *q = (queue*)malloc(sizeof(queue));
  q -> first = NULL;
  q -> last = NULL;
  q -> limit = s;
  q -> size = 0;

  return q;
}

void enqueue(queue *q, lineNum *lNum){
  lNum -> prev = NULL;
  if(q -> size == 0){
    q -> first = lNum;
    q -> last = lNum;
  }else{
    q -> last -> prev = lNum;
    q -> last = lNum;
  }
  q -> size++;  
}

lineNum* dequeue(queue *q){
  lineNum *l;
  if(isEmpty(q))
    return NULL;
  l = q -> first;
  q -> first = q -> first -> prev;
  q -> size--;

  return l;
}

int isEmpty(queue *q){
  if(q -> size == 0)
    return TRUE;
  else
    return FALSE;
}

lineNum* createLineNum(int n){
  lineNum *ln = (lineNum*)malloc(sizeof(lineNum));
  ln -> lNum = n;
  return ln;
}
