#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;

void add_begin() {
  struct node *n = malloc(sizeof(*n));
  printf("Enter value: ");
  scanf("%d", &n->data);
  n->next = head;
  head = n;
}

void add_end() {
  struct node *n = malloc(sizeof(*n)), *t = head;
  printf("Enter value: ");
  scanf("%d", &n->data);
  n->next = NULL;

  if (!head) {
    head = n;
    return;
  }
  while (t->next)
    t = t->next;
  t->next = n;
}

void del_begin() {
  if (!head) {
    printf("List Empty\n");
    return;
  }
  struct node *t = head;
  head = head->next;
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
  while (t->next->next)
    t = t->next;
  free(t->next);
  t->next = NULL;
}

void del_value() {
  int x;
  printf("Enter value: ");
  scanf("%d", &x);

  struct node *t = head, *p = NULL;
  while (t && t->data != x) {
    p = t;
    t = t->next;
  }
  if (!t) {
    printf("Value not found\n");
    return;
  }
  if (!p)
    head = t->next;
  else
    p->next = t->next;
  free(t);
}

void display() {
  struct node *t = head;
  if (!t) {
    printf("List Empty\n");
    return;
  }
  while (t) {
    printf("%d -> ", t->data);
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
