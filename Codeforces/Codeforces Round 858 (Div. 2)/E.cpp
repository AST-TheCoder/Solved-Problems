#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 10000000000000000

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;
const int N=100000;

ll a[N+1],p[N+1],c[N+1],d[N+1],h[N+1],sq=400;
long long int mem[N+1][401];

void dfs(ll u){
    if(!u) return;
    if(!d[p[u]]) dfs(p[u]);
    d[u]=d[p[u]]+1;
    c[d[u]]++;
    h[u]=c[d[u]];
}

long long int solve(ll u,ll v){
    if(!u && !v) return 0;

    if(u>v) swap(u,v);
    if(h[v]<=sq && mem[u][h[v]]) return mem[u][h[v]];
    
    long long int ans=solve(p[u],p[v])+(long long int)a[u]*(long long int)a[v];
    if(h[v]<=sq) mem[u][h[v]]=ans;
    return ans;
}

int main()
{

    ll n,q;
    scanf("%d %d",&n,&q);
    for(ll i=1;i<=n;i++) scanf("%d",&a[i]);
    p[1]=0;
    for(ll i=2;i<=n;i++){
        scanf("%d",&p[i]);
    }

    for(ll i=1;i<=n;i++) dfs(i);

    while(q--){
        ll u,v;
        scanf("%d %d",&u,&v);
        long long int ans=solve(u,v);
        printf("%lli\n",ans);
    }

    return 0;
}