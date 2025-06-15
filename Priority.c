#include <stdio.h>
void priority(int n, int p[], int bT[], int pr[], int wT[], int Tat[]) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (pr[i] > pr[j]) {
                int temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;
                temp = bT[i];
                bT[i] = bT[j];
                bT[j] = temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
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
    int p[n], bT[n], pr[n], wT[n], Tat[n];
    for (int i = 0; i < n; i++) 
        p[i] = i + 1;
    printf("Enter burst times: ");
    for (int i = 0; i < n; i++) 
        scanf("%d", &bT[i]);
    printf("Enter priorities: ");
    for (int i = 0; i < n; i++) 
        scanf("%d", &pr[i]);
    priority(n, p, bT, pr, wT, Tat);
    float awt = 0, atat = 0;
    for (int i = 0; i < n; i++) {
        awt += wT[i];
        atat += Tat[i];
    }
    awt /= n; 
    atat /= n;
    printf("Process\tPriority\tBT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\n", p[i], pr[i], bT[i], Tat[i], wT[i]);
    printf("AWT: %.2f\nATAT: %.2f\n", awt, atat);
    return 0;
}
