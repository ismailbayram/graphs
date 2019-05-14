#include <stdio.h>
#include <stdlib.h>
#define SIZE 9

typedef struct {
  int u, v, w;
} Edge;

void inputGraph(Edge gr[]) {
  // create graph manually instead of redundant input jobs.
  gr[0].u = 1;
  gr[0].v = 2;
  gr[0].w = 4;
  gr[1].u = 1;
  gr[1].v = 3;
  gr[1].w = 1;
  gr[2].u = 1;
  gr[2].v = 4;
  gr[2].w = 1;
  gr[3].u = 2;
  gr[3].v = 3;
  gr[3].w = 2;
  gr[4].u = 3;
  gr[4].v = 4;
  gr[4].w = 8;
  gr[5].u = 3;
  gr[5].v = 5;
  gr[5].w = 2;
  gr[6].u = 4;
  gr[6].v = 5;
  gr[6].w = 5;
  gr[7].u = 4;
  gr[7].v = 6;
  gr[7].w = 7;
  gr[8].u = 5;
  gr[8].v = 6;
  gr[8].w = 3;
}

void printGraph(Edge gr[], char *title, int size) {
  int i;
  printf("\n--GRAPH %s--\n", title);
  for (i = 0; i < size; i++) {
    printf("%d - %d (%d)\n", gr[i].u, gr[i].v, gr[i].w);
  }
}

void sortGraph(Edge gr[]) {
  int i = 1, j;
  Edge temp;
  while (i < SIZE) {
    j = i;
    while (j > 0) {
      if (gr[j - 1].w > gr[j].w) {
        temp = gr[j - 1];
        gr[j - 1] = gr[j];
        gr[j] = temp;
      }
      j--;
    }
    i++;
  }
}

int main() {
  Edge gr[SIZE], *kruskal;
  static int visited[SIZE];
  int i, k = 0;
  inputGraph(gr);
  printGraph(gr, "PURE", SIZE);
  sortGraph(gr);
  printGraph(gr, "SORTED", SIZE);

  kruskal = (Edge *)malloc(0 * sizeof(Edge));

  for (i = 0; i < SIZE; i++) {
    if (visited[gr[i].u] + visited[gr[i].v] != 2) {  // unless both 2 nodes are visited
      kruskal = (Edge *)realloc(kruskal, (k + 1) * sizeof(Edge));
      kruskal[k].u = gr[i].u;
      kruskal[k].v = gr[i].v;
      kruskal[k].w = gr[i].w;
      k++;
      if (visited[gr[i].u] == 0) {
        visited[gr[i].u] = 1;
      } else {
        visited[gr[i].v] = 1;
      }
    }
  }

  printGraph(kruskal, "KRUSKAL", k);
  return 0;
}