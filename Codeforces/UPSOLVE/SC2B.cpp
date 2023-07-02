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

ll n,a[100001],val[100001],s=0;
vector<ll> g[100001];

void dfs(ll u,ll p){
    val[u]=1;
    if(g[u].size()==1) return;
    for(ll i=0;i<g[u].size();i++){
        ll v=g[u][i];
        if(v==p) continue;
        dfs(v,u);
        if(val[v]==-1){
            val[u]=-1;
            return;
        }
        ll temp=__gcd(val[u],val[v]);
        if(s/val[u]<val[v]/temp){
            val[u]=-1;
            return;
        }
        val[u]*=val[v]/temp;
    }

    if(s/val[u]<(g[u].size()-1)){
        val[u]=-1;
        return;
    }
    val[u]*=(g[u].size()-1);
    //cout<<u<<" "<<val[u]<<endl;
}

ll chk_dfs(ll u,ll p,ll sum){
    if(g[u].size()==1){
        if(a[u]>=sum) return 1;
        else return 0;
    }
    ll chk=1;
    for(ll i=0;i<g[u].size();i++){
        ll v=g[u][i];
        if(v==p) continue;
        chk&=chk_dfs(v,u,sum/(g[u].size()-1));
    }
    return chk;
}

int main()
{

    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        s+=a[i];
    }
    for(ll i=1;i<n;i++){
        ll u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    g[1].pb(0);
    queue<ll> q;

    for(ll i=1;i<=n;i++){
        if(g[i].size()==1){
            if(!a[i]){
                cout<<s<<endl;
                return 0;
            }
        }
    }

    dfs(1,0);
    if(val[1]==-1){
        cout<<s<<endl;
        return 0;
    }

    ll l=1,r=s/val[1],ans=s;
    while(l<=r){
        ll m=(l+r)/2;
        ll chk=chk_dfs(1,0,val[1]*m);

        if(chk){
            ans=min(ans,s-m*val[1]);
            l=m+1;
        }
        else r=m-1;
    }
    
    cout<<ans<<endl;

    return 0;
}