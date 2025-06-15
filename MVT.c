#include <stdio.h>
void MVT(int mem, int p[], int n) {
    for (int i = 0; i < n; i++) {
        if (p[i] <= mem) {
            printf("Process %d allocated\n", i+1);
            mem -= p[i];
        } else {
            printf("Process %d not allocated\n", i+1);
        }
    }
    printf("Remaining Memory: %d\n", mem);
}

int main() {
    int mem, n;
    printf("Enter total memory: ");
    scanf("%d", &mem);
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    int p[n];
    printf("Enter process sizes: ");
    for (int i = 0; i < n; i++) 
        scanf("%d", &p[i]);
    MVT(mem, p, n);
    return 0;
}