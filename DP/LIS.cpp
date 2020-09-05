#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define boost                    \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define nl "\n"
#define ll long long
#define pb push_back
#define mpr make_pair
#define fr(i, a, n) for (ll i = a; i < n; ++i)
#define fr0(i, n) for (ll i = 0; i < n; ++i)
#define pii pair<int, int>
#define mem(a) memset(a, 0, sizeof(a))
const ll mod = 1000000007;

void fio()
{
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
}

template <typename T>
void TIME(T start, T end)
{
#ifndef ONLINE_JUDGE
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "\nExecuted in: " << fixed
         << time_taken << setprecision(9);
    cout << " sec";
#endif
}

// left shift << multiply by 2
// right shift >> divide by 2

//Time complexity: n2
//Dp approach
vector<int> print_lis(vector<int> const &a)
{
    int n = a.size();
    // d[i] is the length of the longest increasing subsequence that ends in the element at index i
    // p[i] store ancestors

    vector<int> d(n, 1), p(n, -1);
    // d[i] will either be 1 or be maximum of previous d[j]+1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            //a[i] is increasing wrt a[j] and d[j]+1 is longer than current d[i]
            if (a[j] < a[i] && d[i] < d[j] + 1)
            {
                d[i] = d[j] + 1;
                //save ancestor of a[i] as j
                p[i] = j;
            }
        }
    }
    //finding max d[i]
    int ans = d[0], pos = 0;
    for (int i = 1; i < n; i++)
    {
        if (d[i] > ans)
        {
            ans = d[i];
            pos = i;
        }
    }

    //backtracking to get sequence in reverse
    vector<int> subseq;
    while (pos != -1)
    {
        subseq.push_back(a[pos]);
        pos = p[pos];
    }

    reverse(subseq.begin(), subseq.end());
    return subseq;
}

int lis_nlogn_idea(vector<int> const &a)
{
    int n = a.size();
    //d[i]  is the smallest element at which a subsequence of length i terminates
    const int INF = 1e9;
    vector<int> d(n + 1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            //a[i] is next increasing element
            //a[i] is smaller than last element largest subs of length j
            if (d[j - 1] < a[i] && a[i] < d[j])
                d[j] = a[i];
        }
    }

    int ans = 0;
    //Farthest valid d[i] is the max length
    for (int i = 0; i <= n; i++)
    {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}

input : 10 2 8 33 21 50 41 60 80

    i dp[] 0 10 1000 1000 1000 1000 1000 1000 1000 1000 1 2 1000 1000 1000 1000 1000 1000 1000 1000 2 2 8 1000 1000 1000 1000 1000 1000 1000 3 2 8 33 1000 1000 1000 1000 1000 1000 4 2 8 21 1000 1000 1000 1000 1000 1000 5 2 8 21 50 1000 1000 1000 1000 1000 6 2 8 21 41 1000 1000 1000 1000 1000 7 2 8 21 41 60 1000 1000 1000 1000 8 2 8 21 41 60 80 1000 1000 1000

    //Time complexity: nlogn
    //The array d will always be sorted
    //a[i] will only update at most one value  d[j]
    // find this element in the array d[] using binary search in O(logn)
    int lis(vector<int> const &a)
{
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n + 1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++)
    {
        // look in the array d[] for the first number that is strictly greater than a[i]
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j - 1] < a[i] && a[i] < d[j])
            d[j] = a[i];
    }

    bool sortbysec(const tuple<int, int, int>& a,  
               const tuple<int, int, int>& b) 
{ 
    return (get<1>(a) < get<1>(b)); 
} 

    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}

void solve()
{

    std::vector<int> v;
    fr0(i, 8)
    {
        int x;
        cin >> x;
        v.pb(x);
    }
    cout << lis(v);
}

int main()
{
    auto start = chrono::high_resolution_clock::now();
    boost;
    fio();
    ll t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    auto end = chrono::high_resolution_clock::now();
    TIME(start, end);
    return 0;
}