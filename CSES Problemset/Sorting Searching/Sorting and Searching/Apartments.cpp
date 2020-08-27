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

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    ll a[n];
    ll b[n];

    fr0(i, n)
            cin >>
        a[i];

    fr0(i, m)
            cin >>
        b[i];

    sort(a, a + n);
    sort(b, b + m);

    ll c = 0;

    ll i = 0, ptr = 0;
    while (i < n && ptr < m)
    {
        if (b[ptr] >= a[i] - k && b[ptr] <= a[i] + k)
        {
            ptr++;
            c++;
            i++;
        }
        else
        {
            if (a[i] - k >= b[ptr])
                ptr++;
            else
                i++;
        }
    }

    cout << c << '\n';
}

int main()
{
    //auto start = chrono::high_resolution_clock::now();
    // boost;
    // fio();
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    //auto end = chrono::high_resolution_clock::now();
    //TIME(start, end);
    return 0;
}