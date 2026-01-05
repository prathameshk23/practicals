#include <stdio.h>

int isHit(int frames[], int fn, int page) {
  for (int i = 0; i < fn; i++)
    if (frames[i] == page)
      return 1;
  return 0;
}

void printFrames(int frames[], int fn) {
  for (int i = 0; i < fn; i++) {
    if (frames[i] == -1)
      printf("- ");
    else
      printf("%d ", frames[i]);
  }
}

/* FIFO */
void fifo(int pages[], int pn, int fn) {
  int frames[10], faults = 0, k = 0;

  for (int i = 0; i < fn; i++)
    frames[i] = -1;

  printf("\nFIFO Page Replacement\n");
  printf("Page\tFrames\t\tStatus\n");

  for (int i = 0; i < pn; i++) {
    printf("%d\t", pages[i]);

    if (!isHit(frames, fn, pages[i])) {
      frames[k] = pages[i];
      k = (k + 1) % fn;
      faults++;
      printFrames(frames, fn);
      printf("\tFault\n");
    } else {
      printFrames(frames, fn);
      printf("\tHit\n");
    }
  }
  printf("Total Page Faults = %d\n", faults);
}

/* LRU */
void lru(int pages[], int pn, int fn) {
  int frames[10], time[10], faults = 0;

  for (int i = 0; i < fn; i++) {
    frames[i] = -1;
    time[i] = 0;
  }

  printf("\nLRU Page Replacement\n");
  printf("Page\tFrames\t\tStatus\n");

  for (int i = 0; i < pn; i++) {
    printf("%d\t", pages[i]);
    int hit = 0;

    for (int j = 0; j < fn; j++) {
      if (frames[j] == pages[i]) {
        time[j] = i;
        hit = 1;
        break;
      }
    }

    if (!hit) {
      int pos = 0, min = time[0];
      for (int j = 1; j < fn; j++)
        if (frames[j] == -1 || time[j] < min) {
          min = time[j];
          pos = j;
        }

      frames[pos] = pages[i];
      time[pos] = i;
      faults++;
      printFrames(frames, fn);
      printf("\tFault\n");
    } else {
      printFrames(frames, fn);
      printf("\tHit\n");
    }
  }
  printf("Total Page Faults = %d\n", faults);
}

/* Optimal */
void optimal(int pages[], int pn, int fn) {
  int frames[10], faults = 0;

  for (int i = 0; i < fn; i++)
    frames[i] = -1;

  printf("\nOptimal Page Replacement\n");
  printf("Page\tFrames\t\tStatus\n");

  for (int i = 0; i < pn; i++) {
    printf("%d\t", pages[i]);

    if (!isHit(frames, fn, pages[i])) {
      int pos = -1, farthest = i + 1;

      for (int j = 0; j < fn; j++) {
        int k;
        for (k = i + 1; k < pn; k++)
          if (frames[j] == pages[k])
            break;

        if (k == pn) {
          pos = j;
          break;
        }
        if (k > farthest) {
          farthest = k;
          pos = j;
        }
      }

      if (pos == -1)
        pos = 0;

      frames[pos] = pages[i];
      faults++;
      printFrames(frames, fn);
      printf("\tFault\n");
    } else {
      printFrames(frames, fn);
      printf("\tHit\n");
    }
  }
  printf("Total Page Faults = %d\n", faults);
}

int main() {
  int pages[20], pn, fn;

  printf("Enter number of pages: ");
  scanf("%d", &pn);

  printf("Enter page reference string:\n");
  for (int i = 0; i < pn; i++)
    scanf("%d", &pages[i]);

  printf("Enter number of frames: ");
  scanf("%d", &fn);

  fifo(pages, pn, fn);
  lru(pages, pn, fn);
  optimal(pages, pn, fn);

  return 0;
}
