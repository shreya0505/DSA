#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

// Print Max Subarray Sum
// S[n] is prefix sum
// We need to find max S[i]-S[j], j<i
// Hence keep track of min of S[] upto any i.
// Max(S[i] - min_of_S_upto_i is ans

int printMAX()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = a[0], sum = 0, min_sum = 0;

    for (int r = 0; r < n; ++r)
    {
        sum += a[r];
        ans = max(ans, sum - min_sum);
        min_sum = min(min_sum, sum);
    }
}

int printMaxSubarray()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = a[0], ans_l = 0, ans_r = 0;
    int sum = 0, min_sum = 0, min_pos = -1;

    for (int r = 0; r < n; ++r)
    {
        sum += a[r];
        int cur = sum - min_sum;
        if (cur > ans)
        {
            ans = cur;
            ans_l = min_pos + 1;
            ans_r = r;
        }
        if (sum < min_sum)
        {
            min_sum = sum;
            min_pos = r;
        }
    }
}