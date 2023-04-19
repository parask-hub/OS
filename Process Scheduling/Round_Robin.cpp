#include <iostream>
#include <queue>

using namespace std;

struct process
{
    int pid;
    int at;
    int bt;
    int tb;
    int tat;
    int wt;
    int ct;
    int completed;
};

void sort_as_arrival_time(process p[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                swap(p[j], p[j + 1]);
            }
        }
    }
}

void display(struct process p[], int n)
{
    printf("PID \t AT \t BT \t CT \t TAT \t WT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d \t %d \t %d \t %d \t %d \t %d \t\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
}

void Round_Robin(process p[], int n, int tq)
{
    sort_as_arrival_time(p, n);
    queue<process> ready;
    queue<process> temp;
    int completed = 0;
    int k = 0;
    int curr_time = 0;
    while (completed != n)
    {
        cout << " " << curr_time << "[";
        while (k < n)
        {
            if (p[k].at <= curr_time && p[k].completed == 0)
                ready.push(p[k]);
            else
                break;
            k++;
        }
        if (!temp.empty())
        {
            ready.push(temp.front());
            temp.pop();
        }

        int i = ready.front().pid - 1;
        if (p[i].tb <= tq)
        {
            curr_time += p[i].tb;
            p[i].tb = 0;
            completed++;
            p[i].completed = 1;
            p[i].ct = curr_time;
            p[i].tat = p[i].ct - p[i].at;
            p[i].wt = p[i].tat - p[i].bt;
        }
        else
        {
            p[i].tb -= tq;
            curr_time += tq;
            temp.push(p[i]);
        }
        cout << "P" << i + 1 << "]" << curr_time;
        ready.pop();
    }
    cout << endl;
    display(p, n);
}

int main()
{
    int n;
    cout << "Enter Number Of Processes : ";
    cin >> n;
    process p[n];
    cout << "Enter Arrival Time and Burst Time For Each Process :\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Process " << i + 1 << " : ";
        cin >> p[i].at >> p[i].bt;
        p[i].tb = p[i].bt;
        p[i].tat = 0;
        p[i].wt = 0;
        p[i].ct = 0;
        p[i].pid = i + 1;
        p[i].completed = 0;
    }
    int tq;
    cout << "Enter Time Quantum : ";
    cin >> tq;
    Round_Robin(p, n, tq);
}