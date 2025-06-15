#include <stdio.h>
int findOptimal(int f[], int p[], int n, int i) {
    int j, k, far = -1, pos = -1;
    for (j = 0; j < 3; j++) {
        for (k = i + 1; k < n && f[j] != p[k]; k++);
        if (k == n) 
            return j;
        if (k > far) {
            far = k;
            pos = j;
        }
    }
    return pos;
}

int main() {
    int p[] = {7, 0, 1, 2, 0, 3, 4, 2, 3, 0};
    int f[3] = {-1, -1, -1}, i, j, c = 0;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 3 && f[j] != p[i]; j++);
        if (j == 3) {
            f[findOptimal(f, p, 10, i)] = p[i];
            c++;
        }
    }
    printf("Optimal Page-faults: %d\n", c);
    return 0;
}
