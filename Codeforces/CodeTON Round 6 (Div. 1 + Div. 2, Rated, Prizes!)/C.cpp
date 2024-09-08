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

int main()
{

    ll t;
    cin>>t;

    while(t--){
        ll n,m;
        cin>>n>>m;

        ll a[n+1],c[n+1],r[n+1];
        vector<ll> x[m+1];
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            r[i]=c[i]=0;
            x[a[i]].pb(i);
        }
        ll pl=1,pr=n,pu=1,pd=n;

        for(ll i=1;i<=m;i++){
            while(c[pl]) pl++;
            while(c[pr]) pr--;
            while(r[pu]) pu++;
            while(r[pd]) pd--;
            if(!x[i].size() || pr<pl || pd<pu) cout<<0<<" ";
            else cout<<(pr-pl+1)+(pd-pu+1)<<" ";
            for(ll j=0;j<x[i].size();j++){
                ll xx=x[i][j];
                c[xx]=r[xx]=1;
            }
        }
        cout<<endl;
    }

    return 0;
}