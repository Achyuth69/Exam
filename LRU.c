#include <stdio.h>
int main() {
    int p[] = {7, 0, 1, 2, 0, 3, 4, 2, 3, 0};
    int f[3] = {-1, -1, -1}, r[3], i, j, k, c = 0;
    for (i = 0; i < 3; i++) 
        r[i] = -1;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 3; j++) {
            if (f[j] == p[i]) {
                r[j] = i;
                break;
            }
        }
        if (j == 3) {
            for (j = 0, k = 0; j < 3; j++) {
                if (r[j] < r[k]) 
                    k = j;
            }
            f[k] = p[i];
            r[k] = i;
            c++;
        }
    }
    printf("LRU Page-faults: %d\n", c);
    return 0;
}
