#include <stdio.h>

void main()
{
    int n, m;
    printf("Number of process: ");
    scanf("%d", &n);
    printf("Number of resources: ");
    scanf("%d", &m);
    printf("\n");

    int max[n][m], alloc[n][m], need[n][m], ava[m], complete[n];
    int i, j, flag, valid;

    // input
    for (i = 0; i < n; i++)
    {
        printf("\nPID = %d", i);
        complete[i] = 0;
        printf("\n   Allocation: ");
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);
        printf("   Maximum Re: ");
        for (j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    printf("\nAvailable: ");
    for (j = 0; j < m; j++)
        scanf("%d", &ava[j]);

    // special input
    printf("\nSpecial Request (1/0): ");
    scanf("%d", &flag);
    if (flag)
    {
        int req[m];
        printf("PID: ");
        scanf("%d", &i);
        printf("Allocation: ");
        for (j = 0; j < m; j++)
        {
            scanf("%d", &req[j]);
            if (req[j] > need[i][j] || req[j] > ava[j])
            {
                printf("\nInconsistent Request Input\n");
                return;
            }
        }
        for (j = 0; j < m; j++)
        {
            alloc[i][j] += req[j];
            need[i][j] -= req[j];
            ava[j] -= req[j];
        }
    }

    //output
    printf("\n--- Input Values ---");
    printf("\nInitial Available: ");
    for (j = 0; j < m; j++)
        printf("%d ", ava[j]);
    printf("\n\nPID\tALLOC\tMAX\tNEED\t\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t", i);
        for (j = 0; j < m; j++)
            printf("%d ", alloc[i][j]);
        printf("\t");
        for (j = 0; j < m; j++)
            printf("%d ", max[i][j]);
        printf("\t");
        for (j = 0; j < m; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }

    // Generating sequence
    printf("\nSafe Sequence: ");
    flag = 1;
    while (flag)
    {
        flag = 0;
        for (i = 0; i < n; i++)
        {
            valid = 1;
            if (complete[i] == 1)
                continue;
            for (j = 0; j < m; j++)
                if (need[i][j] > ava[j])
                    valid = 0;
            if (valid)
            {
                flag = 1;
                for (j = 0; j < m; j++)
                    ava[j] += alloc[i][j];
                printf("P%d  ", i);
                complete[i] = 1;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        if (complete[i] == 0)
        {
            printf("\nComplete safe sequence could not be found.");
            printf("\nSystem in Unsafe State.");
            break;
        }
    }

    printf("\n\n");
}