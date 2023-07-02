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

    read:
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<ll> g[n+1],rev_g[n+1];

        for(ll i=0;i<m;i++){
            ll u,v;
            cin>>u>>v;
            g[v].pb(u);
            rev_g[u].pb(v);
        }

        vector<ll> lev[n+1];
        ll dis[n+1];
        queue<ll> q;
        q.push(1);
        memset(dis,-1,sizeof(dis));
        dis[1]=1;
        lev[1].pb(1);
        while(!q.empty()){
            ll u=q.front();
            q.pop();
            for(ll i=0;i<g[u].size();i++){
                ll v=g[u][i];
                if(dis[v]!=-1) continue;
                q.push(v);
                dis[v]=dis[u]+1;
                lev[dis[v]].pb(v);
            }
        }

        for(ll i=1;i<=n;i++){
            if(dis[i]==-1){
                cout<<"INFINITE"<<endl;
                goto read;
            }
        }

        cout<<"FINITE"<<endl;
        vector<ll> ans;
        for(ll i=1;i<=n;i++){
            ll temp[n+1];
            memset(temp,-1,sizeof(temp));
            for(ll j=0;j<lev[i].size();j++){
                ll u=lev[i][j],mn=Max;
                for(ll k=0;k<rev_g[u].size();k++){
                    ll v=rev_g[u][k];
                    if(temp[v]==-1) continue;
                    mn=min(mn,temp[v]);
                }
                if(mn=Max) mn=j;
                for(ll k=1;k<=n;k++){
                    if(temp[k]>=mn) temp[k]++;
                }
                temp[u]=mn;
            }
            for(ll j=1;j<=n;j++){
                if(temp[j]==-1) continue;
                lev[i][temp[j]]=j;
            }
        }
        //cout<<"CHK"<<endl;
        for(ll i=n,ran=1;i>=1;i--,ran++){
            for(ll j=n;j>=ran;j--){
                for(ll k=0;k<lev[j].size();k++){
                    ll u=lev[j][k];
                    ans.pb(u);
                }
            }
        }
        cout<<ans.size()<<endl;
        for(ll i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}