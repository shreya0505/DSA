#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define N 2000
const int MAXLOG = log2(N) + 1;

std::vector<int> adj[N];
int timer;
int up[N][N];
int t_in[N], t_out[N];

void dfs(int node, int parent)
{
    up[node][0] = parent;
    t_in[node] = ++timer;

    for (int i = 1; i < MAXLOG; i++)
    {
        up[node][i] = up[up[node][i - i]][i - 1];
    }

    for (int x : adj[node])
    {
        if (x != parent)
        {
            dfs(x, node);
        }
    }

    t_out[node] = ++timer;
}

bool isancestor(int u, int v)
{
    return (t_in[u] <= t_in[v] && t_out[u] >= t_out[v]);
}

int lca(int u, int v)
{
    if (isancestor(u, v))
        return u;

    if (isancestor(v, u))
        return v;

    for (int i = MAXLOG; i >= 0; i--)
    {
        if (!isancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        adj[i].clear();

    timer = 0;

    memset(up, -1, sizeof(up));
    memset(t_in, 0, sizeof(t_in));
    memset(t_out, 0, sizeof(t_out));

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        while (m--)
        {
            int x;
            cin >> x;
            x--;
            adj[x].push_back(i);
            adj[i].push_back(x);
        }
    }

    dfs(0, 0);

    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        cout << lca(u, v) + 1 << '\n';
    }
}

int main()
{
    return 0;
}