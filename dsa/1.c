#include <stdio.h>
#define N 5

int stack[N], top = -1;

void push() {
  int x;
  if (top == N - 1)
    printf("Stack Overflow\n");
  else {
    printf("Enter value: ");
    scanf("%d", &x);
    stack[++top] = x;
  }
}

void pop() {
  if (top == -1)
    printf("Stack Underflow\n");
  else
    printf("Popped: %d\n", stack[top--]);
}

void peek() {
  if (top == -1) {
    printf("Stack Is Empty\n");
  } else {
    printf("Top of the stack %d\n", stack[top]);
  }
}

void display() {
  for (int i = top; i >= 0; i--)
    printf("%d ", stack[i]);
  printf("\n");
}

int main() {
  int ch;
  do {
    printf("1.Push 2.Pop 3.Peek 4.Display 0.Exit\n");
    scanf("%d", &ch);
    if (ch == 1)
      push();
    else if (ch == 2)
      pop();
    else if (ch == 3)
      peek();
    else if (ch == 4)
      display();
  } while (ch != 0);
}
