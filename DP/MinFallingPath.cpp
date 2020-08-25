//Easier Non recursive DP approach
//Take min of the three elements on the row above
// Construct the table row by row by adding min from above row to corress element

// https://leetcode.com/problems/minimum-falling-path-sum/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

int minFallingPathSum(vector<vector<int>> &A)
{
    int n = A.size();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++)
    {
        dp[0][i] = A[0][i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int mn = INT_MAX;
            for (int k = -1; k <= 1; k++)
            {
                if (j + k >= 0 && j + k < n)
                    mn = min(mn, dp[i - 1][j + k]);
            }
            dp[i][j] = mn + A[i][j];
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        ans = min(dp[n - 1][i], ans);
    }

    return ans;
}
