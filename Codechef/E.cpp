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

    ll t,ii=0;
    cin>>t;

    while(t--){
        ll n,m;
        double s,k;
        cin>>n>>m>>s>>k;

        vector<pair<ll,double>> g[n];

        for(ll i=0;i<m;i++){
            ll u,v;
            double w;
            cin>>u>>v>>w;
            w/=100.0;
            if(w==1.0) w-=0.0000000000000001;

            g[u].pb({v,w});
            g[v].pb({u,w});
        }

        priority_queue<pair<double,ll>> pq;
        pq.push({1.0,0});
        double dis[n];
        for(ll i=0;i<n;i++) dis[i]=0.0;
        dis[0]=1.0;

        ll temp=0;
        while(!pq.empty()){
            ll u=pq.top().second;
            pq.pop();
            //cout<<u<<" "<<pq.size()<<endl;
            for(ll i=0;i<g[u].size();i++){
                ll v=g[u][i].first;
                double w=g[u][i].second;
                if(dis[v]>dis[u]*w) continue;
                dis[v]=dis[u]*w;
                pq.push({dis[v],v});
                //cout<<u<<" "<<v<<" "<<dis[v]<<endl;
                //temp++;
            }
            //if(temp>=100) break;
        }
        double ans=2.0*s*k/dis[n-1];
        cout<<fixed<<setprecision(6)<<"Case "<<++ii<<": "<<ans<<endl;
    }

    return 0;
}