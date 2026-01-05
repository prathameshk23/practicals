#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, hungry, h[10], i, j, ch;

  printf("Dining Philosopher Problem\n");
  printf("Enter number of philosophers: ");
  scanf("%d", &n);

  printf("Enter number of hungry philosophers: ");
  scanf("%d", &hungry);

  if (hungry == n) {
    printf("\nAll philosophers are hungry → Deadlock occurs\n");
    return 0;
  }

  for (i = 0; i < hungry; i++) {
    printf("Enter hungry philosopher %d (1-%d): ", i + 1, n);
    scanf("%d", &h[i]);
  }

  while (1) {
    printf("\n1. One philosopher eats\n");
    printf("2. Two philosophers eat (non-neighbors)\n");
    printf("3. Exit\nEnter choice: ");
    scanf("%d", &ch);

    if (ch == 1) {
      printf("\n-- One philosopher at a time --\n");
      for (i = 0; i < hungry; i++)
        printf("Philosopher %d is eating\n", h[i]);
    }

    else if (ch == 2) {
      printf("\n-- Two philosophers eating together --\n");
      for (i = 0; i < hungry; i++)
        for (j = i + 1; j < hungry; j++)
          if (abs(h[i] - h[j]) != 1 && abs(h[i] - h[j]) != n - 1)
            printf("Philosophers %d and %d are eating\n", h[i], h[j]);
    }

    else if (ch == 3)
      exit(0);

    else
      printf("Invalid choice\n");
  }
}
