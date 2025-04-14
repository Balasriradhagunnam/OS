#include <stdio.h>
#define MAX 25
int main() {
    int frag[MAX], b[MAX], f[MAX], i, j, nb, nf, temp;
    int bf[MAX] = {0}, ff[MAX];
    printf("\n\tMemory Management Scheme - First Fit\n");
    printf("Enter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of files: ");
    scanf("%d", &nf);
    printf("\nEnter the size of the blocks:\n");
    for (i = 0; i < nb; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &b[i]);
    }
    printf("\nEnter the size of the files:\n");
    for (i = 0; i < nf; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &f[i]);
    }
    for (i = 0; i < nf; i++) {
        ff[i] = -1;
        for (j = 0; j < nb; j++) {
            if (bf[j] == 0 && b[j] >= f[i]) {
                ff[i] = j;               
                frag[i] = b[j] - f[i];  
                bf[j] = 1;                
                break;
            }
        }
    }
    printf("\nFile_No\tFile_Size\tBlock_No\tBlock_Size\tFragment\n");
    for (i = 0; i < nf; i++) {
        if (ff[i] != -1) {
            printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", 
                   i + 1, f[i], ff[i] + 1, b[ff[i]], frag[i]);
        } else {
            printf("%d\t%d\t\tNot Allocated\n", i + 1, f[i]);
        }
    }
    return 0;
}

// Output

// 	Memory Management Scheme - First Fit
// Enter the number of blocks: 3
// Enter the number of files: 2

// Enter the size of the blocks:
// Block 1: 100
// Block 2: 200
// Block 3: 300

// Enter the size of the files:
// File 1: 120
// File 2: 80

// File_No	File_Size	Block_No	Block_Size	Fragment
// 1	120		2		200		80
// 2	80		1		100		20
