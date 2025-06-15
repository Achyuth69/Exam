#include <stdio.h>
void FCFS(int n, int bT[], int wT[], int Tat[]) {
    wT[0] = 0;
    for (int i = 1; i < n; i++) 
        wT[i] = wT[i-1] + bT[i-1];
    for (int i = 0; i < n; i++) 
        Tat[i] = wT[i] + bT[i];
}

int main() {
    int n;
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    int bT[n], wT[n], Tat[n];
    printf("Enter burst Times: ");
    for (int i = 0; i < n; i++) 
        scanf("%d", &bT[i]);
    FCFS(n, bT, wT, Tat);
    float awt = 0, atat = 0;
    for (int i = 0; i < n; i++) {
        awt += wT[i];
        atat += Tat[i];
    }
    awt /= n; 
    atat /= n;
    printf("Process\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\n", i+1, bT[i], wT[i], Tat[i]);
    printf("AWT: %.2f\nATAT: %.2f\n", awt, atat);
    return 0;
}
