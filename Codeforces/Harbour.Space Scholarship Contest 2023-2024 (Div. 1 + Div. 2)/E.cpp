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

ll mod=998244353;

ll bigmod(ll x,ll p){
    if(!p) return 1;
    if(p%2) return (x*bigmod(x,p-1))%mod;
    ll v=bigmod(x,p/2);
    return (v*v)%mod;
}

int main()
{

    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);

        ll m=0;
        for(ll i=0;i<n;i++){
            ll p=0,x=(1<<30),c=0,pos=n;
            for(ll j=30;j>=0;j--){
                if(a[i]&(1<<j)){
                    p+=x;
                    c++;
                    x/=2;
                    continue;
                }
                ll id=lower_bound(a,a+n,p+x)-a;
                ll d=pos-id;
                //if(d) cout<<pos<<" "<<id<<" "<<d<<" "<<c<<" "<<2*d*c+d+2*d<<" "<<d<<endl;
                pos=id;
                m=(m+2*d*c+d+2*d)%mod;
                x/=2;
            }
            ll d=pos-i-1;
            m=(m+2*d*c+2*d)%mod;
            m=(m+c+1)%mod;
        }

        ll x=(n*n)%mod;
        //cout<<m<<endl;
        m=(m*bigmod(x,mod-2))%mod;
        cout<<m<<"\n";
    }

    return 0;
}