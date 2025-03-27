#include <stdio.h>
int main() {
    int i, j, n, bu[10], wa[10], tat[10], t, ct[10], remaining;
    float awt = 0, att = 0, temp = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter Burst Time for process %d: ", i + 1);
        scanf("%d", &bu[i]);
        ct[i] = bu[i]; // Store original burst time
    }
    printf("Enter the time quantum: ");
    scanf("%d", &t);
    remaining = n; // Track remaining processes
    // Round Robin Scheduling
    while (remaining > 0) {
        for (i = 0; i < n; i++) {
            if (bu[i] > 0) {
                if (bu[i] <= t) { // Process completes in this cycle
                    temp += bu[i];
                    tat[i] = temp; // Turnaround time
                    bu[i] = 0;
                    remaining--; // Process finished
                } else { // Process still has remaining burst time
                    bu[i] -= t;
                    temp += t;
                }
            }
        }
    }
    // Calculate waiting times
    for (i = 0; i < n; i++) {
        wa[i] = tat[i] - ct[i]; // Waiting time = Turnaround time - Burst time
        awt += wa[i];
        att += tat[i];
    }
    // Print results
    printf("\nThe Average Turnaround Time is: %.2f", att / n);
    printf("\nThe Average Waiting Time is: %.2f\n", awt / n);
    
    printf("\n\tPROCESS\t BURST TIME\t WAITING TIME\t TURNAROUND TIME\n");
    for (i = 0; i < n; i++) {
        printf("\t%d\t %d\t\t %d\t\t %d\n", i + 1, ct[i], wa[i], tat[i]);
    }
    return 0;
}

// Output
// Enter the number of processes: 3
// Enter Burst Time for process 1: 24
// Enter Burst Time for process 2: 3
// Enter Burst Time for process 3: 3
// Enter the time quantum: 3
// The Average Turnaround Time is: 15.00
// The Average Waiting Time is: 5.00
// 	PROCESS	 BURST TIME	 WAITING TIME	 TURNAROUND TIME
// 	1	 24		 6		 30
// 	2	 3		 3		 6
// 	3	 3		 6		 9
