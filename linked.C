#include <stdio.h>
struct file {
    char fname[10];
    int start, size, block[10];
} f[10];
int main() {
    int i, j, n;
    printf("Enter number of files: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter file name: ");
        scanf("%s", f[i].fname);
        printf("Enter starting block: ");
        scanf("%d", &f[i].start);
        f[i].block[0] = f[i].start;
        printf("Enter number of blocks: ");
        scanf("%d", &f[i].size);
        printf("Enter block numbers: ");
        for (j = 1; j < f[i].size; j++) {
            scanf("%d", &f[i].block[j]);
        }
    }
    printf("\nFile\tStart\tSize\tBlocks\n");
    for (i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t", f[i].fname, f[i].start, f[i].size);
        for (j = 0; j < f[i].size - 1; j++) {
            printf("%d--->", f[i].block[j]);
        }
        printf("%d\n", f[i].block[j]);
    }
    return 0;
}