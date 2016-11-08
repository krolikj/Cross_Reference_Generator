/**********************************************************
 * Josh Krolik
 * CIS361
 * Project 2
**********************************************************/

#include "queue.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MaxSize 100

int
main(int argc, char *argv[])
{
  FILE *in;
  char ch;
  char identifier[20];
  int i = 0;
  int lineCount = 0;
  int isIdentifier = FALSE;
  list *myList = malloc(sizeof(list));;
  myList -> head = NULL;

  if(argc != 2){
    printf("Enter a filename\n");
    exit(1);
  }
  in = fopen(argv[1], "r");

  while(!feof(in)){
    fscanf(in, "%c", &ch);

    if(!isIdentifier){
      if(isalpha(ch) || ch == '_'){
	isIdentifier = TRUE;
	identifier[i] = ch;
        i++;
      }
    }
    else{
      if(isalnum(ch) || ch == '_'){
	identifier[i] = ch;
	i++;
      }
      else{
	isIdentifier = FALSE;
	identifier[i] = '\0';
	i = 0;
	if(nodeExists(identifier, myList)){
	}
	else{
	  lineNum *ln = createLineNum(lineCount);
	  node *tempN = addNode(identifier, myList);
	  node *cur = myList -> head;
	  while(cur -> next != NULL){
	    cur = cur -> next;
	  }
	  queue *tempQ = initialize(MaxSize);
	  tempN -> q = tempQ;
	  enqueue(tempN -> q, ln);
	} 
      }
    }

    if(ch == '\n')
      lineCount++;
  }
  node *current = myList -> head;
 
  while(current -> next != NULL){
    printf("%s\n", current -> name);
      while(current -> q -> first -> prev != NULL){
        printf("\t%i\n", current -> q -> first -> lNum);
        dequeue(current -> q);
      }
      printf("\t%i\t", current -> q -> first -> lNum);
    current = current -> next;
  }
  printf("%s\n", current -> name);
  
  fclose(in);

  return 0;
}
