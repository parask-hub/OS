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
    int completed;
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
        p[i].completed = 0;
        printf("Enter Arrival Time and Burst Time Of Process %d : ", i + 1);
        scanf("%d%d", &p[i].at, &p[i].bt);
    }

    // Sort The array in ascending order As per the burst time
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].bt > p[j + 1].bt)
            {
                struct process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    int completed = 0;
    int curr_time = 0;
    while (completed != n)
    {
        int i = 0;
        while (i < n)
        {
            if ((p[i].at <= curr_time) && (p[i].completed == 0))
            {
                p[i].ct = curr_time + p[i].bt;
                p[i].tat = p[i].ct - p[i].at;
                p[i].wt = p[i].tat - p[i].bt;
                p[i].completed = 1;
                completed++;
                break;
            }
            i++;
        }
        if (p[i].completed == 1)
            curr_time += p[i].bt;
        else
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