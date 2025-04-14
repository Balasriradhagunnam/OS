#include <stdio.h>
#define MAX 25

int main() {
    int frag[MAX], blk[MAX], fil[MAX], i, j, nb, nf, temp;
    static int blkFlag[MAX], filBlk[MAX];

    printf("\nMemory Management Scheme - First Fit\n");

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
        for (j = 0; j < nb; j++) {
            if (blkFlag[j] != 1) {
                temp = blk[j] - fil[i];
                if (temp >= 0) {
                    filBlk[i] = j;
                    frag[i] = temp;
                    blkFlag[j] = 1;
                    break;
                }
            }
        }
    }

    printf("\nFile No.\tFile Size\tBlock No.\tBlock Size\tFragment\n");
    for (i = 0; i < nf; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, fil[i], filBlk[i] + 1, blk[filBlk[i]], frag[i]);
    }

    return 0;
}

// Output

// Memory Management Scheme - First Fit
// Enter the number of blocks: 3
// Enter the number of files: 2

// Enter the size of the blocks:
// Block 1: 100
// Block 2: 500
// Block 3: 200

// Enter the size of the files:
// File 1: 120
// File 2: 400

// File No.	File Size	Block No.	Block Size	Fragment
// 1		120		2		500		380
// 2		400		1		100		0
