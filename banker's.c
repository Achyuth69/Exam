#include <stdio.h> 
#include <stdio.h>
int main() {
  int n = 3, avail = 3, max[3] = {3, 2, 2}, alloc[3] = {1, 1, 1}, need[3], finish[3] = {0}, safe[3], i, j, k = 0;
  for (i = 0; i < n; i++) need[i] = max[i] - alloc[i];
  for (i = 0; i < n; i++) for (j = 0; j < n; j++)
    if (!finish[j] && need[j] <= avail) {
      avail += alloc[j];
      safe[k++] = j;
      finish[j] = 1;
      i = -1;
    }
  for (i = 0; i < n && finish[i]; i++);
  if (i == n) { printf("Safe: "); for (i = 0; i < n; i++) printf("%d ", safe[i]); }
  else puts("Not safe");
}