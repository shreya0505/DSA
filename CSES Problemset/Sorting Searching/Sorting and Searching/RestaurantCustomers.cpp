
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

//Keeping track of range updates(Addition and Subtraction)

void solve()
{
    ll n;
    cin >> n;

    std::vector<pair<ll, int>> v;
    int c = 0, m = 0;

    while (n--)
    {
        ll x, y;
        cin >> x >> y;
        v.push_back({x, 1});
        v.push_back({y, -1});
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        c += v[i].second;
        m = max(m, c);
    }
    cout << m << '\n';
}

int main()
{
    return 0;
}