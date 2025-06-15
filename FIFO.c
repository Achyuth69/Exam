#include <stdio.h>
int main() {
    int p[] = {7, 0, 1, 2, 0, 3, 4, 2, 3, 0,}, f[3] = {-1, -1, -1}, i, j, k = 0, c = 0;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 3; j++) if (f[j] == p[i]) break;
        if (j == 3) f[k = (k + 1) % 3] = p[i], c++;
    }
    printf("FIFO_pagefaults: %d\n",c);
}