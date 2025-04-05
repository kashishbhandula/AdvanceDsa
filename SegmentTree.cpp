#include <bits/stdc++.h>
using namespace std;
vector<int> Tree, arr;

void Build(int low, int high, int idx)
{
    if (low == high)
    {
        // cout << idx << " " << low << endl;
        Tree[idx] = arr[low];
        return;
    }
    int mid = (low + high) >> 1;
    Build(low, mid, 2 * idx + 1);
    Build(mid + 1, high, 2 * idx + 2);
    Tree[idx] = Tree[2 * idx + 2] + Tree[2 * idx + 1];
}

void Update(int low, int high, int idx, int pos, int val)
{
    if (low == high)
    {
        Tree[idx] = val;
        return;
    }
    int mid = (low + high) >> 1;
    if (mid < pos)
        Update(mid + 1, high, 2 * idx + 2, pos, val);
    else
        Update(low, mid, 2 * idx + 1, pos, val);
    Tree[idx] = Tree[2 * idx + 2] + Tree[2 * idx + 1];
}

int RangeSum(int low, int high, int idx, int left, int right)
{
    if (left <= low && high <= right)
        return Tree[idx];

    if (right < low || left > high)
        return 0;
    int mid = (low + high) >> 1;
    return RangeSum(mid + 1, high, 2 * idx + 2, left, right) +
           RangeSum(low, mid, 2 * idx + 1, left, right);
}
int main()
{
    int n;
    cin >> n;

    Tree.assign(4 * n, 0);
    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Build(0, n - 1, 0);
    Update(0,n-1,0,2,0);
    cout << RangeSum(0, n - 1, 0, 0, 4) << endl;

    return 0;
}
