#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define MAXN 800001
ll n, t[MAXN];

void update(ll v, ll tl, ll tr, ll pos, ll new_val)
{
    if (tl == tr)
    {
        t[v] = new_val;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

ll sum(ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
    {
        return t[v];
    }
    ll tm = (tl + tr) / 2;
    return sum(v * 2, tl, tm, l, min(r, tm)) + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void build(ll a[], ll v, ll tl, ll tr)
{
    if (tl == tr)
    {
        t[v] = a[tl];
    }
    else
    {
        ll tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

void solve()
{
    ll n, q;
    cin >> n >> q;
    ll x[n];
    for (ll i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i <= 4 * n; i++)
        t[i] = 0;
    build(x, 1, 0, n - 1);

    while (q--)
    {
        ll c, l, r;
        cin >> c >> l >> r;
        l--; //pos
        r--; //new val
        if (c == 2)
            cout << sum(1, 0, n - 1, l, r) << '\n';
        if (c == 1)
        {
            r++;
            update(1, 0, n - 1, l, r);
        }
    }
}

int main()
{
    return 0;
}