#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct {
  int qu[SIZE];
  int rear;
} QUEUE;

void init(QUEUE *queue) {
  queue->rear = 0;
}

int isQueueEmpty(QUEUE *queue) {
  if (queue->rear == 0)
    return 1;
  return 0;
}

int enqueue(QUEUE *queue, int item) {
  queue->qu[queue->rear] = item;
  queue->rear++;
  return 1;
}

int dequeue(QUEUE *queue) {
  if (isQueueEmpty(queue))
    return 0;
  int i, item;
  item = queue->qu[0];
  for (i = 1; i < queue->rear; i++) {
    queue->qu[i - 1] = queue->qu[i];
  }
  queue->rear--;
  return item;
}

void printQueue(QUEUE *queue) {
  int i;
  printf("QUEUE : ");
  for (i = 0; i < queue->rear; i++) {
    printf("%d ", queue->qu[i]);
  }
  printf("\n");
}

void BFS(int gr[SIZE][SIZE], int node, int visited[], QUEUE *queue) {
  int i;
  int n;
  enqueue(queue, node);
  visited[node] = 1;
  while (isQueueEmpty(queue) != 1) {
    printQueue(queue);
    printf("VISITED ARRAY : ");
    for (int k = 0; k < SIZE; k++) {
      printf("%d ", visited[k]);
    }
    printf("\n");
    n = dequeue(queue);
    for (i = 0; i < SIZE; i++) {
      if (gr[n][i] == 1) {
        if (visited[i] == 0) {
          enqueue(queue, i);
          visited[i] = 1;
        }
      }
    }
  }
}

int main() {
  QUEUE *queue = (QUEUE *)malloc(sizeof(QUEUE));
  init(queue);
  int gr[SIZE][SIZE] = {
      {0, 1, 1, 0, 0},
      {1, 0, 0, 0, 0},
      {1, 0, 0, 1, 1},
      {0, 0, 1, 0, 1},
      {0, 0, 1, 1, 0}};
  static int visited[SIZE];

  BFS(gr, 1, visited, queue);

  return 0;
}