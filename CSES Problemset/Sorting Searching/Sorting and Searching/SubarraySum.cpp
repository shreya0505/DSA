#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void solve(){
    ll n,x;
    cin>>n>>x;
    ll a[n];
    ll sum=0, c=0;
    std::map<ll, ll> f;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        f[sum]++;
        ll t = sum-x;
        c+= f[t];
    }
    
    cout<<c;
        
    
    
}

int main()
{
    return 0;
}