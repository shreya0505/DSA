

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fr0(i, n) for (ll i = 0; i < n; ++i)

void solve()
{
    ll n;
    cin >> n;
    ll a[n];
    fr0(i, n)
            cin >>
        a[i];

    multiset<ll> maximas;
    ll t = 0;
    for (ll i = 0; i < n; i++)
    {
        if (maximas.upper_bound(a[i]) == maximas.end())
        {
            // cout<<a[i]<<' '<<"MAXIMA";
            maximas.insert(a[i]);
            t++;
        }
        else
        {
            auto it = maximas.upper_bound(a[i]);
            // cout<<a[i]<<' '<<"INSERT";
            maximas.erase(it);
            maximas.insert(a[i]);
        }
    }

    cout << t;
}

int main()
{
    return 0;
}