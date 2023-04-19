#include <stdio.h>

void display(int b[], int allocation[], int p[], int n, int np)
{
    printf("BNO \t PNO \t Bsize \t Psize \t Hole\t\n");
    for (int i = 0; i < n; i++)
    {
        if (allocation[i] == -1)
            printf("%d \t NA\t\n", i + 1);
        else
        {
            printf("%d \t %d \t %d \t %d \t %d\t\n", i + 1, allocation[i] + 1, b[i], p[allocation[i]], b[i] - p[allocation[i]]);
        }
    }
}

void first_fit(int b[], int n, int p[], int np)
{
    int allocation[n];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < np; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (p[i] <= b[j] && allocation[j] == -1)
            {
                allocation[j] = i;
                break;
            }
        }
    }
    display(b, allocation, p, n, np);
}

void best_fit(int b[], int n, int p[], int np)
{
    int allocation[n];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < np; i++)
    {
        int mini = 999;
        int index = -1;
        for (int j = 0; j < n; j++)
        {
            if (allocation[j] == -1 && p[i] <= b[j])
            {
                if (mini > b[j] - p[i])
                {
                    index = j;
                    mini = b[j] - p[i];
                }
            }
        }
        if (index != -1)
        {
            allocation[index] = i;
        }
    }

    display(b, allocation, p, n, np);
}

void worst_fit(int b[], int n, int p[], int np)
{
    int allocation[n];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < np; i++)
    {
        int maxi = -999;
        int index = -1;
        for (int j = 0; j < n; j++)
        {
            if (allocation[j] == -1 && p[i] <= b[j])
            {
                if (maxi < b[j] - p[i])
                {
                    index = j;
                }
            }
        }
        if (index != -1)
        {
            allocation[index] = i;
        }
    }

    display(b, allocation, p, n, np);
}

void next_fit(int b[], int n, int p[], int np)
{
    int allocation[n];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    int k = -1;
    int j = 0;
    for (int i = 0; i < n; i++)
    {

        for (j = k + 1;; j++)
        {
            if (j >= n)
                j = j % n;
            if (b[j] >= p[i] && allocation[j] == -1)
            {
                allocation[j] = i;
                break;
            }
            if (j == k)
            {
                break;
            }
        }
        k = j % n;
    }

    display(b, allocation, p, n, np);
}

int main()
{
    int n, np;
    printf("Enter Number Of blocks : ");
    scanf("%d", &n);
    printf("Enter Number Of Processes : ");
    scanf("%d", &np);
    int p[np];
    int b[n];

    printf("\nEnter Size of Each Block : \n");
    for (int i = 0; i < n; i++)
    {
        printf("Block %d : ", i + 1);
        scanf("%d", &b[i]);
    }

    printf("Enter Size of Each process : \n");
    for (int i = 0; i < np; i++)
    {
        printf("process %d : ", i + 1);
        scanf("%d", &p[i]);
    }

    next_fit(b, n, p, np);
}