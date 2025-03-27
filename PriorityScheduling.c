#include <stdio.h>
int main() {
    int p[20], bt[20], pri[20], wt[20], tat[20], i, k, n, temp;
    float wtavg, tatavg;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    // Input burst time and priority
    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter Burst Time & Priority of Process %d: ", i + 1);
        scanf("%d %d", &bt[i], &pri[i]);
    }
    // Sorting processes based on priority (lower value = higher priority)
    for (i = 0; i < n - 1; i++) {
        for (k = i + 1; k < n; k++) {
            if (pri[i] > pri[k]) {
                // Swap priority
                temp = pri[i];
                pri[i] = pri[k];
                pri[k] = temp;
                // Swap burst time
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;
                // Swap process number
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
        }
    }
    // Calculating Waiting Time & Turnaround Time
    wt[0] = 0;
    wtavg = 0;
    tat[0] = bt[0];
    tatavg = bt[0];
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];  // Waiting time
        tat[i] = wt[i] + bt[i];         // Turnaround time
        wtavg += wt[i];
        tatavg += tat[i];
    }
    // Printing results
    printf("\nPROCESS\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
    for (i = 0; i < n; i++) {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", p[i], pri[i], bt[i], wt[i], tat[i]);
    }
    // Printing average waiting time and turnaround time
    printf("\n\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\nAverage Turnaround Time: %.2f\n", tatavg / n);
    return 0;
}

// Output
// Enter the number of processes: 5
// Enter Burst Time & Priority of Process 1: 10 3
// Enter Burst Time & Priority of Process 2: 1 1
// Enter Burst Time & Priority of Process 3: 2 4 
// Enter Burst Time & Priority of Process 4: 1 5
// Enter Burst Time & Priority of Process 5: 5 2

// PROCESS	PRIORITY	BURST TIME	WAITING TIME	TURNAROUND TIME
// 2		1		1		0		1
// 5		2		5		1		6
// 1		3		10		6		16
// 3		4		2		16		18
// 4		5		1		18		19

// Average Waiting Time: 8.20
// Average Turnaround Time: 12.00
