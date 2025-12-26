#include <stdio.h>
int main() {
  int p[20], bt[20], su[20], wt[20], tat[20];
  int i, k, n, temp;

  printf("Enter the number of processes --- ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    p[i] = i;
    printf("Enter the Burst Time of Process %d --- ", i);
    scanf("%d", &bt[i]);
    printf("System/User Process (0=System / 1=User) ? --- ");
    scanf("%d", &su[i]);
  }
  for (i = 0; i < n; i++) {
    for (k = i + 1; k < n; k++) {
      if (su[i] > su[k]) {
        temp = p[i];
        p[i] = p[k];
        p[k] = temp;

        temp = bt[i];
        bt[i] = bt[k];
        bt[k] = temp;

        temp = su[i];
        su[i] = su[k];
        su[k] = temp;
      } else if (su[i] == su[k] && bt[i] > bt[k]) {
        temp = p[i];
        p[i] = p[k];
        p[k] = temp;

        temp = bt[i];
        bt[i] = bt[k];
        bt[k] = temp;

        temp = su[i];
        su[i] = su[k];
        su[k] = temp;
      }
    }
  }
  wt[0] = 0;
  tat[0] = bt[0];
  for (i = 1; i < n; i++) {
    wt[i] = wt[i - 1] + bt[i - 1];
    tat[i] = wt[i] + bt[i];
  }
  printf("\nPROCESS\tSYSTEM/USER\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
  for (i = 0; i < n; i++) {
    printf("P%d\t   %d\t\t   %d\t\t   %d\t\t   %d\n", p[i], su[i], bt[i], wt[i],
           tat[i]);
  }
  return 0;
}
