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

ll inp(){
    ll x;
    scanf("%lli",&x);
    ll temp=0;
    for(ll i=0;i<x;i++){
        ll j;
        scanf("%lli",&j);
        temp|=(1<<j);
    }
    return temp;
}

int main()
{

    ll t,ii=0;
    scanf("%lli",&t);

    while(t--){
        ll n,m;
        scanf("%lli %lli",&n,&m);

        ll source=inp();
        ll dest=inp();
        ll cost[m],x[m],y[m];
        for(ll i=0;i<m;i++){
            scanf("%lli",&cost[i]);
            x[i]=inp();
            y[i]=inp();
        }

        ll dis[(1<<n)];
        for(ll i=0;i<(1<<n);i++){
            dis[i]=Max;
        }

        dis[source]=0;

        min_heap<pair<ll,ll>> q;
        q.push({0,source});

        while(!q.empty()){
            ll u=q.top().second;
            ll w=q.top().first;
            q.pop();
            
            if(dis[u]!=w) continue;
            for(ll i=0;i<m;i++){
                if((u|x[i])!=u) continue;
                ll v=(u^x[i])|y[i];
                if(dis[v]<=dis[u]+cost[i]) continue;
                dis[v]=dis[u]+cost[i];
                q.push({dis[v],v});
            }
        }
        
        printf("Case #%lli: ",++ii);
        if(dis[dest]==Max) printf("NO\n");
        else printf("YES %lli\n",dis[dest]);
    }

    return 0;
}