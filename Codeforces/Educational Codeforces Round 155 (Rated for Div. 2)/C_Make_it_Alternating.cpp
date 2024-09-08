#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 10000000000000000

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;

ll mod=998244353,fact[200001],inv[200001];
ll bigmod(ll n,ll p){
    if(!p) return 1;
    if(p%2) return (n*bigmod(n,p-1))%mod;
    ll x=bigmod(n,p/2);
    return (x*x)%mod;
}

int main()
{

    fact[0]=inv[0]=1;
    for(ll i=1;i<=200000;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }

    ll t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;
        s+='#';

        ll x=0,y=1,c=1;
        for(ll i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                c++;
                continue;
            }

            x+=(c-1);
            y=(y*c)%mod;
            c=1;
        }

        y=(y*fact[x])%mod;

        cout<<x<<" "<<y<<endl;
    }

    return 0;
}