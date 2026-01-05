#include <stdio.h>
#define N 5

int q[N], front = -1, rear = -1;

void enqueue() {
  int x;
  if ((rear + 1) % N == front)
    printf("Queue Full\n");
  else {
    printf("Enter value: ");
    scanf("%d", &x);
    if (front == -1)
      front = 0;
    rear = (rear + 1) % N;
    q[rear] = x;
    printf("Added: %d\n", q[rear]);
  }
}

void dequeue() {
  if (front == -1)
    printf("Queue Empty\n");
  else {
    printf("Removed: %d\n", q[front]);
    if (front == rear)
      front = rear = -1;
    else
      front = (front + 1) % N;
  }
}

void display() {
  if (front == -1) {
    printf("Queue is empty\n");
    return;
  }
  printf("Queue elements: ");
  int i = front;
  while (1) {
    printf("%d ", q[i]);
    if (i == rear)
      break;
    i = (i + 1) % N;
  }
  printf("\n");
}

int main() {
  int ch;
  do {
    printf("1.Enqueue 2.Dequeue 3.Display 0.Exit\n");
    scanf("%d", &ch);
    if (ch == 1)
      enqueue();
    else if (ch == 2)
      dequeue();
    else if (ch == 3)
      display();
  } while (ch != 0);
}
