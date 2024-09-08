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

ll a[1000001],c[1000001],spf[1000001],x[1000001],d[1000001];

int main()
{   
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    for(ll i=2;i<=1000000;i++){
        if(!spf[i]){
            for(ll j=i;j<=1000000;j+=i){
                if(!spf[j]) spf[j]=i;
            }
        }
    }
    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        for(ll i=1;i<=n;i++){
            c[i]=d[i]=x[i]=0;
        }

        ll ans=(n*(n-1))/2;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            c[a[i]]++;
        }

        sort(a+1,a+n+1);
        if(a[1]==1){
            cout<<0<<endl;
            continue;
        }
        for(ll i=1;i<=n;i++){
            if(!c[i]) continue;
            vector<ll> pr,div;
            ll temp=i;
            while(temp!=1){
                pr.pb(spf[temp]);
                temp/=spf[temp];
            }
            div.pb(1);
            ll sz=div.size();
            for(ll j=0;j<pr.size();j++){
                if(j && pr[j]!=pr[j-1]) sz=div.size();
                ll temp_sz=div.size();
                for(ll k=temp_sz-sz;k<temp_sz;k++){
                    div.pb(div[k]*pr[j]);
                }
            }
            ans-=(c[i]*(c[i]-1))/2;
            cout<<"CHK "<<i<<" "<<ans<<endl;
            for(ll j=0;j<div.size();j++){
                if(!c[div[j]]) continue;
                if(div[j]!=i){
                    ans+=(x[div[j]]-1)*d[div[j]]*c[i];
                    x[i]-=(x[div[j]]-1);
                }
                d[div[j]]+=c[i];
            }
            cout<<"CHK "<<i<<" "<<ans<<endl;
        }

        cout<<ans<<endl;
    }

    return 0;
}