#include <stdio.h>
#include <stdlib.h>

struct process
{
    int pid;
    int at;
    int bt;
    int tat;
    int ct;
    int wt;
};

void display(struct process p[], int n)
{
    printf("PID \t AT \t BT \t CT \t TAT \t WT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d \t %d \t %d \t %d \t %d \t %d \t\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
}

int main()
{
    int n;
    printf("Enter The Number Of Processes : ");
    scanf("%d", &n);
    struct process p[n];
    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("Enter Arrival Time and Burst Time Of Process %d : ", i + 1);
        scanf("%d%d", &p[i].at, &p[i].bt);
    }

    // sort process as per the arrival time
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                struct process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Calculating Completion time
    int sum = p[0].at;
    printf("Gannt Chart:\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d[", sum);
        if (sum < p[i].at)
            sum = p[i].at;

        p[i].ct = sum + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        sum = p[i].ct;
        printf("P%d]%d", p[i].pid, sum);
    }
    printf("\n");

    display(p, n);
}