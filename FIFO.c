#include <stdio.h>
int main() {
    int i, j, k, f, pf = 0, count = 0, rs[25], m[10], n;
    // Get reference string length
    printf("Enter the length of reference string: ");
    scanf("%d", &n);
    // Get reference string values
    printf("Enter the reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &rs[i]);
    // Get number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &f);
    // Initialize frames with -1 (indicating empty)
    for (i = 0; i < f; i++)
        m[i] = -1;
    printf("\nThe Page Replacement Process is:\n");
    // FIFO Page Replacement Logic
    for (i = 0; i < n; i++) {
        // Check if the page is already in a frame
        for (k = 0; k < f; k++) {
            if (m[k] == rs[i])
                break;
        }
        // If page is not found in frames (page fault occurs)
        if (k == f) {
            m[count] = rs[i]; // Replace the oldest page
            count = (count + 1) % f; // FIFO replacement logic
            pf++; // Increment page fault count
        }
        // Print current frames
        for (j = 0; j < f; j++) {
            if (m[j] != -1)
                printf("\t%d", m[j]);
            else
                printf("\t-");
        }
        // Indicate a page fault if it happened
        if (k == f)
            printf("\tPF No. %d", pf);
        printf("\n");
    }
    // Print total number of page faults
    printf("\nTotal Page Faults using FIFO: %d\n", pf);
    return 0;
}
// Output
// Enter the length of reference string: 7
// Enter the reference string: 1 3 0 3 5 6 3 
// Enter the number of frames: 3
// The Page Replacement Process is:
// 	1	-	-	PF No. 1
// 	1	3	-	PF No. 2
// 	1	3	0	PF No. 3
// 	1	3	0
// 	5	3	0	PF No. 4
// 	5	6	0	PF No. 5
// 	5	6	3	PF No. 6

// Total Page Faults using FIFO: 6
