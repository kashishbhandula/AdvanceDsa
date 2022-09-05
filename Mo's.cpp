
#include <bits/stdc++.h>
using namespace std;

int block;

struct Query
{
    int L, R, pos;
};

bool compare(Query x, Query y)
{

    if (x.L / block != y.L / block)
        return x.L / block < y.L / block;

    return x.R < y.R;
}

void queryResults(vector<int> &arr, int n, vector<Query> &q, int m)
{

    block = (int)sqrt(n);

    sort(q.begin(), q.end(), compare);

    int currL = 0, currR = 0;
    int currSum = 0;

    for (int i = 0; i < m; i++)
    {
        int L = q[i].L, R = q[i].R;

        while (currL < L)
        {
            currSum -= arr[currL];
            currL++;
        }

        while (currL > L)
        {
            currSum += arr[currL - 1];
            currL--;
        }
        while (currR <= R)
        {
            currSum += arr[currR];
            currR++;
        }

        while (currR > R + 1)
        {
            currSum -= arr[currR - 1];
            currR--;
        }

        cout << "Sum of [" << L << ", " << R
             << "] is " << currSum << endl;
    }
}

// Driver program
int main()
{

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    vector<Query> q;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        q.push_back({u, v, i});
    }
    queryResults(arr, n, q, m);
    return 0;
}
