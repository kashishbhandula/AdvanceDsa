// C++ program to demonstrate working of Square Root
// Decomposition.
#include <bits/stdc++.h>
using namespace std;

vector<int> block;
vector<int> arr;
int blk_sz;

void update(int idx, int val)
{
    int blockNumber = idx / blk_sz;
    block[blockNumber] += val - arr[idx];
    arr[idx] = val;
}

int query(int l, int r)
{
    int sum = 0;
    while (l < r and l % blk_sz != 0 and l != 0)
    {

        sum += arr[l];
        l++;
    }
    while (l + blk_sz - 1 <= r)
    {

        sum += block[l / blk_sz];
        l += blk_sz;
    }
    while (l <= r)
    {

        sum += arr[l];
        l++;
    }
    return sum;
}

void preprocess(vector<int> &arr, int n)
{

    int blk_idx = -1;

    blk_sz = sqrt(n);
    block.assign(blk_sz + 1, 0);

    for (int i = 0; i < n; i++)
    {
        if (i % blk_sz == 0)
        {

            blk_idx++;
        }
        block[blk_idx] += arr[i];
    }
}

// Driver code
int main()
{
    int n;
    cin >> n;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    preprocess(arr, n);

    for (auto it : block)
        cout << it << " ";
    cout << endl;
    return 0;
}
