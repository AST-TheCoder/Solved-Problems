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

vector<pair<pair<ll,ll>,pair<ll,ll>>> g[1001];
double dis[1001][11][11];

int main()
{

    ll n,m,k;
    cin>>n>>m>>k;

    for(ll i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        ll x=w,p=0,q=0;
        while(x%2==0){
            p++;
            x/=2;
        }
        while(x%5==0){
            q++;
            x/=5;
        }
        g[u].pb({{v,w},{p,q}});
        g[v].pb({{u,w},{p,q}});
    }

    min_heap<pair<pair<double,ll>,pair<ll,ll>>> q;
    for(ll i=1;i<=n;i++)
        for(ll j=0;j<=k;j++)
            for(ll l=0;l<=k;l++)
                dis[i][j][l]=(double)Max;

    q.push({{0.0,1},{0,0}});
    dis[1][0][0]=0.0;

    while(!q.empty()){
        ll u=q.top().first.second;
        ll x=q.top().second.first;
        ll y=q.top().second.second;
        double w=q.top().first.first;
        q.pop();
        for(ll i=0;i<g[u].size();i++){
            ll v=g[u][i].first.first;
            double c=log10((double)g[u][i].first.second);
            ll xx=min(k,x+g[u][i].second.first);
            ll yy=min(k,y+g[u][i].second.second);
            if(dis[v][xx][yy]<=w+c) continue;
            dis[v][xx][yy]=w+c;
            q.push({{w+c,v},{xx,yy}});
        }
    }
    if(dis[n][k][k]==(double)Max) cout<<-1<<endl;
    else cout<<fixed<<setprecision(10)<<dis[n][k][k]<<endl;

    return 0;
}