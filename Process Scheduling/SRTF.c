#include <stdio.h>
#include <stdlib.h>

struct process
{
    int pid;
    int at;
    int bt;
    int tb;
    int tat;
    int ct;
    int wt;
    int completed;
};

void display(struct process p[], int n)
{
    printf("PID \t AT \t BT \tTB \t CT \t TAT \t WT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d \t %d \t %d \t %d \t %d \t %d \t %d \t\n", p[i].pid, p[i].at, p[i].bt, p[i].tb, p[i].ct, p[i].tat, p[i].wt);
    }
}

void sort_as_burst_time(struct process p[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].tb > p[j + 1].tb)
            {
                struct process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
            else if (p[j].tb == p[j + 1].tb)
            {
                if (p[j].at > p[j + 1].at)
                {
                    struct process temp = p[j];
                    p[j] = p[j + 1];
                    p[j + 1] = temp;
                }
            }
        }
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
        p[i].completed = 0;
        printf("Enter Arrival Time and Burst Time Of Process %d : ", i + 1);
        scanf("%d%d", &p[i].at, &p[i].bt);
        p[i].tb = p[i].bt;
        p[i].tat = -999;
        p[i].ct = -999;
        p[i].wt = -999;
    }

    sort_as_burst_time(p, n);

    int completed = 0;
    int curr_time = 0;
    while (completed != n)
    {
        int i = 0;
        display(p, n);
        while (i < n)
        {
            if (p[i].at <= curr_time && p[i].completed == 0)
            {
                p[i].tb--;
                if (p[i].tb == 0)
                {
                    p[i].completed = 1;
                    completed++;
                    p[i].ct = curr_time + 1;
                    p[i].tat = p[i].ct - p[i].at;
                    p[i].wt = p[i].tat - p[i].bt;
                }
                sort_as_burst_time(p, n);
                printf("\n\n");
                break;
            }
            i++;
        }
        curr_time++;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].pid > p[j + 1].pid)
            {
                struct process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    display(p, n);
}