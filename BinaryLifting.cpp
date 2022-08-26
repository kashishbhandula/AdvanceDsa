#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
int par[20][300000];
int height[300000];

int findParent(int node, int k)
{
    for (int i = 0; i < 20; i++)
    {
        if (k & (1 << i))
            node = par[i][node];
    }
    if (node == 0)
        return -1;
    return node;
}
int lca(int u, int v)
{
    if (height[v] < height[u])
        swap(u, v);
    int diff = height[v] - height[u];
    v = findParent(v, diff);
    // cout<<u<<" "<<v<<endl;
    if (u == v)
        return v;
    for (int i = 19; i >= 0; i--)
    {

        if (par[i][u] != par[i][v])
        {

            u = par[i][u];
            v = par[i][v];
        }
    }

    return par[0][u];
}
void Dfs(int node, int p = 0)
{
    par[0][node] = p;
    height[node] = height[p] + 1;
    for (int i = 1; i < 20; i++)
    {
        par[i][node] = par[i - 1][par[i - 1][node]];
    }
    for (auto it : graph[node])
    {
        if (it != p)
        {
            Dfs(it, node);
        }
    }
}
int main()
{
    int vertex, q;
    cin >> vertex >> q;

    graph.assign(vertex + 1, vector<int>());
    for (int i = 2; i <= vertex; i++)
    {
        int u;
        cin >> u;

        graph[u].push_back(i);
    }
    Dfs(1);
    // for(auto it:height)cout<<it<<" ";
    // cout<<endl;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        // cout<<findParent(u,1)<<endl;
        cout << lca(u, v) << endl;
    }
    return 0;
}