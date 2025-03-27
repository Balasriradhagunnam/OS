#include <stdio.h>
int main() {
    int p[20], bt[20], wt[20], tat[20], i, k, n, temp;
    float wtavg, tatavg;
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    // Taking burst time input and initializing process numbers
    for (i = 0; i < n; i++) {
        p[i] = i;
        printf("Enter Burst Time for Process %d: ", i);
        scanf("%d", &bt[i]);
    }
    // Sorting processes based on burst time (SJF Scheduling)
    for (i = 0; i < n - 1; i++) {
        for (k = i + 1; k < n; k++) {
            if (bt[i] > bt[k]) {
                // Swap burst times
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;

                // Swap process numbers
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
        }
    }
    // Calculating waiting time and turnaround time
    wt[0] = 0;
    wtavg = 0;
    tat[0] = bt[0];
    tatavg = bt[0];
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];  // Waiting time calculation
        tat[i] = wt[i] + bt[i];         // Correct turnaround time calculation
        wtavg += wt[i];
        tatavg += tat[i];
    }
    // Displaying results
    printf("\n\tPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++) {
        printf("\n\tP%d\t\t%d\t\t%d\t\t%d", p[i], bt[i], wt[i], tat[i]);
    }
    // Printing average waiting time and turnaround time
    printf("\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\nAverage Turnaround Time: %.2f\n", tatavg / n);
    return 0;
}

// Output
// Enter the number of processes: 4
// Enter Burst Time for Process 0: 6
// Enter Burst Time for Process 1: 8
// Enter Burst Time for Process 2: 7
// Enter Burst Time for Process 3: 3

// 	PROCESS	BURST TIME	WAITING TIME	TURNAROUND TIME

// 	P3		3		0		3
// 	P0		6		3		9
// 	P2		7		9		16
// 	P1		8		16		24
// Average Waiting Time: 7.00
// Average Turnaround Time: 13.00
