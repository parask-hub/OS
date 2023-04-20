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

void LRU(int frames[], int f, int request[], int n)
{
    int i = 0;
    int hit = 0;
    int curr_s = 0;
    int page_fault = 0;
    int timespace[f] = {-1};

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

int kiskokaru(int frames[], int request[], int f, int t, int n)
{
    int maxi = -9999;
    int ans = -1;
    for (int i = 0; i < f; i++)
    {
        int j;
        for (j = t + 1; j < n; j++)
        {
            if (frames[i] == request[j])
                break;
        }
        if (j > maxi)
        {
            maxi = j;
            ans = i;
        }
    }
    return ans;
}

void Optimal(int frames[], int f, int request[], int n)
{
    int i = 0;
    int curr_s = 0;
    int hit = 0;
    while (curr_s < f)
    {
        if (find(frames, f, request[i]) > 0)
            hit++;
        else
        {
            frames[curr_s] = request[i];
            curr_s++;
        }
        display(frames, f);
        cout << endl;
        i++;
    }

    while (i < n)
    {
        if (find(frames, f, request[i]) >= 0)
            hit++;
        else
        {
            int dis = kiskokaru(frames, request, f, i, n);
            frames[dis] = request[i];
        }
        display(frames, f);
        cout << endl;
        i++;
    }
    cout << "Hits = " << hit << endl
         << "Miss = " << n - hit;
}

int main()
{
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
    // LRU(frames, f, request, n);
    Optimal(frames, f, request, n);
}