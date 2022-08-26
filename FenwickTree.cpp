#include <bits/stdc++.h>
using namespace std;
// update--- 2's cpmpliment & with original number +with original number
// sum-- 2's cpmpliment & with original number -with original number
vector<int> Tree;
int getSum(int idx)
{
    int sum = 0;

    idx = idx + 1;

    while (idx > 0)
    {
        sum += Tree[idx];

        idx -= idx & (-idx);
    }
    return sum;
}

void Update(int n, int idx, int val)
{

    idx = idx + 1;

    while (idx <= n)
    {

        Tree[idx] += val;

        idx += idx & (-idx);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    Tree.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        Update(n, 0, arr[i]);
    }
}