#include <stdio.h>
#include <string.h>

struct fileTable {
    char name[20];
    int sb, nob;
} ft[30];

int main() {
    int i, j, n;
    char s[20];

    printf("Enter number of files: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter file name %d: ", i + 1);
        scanf("%s", ft[i].name);
        printf("Enter starting block of file %d: ", i + 1);
        scanf("%d", &ft[i].sb);
        printf("Enter number of blocks in file %d: ", i + 1);
        scanf("%d", &ft[i].nob);
    }

    printf("\nEnter the file name to be searched: ");
    scanf("%s", s);

    for (i = 0; i < n; i++) {
        if (strcmp(s, ft[i].name) == 0)
            break;
    }

    if (i == n) {
        printf("\nFile Not Found\n");
    } else {
        printf("\nFILE NAME\tSTART BLOCK\tNO OF BLOCKS\tBLOCKS OCCUPIED\n");
        printf("%s\t\t%d\t\t%d\t\t", ft[i].name, ft[i].sb, ft[i].nob);
        for (j = 0; j < ft[i].nob; j++) {
            printf("%d ", ft[i].sb + j);
        }
        printf("\n");
    }

    return 0;
}

// Output
// Enter number of files: 2

// Enter file name 1: file1
// Enter starting block of file 1: 5
// Enter number of blocks in file 1: 3

// Enter file name 2: file2
// Enter starting block of file 2: 10
// Enter number of blocks in file 2: 2

// Enter the file name to be searched: file1

// FILE NAME      START BLOCK    NO OF BLOCKS   BLOCKS OCCUPIED
// file1          5              3              5 6 7
