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

vector<int> val[1000001],g[1000001];
int p[1000001][21],dis[1000001],cnt,inv[1000001];

void dfs(int u,int par){
    inv[u]=++cnt;
    dis[u]=dis[par]+1;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==par) continue;
        dfs(v,u);
    }
}

int lca(int u,int v){
    if(dis[u]<dis[v]) swap(u,v);

    int lev=20;
    while(dis[u]>dis[v]){
        if(dis[p[u][lev]]>=dis[v]) u=p[u][lev];
        lev--;
    }

    if(u==v) return u;

    for(int j=20;j>=0;j--){
        if(p[u][j]!=p[v][j]){
            u=p[u][j];
            v=p[v][j];
        }
    }
    return p[u][0];
}

int main()
{

    int n,k;
    scanf("%d %d",&n,&k);

    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);

        val[x].pb(i);
    }
    int root;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);

        if(!x) root=i;
        else{
            g[i].pb(x);
            g[x].pb(i);
        }
        p[i][0]=x;
    }

    dfs(root,0);    

    for(int i=1;i<=20;i++){
        for(int j=1;j<=n;j++){
            int par=p[j][i-1];
            p[j][i]=p[par][i-1];
        }
    }

    for(int i=1;i<=k;i++){
        vector<pair<int,int>> temp;
        for(int j=0;j<val[i].size();j++) temp.pb({inv[val[i][j]],val[i][j]});
        sort(all(temp));
        val[i].clear();
        for(int j=0;j<temp.size();j++) val[i].pb(temp[j].second);

        if(!val[i].size()){
            printf("0 ");
            continue;
        }

        int ans=dis[val[i][0]];
        for(int j=1;j<val[i].size();j++){
            int x=lca(val[i][j-1],val[i][j]);
            ans+=dis[val[i][j]]-dis[x];
        }
        printf("%d ",ans);
    }

    return 0;
}