#include <stdio.h>

int main() {
    char dirName[20], files[10][20];
    int n, i;
    printf("Enter directory name: ");
    scanf("%s", dirName);
    printf("Enter number of files: ");
    scanf("%d", &n);
    printf("Enter file names:\n");
    for (i = 0; i < n; i++)
        scanf("%s", files[i]);
    printf("\nDirectory: %s\nFiles:\n", dirName);
    for (i = 0; i < n; i++)
        printf("  %s\n", files[i]);
    return 0;
}
