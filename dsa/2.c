#include <stdio.h>
#define N 5

int q[N], front = -1, rear = -1;

void enqueue() {
  int x;
  if (rear == N - 1)
    printf("Queue Full\n");
  else {
    printf("Enter value: ");
    scanf("%d", &x);
    if (front == -1)
      front = 0;
    q[++rear] = x;
    printf("Added: %d\n", x);
  }
}

void dequeue() {
  if (front == -1 || front > rear)
    printf("Queue Empty\n");
  else
    printf("Removed: %d\n", q[front++]);
}

void display() {
  for (int i = front; i <= rear; i++)
    printf("%d ", q[i]);
  printf("\n");
}

int main() {
  int ch;
  do {
    printf("\n1.Enqueue 2.Dequeue 3.Display 0.Exit\n");
    scanf("%d", &ch);
    if (ch == 1)
      enqueue();
    else if (ch == 2)
      dequeue();
    else if (ch == 3)
      display();
  } while (ch != 0);
}
