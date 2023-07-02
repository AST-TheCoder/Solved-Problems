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

ll mod=1000000007;

ll p[100007],d[10000007],c[10000007],f[100007],inv[100007],spf[10000007];

ll bigmod(ll n,ll p){
    if(!p) return 1;
    if(p%2) return (n*bigmod(n,p-1))%mod;
    ll x=bigmod(n,p/2);
    return (x*x)%mod;
}

int main()
{

    p[0]=1;
    f[0]=1;
    inv[0]=bigmod(f[0],mod-2);
    for(ll i=1;i<=100000;i++){
        p[i]=(p[i-1]*2)%mod;
        f[i]=(f[i-1]*i)%mod;
        inv[i]=bigmod(f[i],mod-2);
    }

    for(ll i=2;i<=10000000;i++){
        if(!spf[i]){
            for(ll j=i;j<=10000000;j+=i){
                if(spf[j]) continue;
                spf[j]=i;
            }
        }
    }

    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        vector<ll> v,div;

        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;
            v.pb(x);
            c[x]++;
        }

        sort(all(v));
        v.resize(unique(v.begin(),v.end())-v.begin());
        ll ans=0;

        for(auto x: v){
            ans=(ans+p[c[x]]-1+mod)%mod;
            vector<ll> temp,pr;
            ll temp_val=x,sz=1;
            while(temp_val!=1){
                pr.pb(spf[temp_val]);
                temp_val/=spf[temp_val];
            }

            temp.pb(1);
            ll mul=1;
            for(ll i=0;i<pr.size();i++){
                if(i && pr[i]!=pr[i-1]){
                    sz=temp.size();
                    mul=1;
                }
                mul*=pr[i];
                for(ll j=0;j<sz;j++) temp.pb(temp[j]*mul);
            }

            for(auto i: temp){
                div.pb(i);
                d[i]+=c[x];
                if(i<=c[x]){
                    ll val=(f[c[x]]*inv[i])%mod;
                    val=(val*inv[c[x]-i])%mod;
                    ans=(ans-val+mod)%mod;
                }
            }
            c[x]=0;
        }

        sort(all(div));
        div.resize(unique(div.begin(),div.end())-div.begin());

        for(auto x: div){
            if(d[x]<x || x==1){
                d[x]=0;
                continue;
            }
            ll val=(f[d[x]]*inv[x])%mod;
            val=(val*inv[d[x]-x])%mod;
            ans=(ans+val)%mod;
            d[x]=0;
        }
        cout<<ans<<endl;
    }

    return 0;
}