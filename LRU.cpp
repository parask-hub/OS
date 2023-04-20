#include <iostream>
using namespace std;

struct pagetable
{
    int fno;
    int valid;
    int time;
};

int find(int frames[], int f, int x)
{
    for (int i = 0; i < f; i++)
    {
        if (frames[i] == x)
            return i;
    }
    return -1;
}

void display(int frames[], int f)
{
    for (int i = 0; i < f; i++)
    {
        cout << frames[i] << " ";
    }
}

int find_maxitime(int timespace[], int f)
{
    int maxi = -9999;
    int ans = -1;
    for (int i = 0; i < f; i++)
    {
        if (timespace[i] > maxi)
        {
            maxi = timespace[i];
            ans = i;
        }
    }
    return ans;
}
int main()
{
    int fault = 0;
    int n;
    cout << "Enter Number Of Input Process : ";
    cin >> n;
    int request[n];
    for (int i = 0; i < n; i++)
        cin >> request[i];
    int f;
    cout << "Enter Number Of Frames : ";
    cin >> f;
    int frames[f] = {-1};
    int timespace[f] = {-1};

    int i = 0;
    int hit = 0;
    int curr_s = 0;
    int page_fault = 0;

    while (curr_s < f)
    {
        if (find(frames, f, request[i]) > 0)
        {
            timespace[find(frames, f, request[i])] = 0;
            hit++;
        }
        else
        {
            frames[curr_s] = request[i];
            timespace[curr_s] = 0;
            curr_s++;
            fault++;
        }

        for (int i = 0; i < f; i++)
        {
            timespace[i]++;
        }

        display(frames, f);
        cout << endl;
        // display(timespace, f);
        // cout << endl
        //      << endl;

        i++;
    }
    i--;

    while (i < n)
    {
        if (find(frames, f, request[i]) > 0)
        {
            timespace[find(frames, f, request[i])] = 0;
            hit++;
        }
        else
        {
            int maxi = find_maxitime(timespace, f);
            frames[maxi] = request[i];
            timespace[maxi] = 0;
            fault++;
        }

        for (int i = 0; i < f; i++)
        {
            timespace[i]++;
        }

        display(frames, f);
        cout << endl;
        // display(timespace, f);
        // cout << endl
        //      << endl;

        i++;
    }

    cout << "Hits = " << hit << endl
         << "Miss = " << n - hit;
}