#include <stdio.h>

int main() {
  int a[10], n, key, l = 0, r;
  printf("Enter size: ");
  scanf("%d", &n);
  printf("Enter sorted array:\n");
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  printf("Enter key: ");
  scanf("%d", &key);
  r = n - 1;

  while (l <= r) {
    int m = (l + r) / 2;
    if (a[m] == key) {
      printf("Found at %d\n", m);
      return 0;
    }
    if (a[m] < key)
      l = m + 1;
    else
      r = m - 1;
  }
  printf("Not Found\n");
}
