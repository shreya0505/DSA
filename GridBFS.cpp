#include <bits/stdc++.h>
using namespace std;

bool isvalid(int x, int y, int n, int m)
{
    if (x >= 0 && y >= 0 && x < n && y < n)
        return 1;
    return 0;
}

int orangesRotting(vector<vector<int>> &a)
{
    int n = a.size();
    int m = a[0].size();
    int time[n][m], vis[n][m];
    memset(time, -1, sizeof(time));
    memset(vis, -1, sizeof(vis));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 2)
            {
                int v[n][m];
                memset(v, 0, sizeof(v));
                queue<tuple<int, int, int>> q;
                q.push({0, i, j});
                while (!q.empty())
                {
                    cout << "HERE";
                    tuple<int, int, int> curr;
                    curr = q.front();
                    q.pop();
                    int dx[4] = {0, 0, 1, -1};
                    int dy[4] = {-1, 1, 0, 0};
                    for (int k = 0; k < 4; k++)
                    {
                        int x = get<1>(curr) + dx[k];
                        int y = get<2>(curr) + dy[k];
                        int l = get<0>(curr) + 1;
                        cout << x << ' ' << y << '\n';
                        if (isvalid(x, y, n, m) && a[x][y] == 1 && !v[x][y])
                        {

                            cout << x << ' ' << y << '\n';
                            vis[x][y] = 1;
                            v[x][y] = 1;
                            if (time[x][y] == -1)
                                time[x][y] = l;
                            else
                                time[x][y] = min(time[x][y], l);
                            q.push({l, x, y});
                        }
                    }
                }
            }

            // for(int i=0;i<n;i++){
            //     for(int j=0;j<m;j++){
            //         cout<<time[i][j]<<' ';
            //     }
            //     cout<<'\n';
            // }
            // cout<<'\n';
        }
        // cout<< i<<'\n';
    }

    int flag = 1, mn = INT_MIN;

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<time[i][j]<<' ';
    //         if(a[i][j]==1 && vis[i][j]==-1){
    //             flag=0;
    //             break;
    //         }
    //         if(a[i][j]==1)
    //             mn =  max(time[i][j], mn);
    //     }
    //     cout<<'\n';
    // }

    if (flag)
    {
        if (mn == INT_MIN)
            return 0;
        return mn;
    }

    return -1;
}

int main()
{
    return 0;
}