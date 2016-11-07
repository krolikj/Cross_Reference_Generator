#ifndef QUEUE_H
#define QUEUE_H

#define TRUE 1
#define FALSE 0
struct lineNum{
  int lNum;  
  struct lineNum *prev;
};

typedef struct lineNum lineNum;

struct queue{
  lineNum *first;
  lineNum *last;
  int size;
  int limit;
};

typedef struct queue queue;

queue* initialize(int s);
void enqueue(queue *q, lineNum *lNum);
lineNum* dequeue(queue *q);
int isEmpty(queue *q);

#endif
