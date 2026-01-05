#include <stdio.h>

int main() {
  int n, bt[10], wt[10], tat[10];
  float awt = 0, atat = 0;

  printf("Enter number of processes: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("Enter burst time of P%d: ", i + 1);
    scanf("%d", &bt[i]);
  }

  wt[0] = 0;
  for (int i = 1; i < n; i++)
    wt[i] = wt[i - 1] + bt[i - 1];

  for (int i = 0; i < n; i++) {
    tat[i] = wt[i] + bt[i];
    awt += wt[i];
    atat += tat[i];
  }

  printf("\nProcess  BT  WT  TAT\n");
  for (int i = 0; i < n; i++)
    printf("P%d       %d   %d   %d\n", i + 1, bt[i], wt[i], tat[i]);

  printf("\nAverage WT = %.2f", awt / n);
  printf("\nAverage TAT = %.2f\n", atat / n);
}
