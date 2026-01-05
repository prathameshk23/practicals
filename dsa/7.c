#include <stdio.h>

#define MAX 10

int adj[MAX][MAX], visited[MAX];
int n;

void addEdge() {
  int u, v;
  printf("Enter source and destination: ");
  scanf("%d %d", &u, &v);
  adj[u][v] = 1;
  adj[v][u] = 1;
}

void display() {
  printf("Adjacency Matrix:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      printf("%d ", adj[i][j]);
    printf("\n");
  }
}

void bfs() {
  int q[MAX], front = 0, rear = -1, start;

  for (int i = 0; i < n; i++)
    visited[i] = 0;

  printf("Enter start vertex: ");
  scanf("%d", &start);

  q[++rear] = start;
  visited[start] = 1;

  printf("BFS Traversal: ");
  while (front <= rear) {
    int v = q[front++];
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
      if (adj[v][i] && !visited[i]) {
        visited[i] = 1;
        q[++rear] = i;
      }
    }
  }
  printf("\n");
}

int main() {
  int choice;

  printf("Enter number of vertices: ");
  scanf("%d", &n);

  do {
    printf("\n1. Add Edge\n");
    printf("2. Display Graph\n");
    printf("3. Perform BFS\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      addEdge();
      break;
    case 2:
      display();
      break;
    case 3:
      bfs();
      break;
    }
  } while (choice != 4);
}
