#include <stdio.h>

int main() {
  int n, bt[10], wt[10], tat[10], p[10];
  float awt = 0, atat = 0;

  printf("Enter number of processes: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    p[i] = i + 1;
    printf("Enter burst time of P%d: ", p[i]);
    scanf("%d", &bt[i]);
  }

  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
      if (bt[i] > bt[j]) {

        int t = bt[i];
        bt[i] = bt[j];
        bt[j] = t;

        t = p[i];
        p[i] = p[j];
        p[j] = t;
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
    printf("P%d       %d   %d   %d\n", p[i], bt[i], wt[i], tat[i]);

  printf("\nAverage WT = %.2f", awt / n);
  printf("\nAverage TAT = %.2f\n", atat / n);
}
