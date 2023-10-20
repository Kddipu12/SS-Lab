#include <stdio.h>

struct st {
    char dname[10];
    char sdname[10][10];
    char fname[10][10][10];
    int ds, sds[10];
} dir[10];

int main() {
    int i, j, k, n;
    printf("Enter the number of directories: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter directory %d name: ", i + 1);
        scanf("%s", dir[i].dname);
        printf("Enter the size of directory %s: ", dir[i].dname);
        scanf("%d", &dir[i].ds);
        for (j = 0; j < dir[i].ds; j++) {
            printf("Enter subdirectory name and size for directory %s: ", dir[i].dname);
            scanf("%s", dir[i].sdname[j]);
            printf("Enter the size of subdirectory %s: ", dir[i].sdname[j]);
            scanf("%d", &dir[i].sds[j]);
            for (k = 0; k < dir[i].sds[j]; k++) {
                printf("Enter file name for subdirectory %s: ", dir[i].sdname[j]);
                scanf("%s", dir[i].fname[j][k]);
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf("\n*******************\n");
        printf("Directory Name: %s\n", dir[i].dname);
        for (j = 0; j < dir[i].ds; j++) {
            printf("\tSubdirectory Name: %s (Size: %d)\n", dir[i].sdname[j], dir[i].sds[j]);
            for (k = 0; k < dir[i].sds[j]; k++) {
                printf("\t\tFile Name: %s\n", dir[i].fname[j][k]);
            }
        }
    }

    return 0;
}
