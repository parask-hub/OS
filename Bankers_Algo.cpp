#include <iostream>
using namespace std;

int allocated[10][10];
int maxneed[10][10];
int need[10][10];

bool safe_sequence(int n, int m, int availble[])
{
    int finish[m];
    int work[m];
    int i, j, k;
    int ans[10];
    for (i = 0; i < n; i++)
        finish[i] = 0;
    for (i = 0; i < m; i++)
        work[i] = availble[i];
    int flag = 1;
    int count = 0;
    while (flag)
    {
        flag = 0;
        for (i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                for (j = 0; j < m; j++)
                    if (need[i][j] > work[j])
                        break;
                if (j == m)
                {
                    ans[count] = i;
                    finish[i] = 1;
                    flag = 1;
                    for (k = 0; k < m; k++)
                        work[k] += allocated[i][k];
                }
                if (finish[i] == 1)
                    count++;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (finish[i] == 0)
        {
            printf("No Safe Sequence");
            return 0;
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("P%d ", ans[i]);
    }
    return 1;
}

int main()
{
    int n;
    cout << "Enter Number Of Processes : ";
    cin >> n;
    int m;
    cout << "Enter Number Of Memory Types : ";
    cin >> m;

    cout << "Enter Allocated Resources for processes : \n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> allocated[i][j];

    cout << "Enter Maximum Need for processes : \n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> maxneed[i][j];
            need[i][j] = maxneed[i][j] - allocated[i][j];
        }

    int available[m];
    cout << "Enter Availble Resources : \n";
    for (int i = 0; i < m; i++)
        cin >> available[i];

    bool ans = safe_sequence(n, m, available);
    cout << ans << endl;
}