#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *prev, *next;
};

struct node *head = NULL;

void add_begin() {
  struct node *n = malloc(sizeof(*n));
  printf("Enter value: ");
  scanf("%d", &n->data);

  n->prev = NULL;
  n->next = head;
  if (head)
    head->prev = n;
  head = n;
}

void add_end() {
  struct node *n = malloc(sizeof(*n)), *t = head;
  printf("Enter value: ");
  scanf("%d", &n->data);

  n->next = NULL;
  if (!head) {
    n->prev = NULL;
    head = n;
    return;
  }
  while (t->next)
    t = t->next;
  t->next = n;
  n->prev = t;
}

void del_begin() {
  if (!head) {
    printf("List Empty\n");
    return;
  }
  struct node *t = head;
  head = head->next;
  if (head)
    head->prev = NULL;
  free(t);
}

void del_end() {
  if (!head) {
    printf("List Empty\n");
    return;
  }
  if (!head->next) {
    free(head);
    head = NULL;
    return;
  }
  struct node *t = head;
  while (t->next)
    t = t->next;
  t->prev->next = NULL;
  free(t);
}

void del_value() {
  int x;
  printf("Enter value: ");
  scanf("%d", &x);

  struct node *t = head;
  while (t && t->data != x)
    t = t->next;

  if (!t) {
    printf("Value not found\n");
    return;
  }
  if (t->prev)
    t->prev->next = t->next;
  else
    head = t->next;

  if (t->next)
    t->next->prev = t->prev;
  free(t);
}

void display() {
  struct node *t = head;
  if (!t) {
    printf("List Empty\n");
    return;
  }
  while (t) {
    printf("%d <-> ", t->data);
    t = t->next;
  }
  printf("NULL\n");
}

int main() {
  int choice;
  do {
    printf("\nEnter your choice:\n");
    printf("1: Display\n2: Add at beginning\n3: Add at the end\n");
    printf("4: Delete at beginning\n5: Delete at end\n");
    printf("6: Delete specific value\n7: Exit\nChoice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      display();
      break;
    case 2:
      add_begin();
      break;
    case 3:
      add_end();
      break;
    case 4:
      del_begin();
      break;
    case 5:
      del_end();
      break;
    case 6:
      del_value();
      break;
    }
  } while (choice != 7);
}
