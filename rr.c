#include <stdio.h>
struct process
{
    int pid; // process id
    int at;  // arrival time
    int bt;  // burst time
    int rt;  // remaining time
    int ct;  // completion time
    int tat; // turnaround time
    int wt;  // waiting time
};
void main()
{
    int n, tq, time = 0, i, j, total_wt = 0, total_tat = 0;
    float avg_wt, avg_tat;
    // Take input from user
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct process p[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter arrival time and burst time for process %d: ",
               i + 1);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].pid = i + 1;
        p[i].rt = p[i].bt;
    }
    printf("Enter time quantum: ");
    scanf("%d", &tq);
    // Perform round robin scheduling
    int completed = 0;
    printf("\nGantt chart:\n");
    while (completed != n)
    {
        for (i = 0; i < n; i++)
        {
            if (p[i].rt > 0)
            {
                printf(" %d | P%d ", time, p[i].pid);
                if (p[i].rt > tq)
                {
                    time += tq;
                    p[i].rt -= tq;
                }
                else
                {
                    time += p[i].rt;
                    p[i].ct = time;
                    p[i].tat = p[i].ct - p[i].at;
                    p[i].wt = p[i].tat - p[i].bt;
                    total_tat += p[i].tat;
                    total_wt += p[i].wt;
                    p[i].rt = 0;
                    completed++;
                }
            }
        }
    }
    printf("%d\n", time);
    // Output results
    avg_tat = (float)total_tat / n;
    avg_wt = (float)total_wt / n;
    printf("\nAverage waiting time: %.2f\n", avg_wt);
    printf("Average turnaround time: %.2f\n", avg_tat);
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt,
               p[i].ct, p[i].tat, p[i].wt);
    }
}
