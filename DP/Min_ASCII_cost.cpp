// Given two strings s1, s2, find the lowest ASCII sum of deleted characters to make two strings equal.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

int minimumDeleteSum(string s1, string s2)
{
    int n1 = s1.length(), n2 = s2.length();
    // dp[i][j] stores the max ASCII sum common in s1[0,i-1] and s2[0,j-1]
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = max({dp[i - 1][j - 1] + s1[i - 1], dp[i - 1][j], dp[i][j - 1]}); 
                //calculate max ASCII cost of LCS 
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int ans = 0;
    for (auto i : s1)
        ans += i;
    for (auto i : s2)
        ans += i;

    return ans - 2 * dp.back().back();
}