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
    //ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll t;
    cin>>t;

    while(t--){
        ll n,m,k;
        cin>>n>>m>>k;

        ll x[n+1];
        for(ll i=1;i<=n;i++){
            cin>>x[i];
        }

        vector<ll> g[n+1];
        ll c[n+1];
        memset(c,0,sizeof(c));

        for(ll i=0;i<m;i++){
            ll u,v;
            cin>>u>>v;
            g[u].pb(v);
            c[v]++;
        }

        queue<ll> q;
        vector<pair<ll,ll>> temp;
        for(ll i=1;i<=n;i++){
            if(!c[i]){
                q.push(i);
                temp.pb({x[i],i});
            }
        }
        
        ll mx=0;
        while(!q.empty()){
            ll u=q.front();
            mx=max(mx,x[u]);
            q.pop();

            for(ll i=0;i<g[u].size();i++){
                ll v=g[u][i];
                c[v]--;
                if(!c[v]) q.push(v);

                ll d1=x[u]/k;
                ll d2=x[v]/k;
                
                if(d1<d2) continue;
                
                x[v]=(x[v]%k+k*d1);
                if(x[v]>=x[u]) continue;
                x[v]+=k;
            }
        }
        sort(all(temp));
        ll ans=mx-temp[0].first;
        for(ll i=1;i<temp.size();i++){
            queue<ll> q;
            x[temp[i-1].second]=temp[i-1].first+k;
            q.push(temp[i-1].second);
            c[temp[i-1].second]=1;

            while(!q.empty()){
                ll u=q.front();
                mx=max(mx,x[u]);
                q.pop();

                for(ll j=0;j<g[u].size();j++){
                    ll v=g[u][j];
                    if(c[v]) continue;
                    if(x[v]>=x[u]) continue;
                    x[v]+=k;
                    q.push(v);
                    c[v]=1;
                }
            }
            ans=min(ans,mx-temp[i].first);
        }

        cout<<ans<<"\n";
    }

    return 0;
}