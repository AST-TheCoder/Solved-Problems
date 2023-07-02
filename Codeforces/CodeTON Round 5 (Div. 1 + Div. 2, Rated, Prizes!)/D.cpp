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

    ll n,m;
    cin>>n>>m;

    vector<pair<ll,ll>> g[n+1];
    vector<ll> x;
    ll s[n+1];
    memset(s,-1,sizeof(s));

    for(ll i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].pb({w,v});
        g[v].pb({w,u});
    }

    for(ll i=1;i<=n;i++) sort(all(g[i]),greater<pair<ll,ll>>());

    ll t=0;
    vector<pair<string,ll>> ans;
    string p;
    for(ll i=0;i<n;i++) p+='1';
    p[n-1]='0';
    x.pb(n);
    s[n]=0;

    //cout<<x.size()<<endl;
    while(x.size()!=n){
        ll k=Max;
        for(ll i=0;i<x.size();i++){
            ll u=x[i];
            if(g[u].size()==0) continue;
            ll temp=g[u][g[u].size()-1].first+s[u]-t;
            k=min(k,temp);
        }
        if(k==Max){
            t=-1;
            break;
        }
        ans.pb({p,k});
        for(ll i=0;i<x.size();i++){
            ll u=x[i];
            if(g[u].size()==0) continue;
            for(ll j=g[u].size()-1;j>=0;j--){
                ll v=g[u][j].second;
                if(s[v]!=-1){
                    g[u].pop_back();
                    continue;
                }
                ll w=g[u][j].first+s[u]-t;
                if(w==k){
                    x.pb(v);
                    p[v-1]='0';
                    s[v]=t+k;
                    g[u].pop_back();
                }
                else break;
            }
        }
        t+=k;
        if(p[0]=='0') break;
    }

    if(t==-1) cout<<"inf"<<endl;
    else{
        cout<<t<<" "<<ans.size()<<endl;
        for(ll i=0;i<ans.size();i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }

    return 0;
}