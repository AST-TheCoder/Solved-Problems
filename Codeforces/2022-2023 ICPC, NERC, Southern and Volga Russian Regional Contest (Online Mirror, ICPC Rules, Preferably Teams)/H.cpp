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

vector<ll> a[2001],temp;
ll vis[2001],p[2001];

void dfs(ll u){
    if(vis[u]) return;
    vis[u]=1;
    temp.pb(u);
    for(ll i=0;i<a[u].size();i++) dfs(a[u][i]);
}

void relax(ll u,ll val){
    if(p[u]<val) return;
    p[u]=min(p[u],val-1);
    for(ll i=0;i<a[u].size();i++) relax(a[u][i],p[u]);
}

int main()
{

    ll n,m;
    scanf("%lli %lli",&n,&m);
    for(ll i=1;i<=n;i++){
        scanf("%lli",&p[i]);
    }
    
    for(ll i=1;i<=m;i++){
        ll x,y;
        scanf("%lli %lli",&x,&y);
        a[y].pb(x);
        relax(x,p[y]);
    }

    for(ll i=1;i<=n;i++){
        temp.clear();
        dfs(i);

        ll ans=temp.size();
        sort(all(temp));
        
        for(ll j=0;j<temp.size();j++) vis[temp[j]]=0;
        
        ll cnt[n+1];
        memset(cnt,0,sizeof(cnt));
        for(ll j=1,k=0;j<=n;j++){
            if(k<temp.size() && j==temp[k]){
                k++;
                continue;
            }
            cnt[p[j]]++;
        }
        for(ll j=1,s=ans-1;j<=n;j++){
            s+=cnt[j];
            if(s==j) ans=j+1;
        }
        printf("%lli ",ans);
    }printf("\n");

    return 0;
}