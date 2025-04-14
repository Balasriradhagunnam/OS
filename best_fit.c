#include <stdio.h>
#define MAX 25

int main() {
    int frag[MAX], blk[MAX], fil[MAX], i, j, nb, nf, temp, best;
    static int blkFlag[MAX], filBlk[MAX];

    printf("\nMemory Management Scheme - Best Fit\n");

    printf("Enter the number of blocks: ");
    scanf("%d", &nb);

    printf("Enter the number of files: ");
    scanf("%d", &nf);

    printf("\nEnter the size of the blocks:\n");
    for (i = 0; i < nb; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blk[i]);
    }

    printf("\nEnter the size of the files:\n");
    for (i = 0; i < nf; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &fil[i]);
    }

    for (i = 0; i < nf; i++) {
        best = 10000;  // reset best fit value for each file
        for (j = 0; j < nb; j++) {
            if (blkFlag[j] != 1) {
                temp = blk[j] - fil[i];
                if (temp >= 0 && temp < best) {
                    filBlk[i] = j;
                    frag[i] = temp;
                    best = temp;
                }
            }
        }
        blkFlag[filBlk[i]] = 1;
    }

    printf("\nFile No.\tFile Size\tBlock No.\tBlock Size\tFragment\n");
    for (i = 0; i < nf; i++) {
        int bi = filBlk[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, fil[i], bi + 1, blk[bi], frag[i]);
    }

    return 0;
}

// Output
// Memory Management Scheme - Best Fit
// Enter the number of blocks: 3
// Enter the number of files: 2

// Enter the size of the blocks:
// Block 1: 5
// Block 2: 2
// Block 3: 
// 7

// Enter the size of the files:
// File 1: 1
// File 2: 4

// File No.	File Size	Block No.	Block Size	Fragment
// 1		1		2		2		1
// 2		4		1		5		1
