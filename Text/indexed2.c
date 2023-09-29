#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 50

int main() {
    int f[MAX_BLOCKS], index[MAX_BLOCKS];
    int i, n, ind, j, count, k, c;

    // Initialize the file allocation table (FAT)
    for (i = 0; i < MAX_BLOCKS; i++) {
        f[i] = 0; // 0 represents unallocated, 1 represents allocated
    }

    do {
        printf("Enter the index block: ");
        scanf("%d", &ind);

        if (f[ind] != 1) {
            printf("Enter the number of blocks needed and the block numbers for index %d: \n", ind);
            scanf("%d", &n);
        } else {
            printf("%d index is already allocated.\n", ind);
            continue;
        }

        count = 0;

        printf("Enter block numbers for the file in index %d:\n", ind);
        for (i = 0; i < n; i++) {
            scanf("%d", &index[i]);
            if (f[index[i]] == 0) {
                count++;
            }
        }

        if (count == n) {
            for (j = 0; j < n; j++) {
                f[index[j]] = 1; // Mark blocks as allocated
            }
            printf("Allocated\n");
            printf("File Indexed\n");
            for (k = 0; k < n; k++) {
                printf("%d-------->%d : %d\n", ind, index[k], f[index[k]]);
            }
        } else {
            printf("File in the index is already allocated.\n");
            printf("Enter another file index.\n");
            continue;
        }

        printf("Do you want to enter more files (1 for Yes, 0 for No)? ");
        scanf("%d", &c);
    } while (c != 0);

    return 0;
}
