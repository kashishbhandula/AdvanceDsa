//
#include <stdio.h>
#include <math.h>
#define MAX 1000

int tree[MAX] = {0};
int lazy[MAX] = {0};

void Update(int idx, int low, int high, int left, int right, int diff)
{

    if (lazy[idx] != 0)
    {

        tree[idx] += (high - low + 1) * lazy[idx];

        if (low != high)
        {

            lazy[idx * 2 + 1] += lazy[idx];
            lazy[idx * 2 + 2] += lazy[idx];
        }

        lazy[idx] = 0;
    }

    if (low > high || low > right || high < left)
        return;

    if (low >= left && high <= right)
    {

        tree[idx] += (high - low + 1) * diff;

        if (low != high)
        {

            lazy[idx * 2 + 1] += diff;
            lazy[idx * 2 + 2] += diff;
        }
        return;
    }

    int mid = (low + high) / 2;
    Update(idx * 2 + 1, low, mid, left, right, diff);
    Update(idx * 2 + 2, mid + 1, high, left, right, diff);

    tree[idx] = tree[idx * 2 + 1] + tree[idx * 2 + 2];
}

void updateRange(int n, int left, int right, int diff)
{
    Update(0, 0, n - 1, left, right, diff);
}

int getSumUtil(int low, int high, int qs, int qe, int idx)
{

    if (lazy[idx] != 0)
    {
        tree[idx] += (high - low + 1) * lazy[idx];

        if (low != high)
        {

            lazy[idx * 2 + 1] += lazy[idx];
            lazy[idx * 2 + 2] += lazy[idx];
        }

        lazy[idx] = 0;
    }

    if (low > high || low > qe || high < qs)
        return 0;

    if (low >= qs && high <= qe)
        return tree[idx];

    int mid = (low + high) / 2;
    return getSumUtil(low, mid, qs, qe, 2 * idx + 1) +
           getSumUtil(mid + 1, high, qs, qe, 2 * idx + 2);
}

int getSum(int n, int qs, int qe)
{

    if (qs < 0 || qe > n - 1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }

    return getSumUtil(0, n - 1, qs, qe, 0);
}

void Build(int arr[], int low, int high, int idx)
{

    if (low > high)
        return;

    if (low == high)
    {
        tree[idx] = arr[low];
        return;
    }

    int mid = (low + high) / 2;
    Build(arr, low, mid, idx * 2 + 1);
    Build(arr, mid + 1, high, idx * 2 + 2);

    tree[idx] = tree[idx * 2 + 1] + tree[idx * 2 + 2];
}

int main()
{

    return 0;
}
