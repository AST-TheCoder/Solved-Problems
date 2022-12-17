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

vector<ll> g[200001];
ll lev[200001],n,d,par[200001][19],ans,m[200001];

void bfs(){
    
    lev[1]=1;
    queue<ll> q;
    q.push(1);

    while(!q.empty()){
        ll u=q.front();
        q.pop();

        for(ll i=0;i<g[u].size();i++){
            ll v=g[u][i];
            if(!lev[v]){
                lev[v]=lev[u]+1;
                q.push(v);
                ll p=u;
                par[v][0]=u;
                for(ll j=1;j<19;j++){
                    p=par[p][j-1];
                    if(!p) break;
                    par[v][j]=p;
                }  
            }
        }
    }

}

int main()
{

    cin>>n>>d;

    for(ll i=1;i<n;i++){
        ll u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }

    bfs();
    

    vector<ll> a,b;

    ll x;
    cin>>x;
    for(ll i=0;i<x;i++){
        ll v;
        cin>>v;
        a.pb(v);
        for(ll j=0;j<19;j++){
            if(d&(1<<j)) v=par[v][j];
        }
        if(v) b.pb(v);
    }
    cin>>x;
    for(ll i=0;i<x;i++){
        ll v;
        cin>>v;
        b.pb(v);
        for(ll j=0;j<19;j++){
            if(d&(1<<j)) v=par[v][j];
        }
        if(v) a.pb(v);
    }

    m[1]=1;
    for(ll i=0;i<a.size();i++){
        ll u=a[i];
        while(!m[u]){
            m[u]=1;
            ans+=2;
            u=par[u][0];
        }
    }

    memset(m,0,sizeof(m));
    m[1]=1;
    for(ll i=0;i<b.size();i++){
        ll u=b[i];
        while(!m[u]){
            m[u]=1;
            ans+=2;
            u=par[u][0];
        }
    }

    cout<<ans<<endl;
    

    return 0;
}