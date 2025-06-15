#include <stdio.h>
void RR(int n, int bT[], int q, int wT[], int Tat[]) {
    int t = 0, rbT[n];
    for (int i = 0; i < n; i++) 
        rbT[i] = bT[i];
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (rbT[i] > 0) {
                done = 0;
                if (rbT[i] > q) {
                    t += q;
                    rbT[i] -= q;
                } else {
                    t += rbT[i];
                    wT[i] = t - bT[i];
                    Tat[i] = t;
                    rbT[i] = 0;
                }
            }
        }
        if (done) break;
    }
}

int main() {
    int n, q;
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    printf("Enter time Quantum: ");
    scanf("%d", &q);
    int bT[n], wT[n], Tat[n];
    printf("Enter burst Times: ");
    for (int i = 0; i < n; i++) 
        scanf("%d", &bT[i]);
    RR(n, bT, q, wT, Tat);
    float awt = 0, atat = 0;
    for (int i = 0; i < n; i++) {
        awt += wT[i];
        atat += Tat[i];
    }
    awt /= n; 
    atat /= n;
    printf("Process\tBT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\n", i+1, bT[i], Tat[i], wT[i]);
    printf("AWT: %.2f\nATAT: %.2f\n", awt, atat);
    return 0;
}
