#include <stdio.h>

int main() {
    char user[10][20], files[10][10][20];
    int u, f, i, j, count[10];
    printf("Enter number of users: ");
    scanf("%d", &u);
    for (i = 0; i < u; i++) {
        printf("Enter username: ");
        scanf("%s", user[i]);
        printf("Enter number of files for %s: ", user[i]);
        scanf("%d", &count[i]);
        printf("Enter file names:\n");
        for (j = 0; j < count[i]; j++)
            scanf("%s", files[i][j]);
    }
    printf("\n--- Two Level Directory ---\n");
    for (i = 0; i < u; i++) {
        printf("User: %s\n", user[i]);
        for (j = 0; j < count[i]; j++)
            printf("  %s\n", files[i][j]);
    }
    return 0;
}
