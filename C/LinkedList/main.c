#include <stdio.h>
#include "./lib/LinkedList.h"

#include <string.h>

typedef struct {
  int key;
  char name[10];
} People;


int main() {
  LinkedList ll;
  People people[4];
  
  people[0].key = 5;
  strcpy(people[0].name, "name 1");

  people[1].key = 10;
  strcpy(people[1].name, "name 2");

  people[2].key = 15;
  strcpy(people[2].name, "name 3");


  linkedListInit(&ll, sizeof(People));
  linkedListInsertAt(&ll, 0, &people[0]);
  linkedListInsertAt(&ll, 1, &people[1]);
  linkedListInsertAt(&ll, 2, &people[2]);

  linkedListAt(&ll, 2, &people[3]);

  printf("%d %s\n\n", people[3].key, people[3].name);
  

  return 0;
}
