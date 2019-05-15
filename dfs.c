/*
  DEPTH-FIRST SEARCH
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct Number {
  int val;
  struct Number *next;
};

void pushNumber(struct Number *head, int val) {
  struct Number *current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = (struct Number *)malloc(sizeof(struct Number));
  current->next->val = val;
  current->next->next = NULL;
}

int popNumber(struct Number *head) {
  struct Number *current = head;
  int popped;
  while (current->next->next != NULL) {
    current = current->next;
  }
  popped = current->next->val;
  free(current->next->next);
  current->next = NULL;
  return popped;
}

int peekNumber(struct Number *head) {
  struct Number *current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  return current->val;
}

void printStack(struct Number *head) {
  struct Number *current = head;
  printf("Stack : ");
  while (current->next != NULL) {
    current = current->next;
    printf("%d ", current->val);
  }
  printf("\n");
}

void DFS(int gr[SIZE][SIZE], int node, int visited[], struct Number *head) {
  static int i;
  pushNumber(head, node);
  visited[node] = 1;
  printStack(head);
  printf("VISITED ARRAY : ");
  for (int k = 0; k < SIZE; k++) {
    printf("%d ", visited[k]);
  }
  printf("\n");
  for (i = 0; i < SIZE; i++) {
    if (gr[node][i] == 1) {
      if (visited[i] == 0)
        DFS(gr, i, visited, head);
      else
        popNumber(head);
    }
  }
}

int main() {
  struct Number *headNumber;  // stack
  headNumber = (struct Number *)malloc(sizeof(struct Number));
  if (headNumber == NULL) {
    printf("Memory could not allocated.");
    return 0;
  }
  headNumber->next = NULL;

  int gr[SIZE][SIZE] = {
      {0, 1, 1, 0, 0},
      {1, 0, 0, 0, 0},
      {1, 0, 0, 1, 1},
      {0, 0, 1, 0, 1},
      {0, 0, 1, 1, 0}};
  static int visited[SIZE];

  DFS(gr, 1, visited, headNumber);

  return 0;
}