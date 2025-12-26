#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left, *right;
};

struct node *newNode(int x) {
  struct node *n = malloc(sizeof(*n));
  n->data = x;
  n->left = n->right = NULL;
  return n;
}

struct node *insert(struct node *r, int x) {
  if (!r)
    return newNode(x);
  if (x < r->data)
    r->left = insert(r->left, x);
  else if (x > r->data)
    r->right = insert(r->right, x);
  return r;
}

void search(struct node *r, int x) {
  if (!r) {
    printf("Not Found\n");
    return;
  }
  if (r->data == x) {
    printf("Found\n");
    return;
  }
  if (x < r->data)
    search(r->left, x);
  else
    search(r->right, x);
}

struct node *findMin(struct node *r) {
  while (r->left)
    r = r->left;
  return r;
}

struct node *deleteNode(struct node *r, int x) {
  if (!r)
    return r;

  if (x < r->data)
    r->left = deleteNode(r->left, x);
  else if (x > r->data)
    r->right = deleteNode(r->right, x);
  else {
    if (!r->left) {
      struct node *t = r->right;
      free(r);
      return t;
    }
    if (!r->right) {
      struct node *t = r->left;
      free(r);
      return t;
    }
    struct node *t = findMin(r->right);
    r->data = t->data;
    r->right = deleteNode(r->right, t->data);
  }
  return r;
}

void inorder(struct node *r) {
  if (r) {
    inorder(r->left);
    printf("%d ", r->data);
    inorder(r->right);
  }
}

int main() {
  struct node *root = NULL;
  int ch, x;

  do {
    printf("\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\nChoice: ");
    scanf("%d", &ch);

    switch (ch) {
    case 1:
      printf("Enter value: ");
      scanf("%d", &x);
      root = insert(root, x);
      break;

    case 2:
      printf("Enter value: ");
      scanf("%d", &x);
      search(root, x);
      break;

    case 3:
      printf("Enter value: ");
      scanf("%d", &x);
      root = deleteNode(root, x);
      break;

    case 4:
      inorder(root);
      printf("\n");
      break;
    }
  } while (ch != 5);
}
