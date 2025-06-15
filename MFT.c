#include <stdio.h>

void MFT(int mem, int bs, int p[], int n) {
    int nb = mem / bs;
    for (int i = 0; i < n; i++)
        printf("Process %d %s\n", i + 1, (p[i] <= bs && nb--) ? "allocated" : "not allocated");
    printf("Remaining Blocks: %d\n", nb);
}

int main() {
    int mem, bs, n;
    printf("Enter total memory, block size, no. of processes: \n");
    scanf("%d %d %d", &mem, &bs, &n);
    int p[n];
    printf("Enter process sizes: \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    MFT(mem, bs, p, n);
    return 0;
}
