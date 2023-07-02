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

vector<ll> g[2007],cyc;
ll vis[2007];

void dfs(ll u,ll p,ll s){
    vis[u]=1;
    for(ll i=0;i<g[u].size();i++){
        ll v=g[u][i];
        if(vis[v]){
            if(v==s && v!=p){
                vis[u]=2;
                cyc.pb(u);
                return;
            }
            continue;
        }
        dfs(v,u,s);
        if(vis[v]==2){
            vis[u]=2;
            cyc.pb(u);
            return;
        }
    }
}

int main()
{

    ll t;
    cin>>t;

    while(t--){
        ll n,m;
        cin>>n>>m;

        for(ll i=1;i<=m;i++){
            ll u,v;
            cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
        }
        ll ok=0;
        for(ll i=1;i<=n;i++){
            if(g[i].size()<4) continue;
            for(ll j=1;j<=n;j++) vis[j]=0;
            dfs(i,-1,i);
            if(vis[i]==2){
                reverse(all(cyc));
                ok=1;
                break;
            }
        }
        if(!ok){
            cout<<"NO"<<"\n";
            for(ll i=1;i<=n;i++){
                vis[i]=0;
                g[i].clear();
            }
            cyc.clear();
            continue;
        }
        cout<<"YES"<<"\n";
        ll u=cyc[0],c=0;
        vector<ll> x;
        for(ll k=0;k<2;k++){
            for(ll i=0;i<g[u].size();i++){
                ll v=g[u][i],f=1;
                for(ll j=1;j<cyc.size();j++){
                    if(v==cyc[j]){
                        if(j==1 || j==cyc.size()-1){
                            f=0;
                            break;
                        }
                        v=cyc[cyc.size()-1];
                        while(cyc.size()>3 && cyc.size()!=j+1){
                            cyc.pop_back();
                        }
                        break;
                    }
                }
                if(f){
                    x.pb(v);
                    for(ll j=0;j<g[u].size();j++){
                        if(v==g[u][j]){
                            g[u].erase(g[u].begin()+j);
                            break;
                        }
                    }
                    break;
                }
            }
        }
        cout<<cyc.size()+2<<"\n";
        cout<<u<<" "<<x[0]<<"\n";
        cout<<u<<" "<<x[1]<<"\n";
        for(ll i=0;i<cyc.size();i++){
            if(i+1==cyc.size()) cout<<cyc[i]<<" "<<cyc[0]<<"\n";
            else cout<<cyc[i]<<" "<<cyc[i+1]<<"\n";
        }
        for(ll i=1;i<=n;i++){
            vis[i]=0;
            g[i].clear();
        }
        cyc.clear();
    }

    return 0;
}