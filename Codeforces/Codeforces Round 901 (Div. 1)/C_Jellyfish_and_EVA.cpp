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

    while(t--){
        ll n,m;
        cin>>n>>m;

        vector<ll> g[n+1];
        ll cnt[n+1];
        memset(cnt,0,sizeof(cnt));
        for(ll i=0;i<m;i++){
            ll u,v;
            cin>>u>>v;
            g[u].pb(v);
            cnt[v]++;
        }
        double pro[n+1];
        for(ll i=0;i<=n;i++) pro[i]=0.0;
        pro[1]=1.0;

        queue<ll> q;
        q.push(1);

        while(!q.empty()){
            ll u=q.front();
            q.pop();

            ll x=g[u].size();
            double c=0.0,mul=1.0/((double)(x*x));

            while(x>0){
                c+=mul;
                mul*=(double)(x-1)*(double)(x-2);
                x-=2;
            }

            for(ll i=0;i<g[u].size();i++){
                ll v=g[u][i];
                cnt[v]--;
                if(!cnt[v]) q.push(v);
                pro[v]=max(pro[v],pro[u]*c);
            }

            cout<<u<<" "<<pro[u]<<endl;
        }

        cout<<fixed<<setprecision(12)<<pro[n]<<endl;

    }

    return 0;
}