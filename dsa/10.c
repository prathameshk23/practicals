#include <stdio.h>

int partition(int a[], int l, int h) {
  int p = a[h], i = l - 1;
  for (int j = l; j < h; j++)
    if (a[j] < p) {
      i++;
      int t = a[i];
      a[i] = a[j];
      a[j] = t;
    }
  int t = a[i + 1];
  a[i + 1] = a[h];
  a[h] = t;
  return i + 1;
}

void quicksort(int a[], int l, int h) {
  if (l < h) {
    int pi = partition(a, l, h);
    quicksort(a, l, pi - 1);
    quicksort(a, pi + 1, h);
  }
}

int main() {
  int a[10], n;
  printf("Enter size: ");
  scanf("%d", &n);
  printf("Enter elements:\n");
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  quicksort(a, 0, n - 1);

  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
}
