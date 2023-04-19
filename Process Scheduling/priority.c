#include <stdio.h>
#include <stdlib.h>

struct process
{
    int pid;
    int priority;
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
    printf("PID \t AT \t BT \t CT \t TAT \t WT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d \t %d \t %d \t %d \t %d \t %d \t\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
}

void sort_as_priority(struct process p[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].priority < p[j + 1].priority)
            {
                struct process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
            else if (p[j].priority < p[j + 1].priority)
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
    printf("Higher The Priority no. Higher Will Be the priority ");
    int n;
    printf("Enter The Number Of Processes : ");
    scanf("%d", &n);
    struct process p[n];
    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("Enter Priority , Arrival Time and Burst Time Of Process %d : ", i + 1);
        scanf("%d%d%d", &p[i].priority, &p[i].at, &p[i].bt);
        p[i].completed = 0;
        p[i].tb = p[i].bt;
    }

    sort_as_priority(p, n);

    int completed = 0;
    int curr_time = 0;
    while (completed != n)
    {
        int i = 0;
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