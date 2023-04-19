#include <stdio.h>

int absi(int a, int b)
{
    if (a - b < 0)
        return b - a;
    else
        return a - b;
}

int fcfs(int req[], int n, int head)
{
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ans = ans + absi(req[i + 1], req[i]);
    }
    return ans + absi(req[0], head);
}

int scan(int req[], int n, int k, int head)
{
    int mini = 999;
    for (int i = 0; i < n; i++)
    {
        if (mini > req[i])
            mini = req[i];
    }

    return absi(k - 1, mini) + absi(head, k - 1);
}

int cscan(int req[], int n, int k, int head)
{
    int mini = 9999;
    int min_index = -1;
    for (int i = 0; i < n; i++)
    {
        if (req[i] < head)
        {
            if (mini > head - req[i])
            {
                mini = head - req[i];
                min_index = i;
            }
        }
    }
    return absi(head, k - 1) + k - 1 + req[min_index];
}

int sstf(int req[], int n, int head)
{
    int mini = 9999;
    int maxi = -9999;
    for (int i = 0; i < n; i++)
    {
        if (mini > req[i])
            mini = req[i];
        if (maxi < req[i])
            maxi = req[i];
    }

    return absi(head, mini) + absi(mini, maxi);
}

int main()
{
    int n;
    int k = 200;
    printf("Enter Number Of Requests : ");
    scanf("%d", &n);
    int request[n];
    printf("Enter Each Process Requirement : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &request[i]);
    }
    int head;
    printf("Enter Position Of Header : ");
    scanf("%d", &head);

    printf("FCFS SEEK TIME : %d\n", fcfs(request, n, head));

    printf("SSTF SEEK TIME : %d\n", sstf(request, n, head));

    printf("SCAN SEEK TIME : %d\n", scan(request, n, k, head));

    printf("CSCAN SEEK TIME : %d\n", cscan(request, n, k, head));
}