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

vector<ll> q[501];
vector<pair<ll,ll>> g[100001];
ll n,m,ans,val[100001][501];

void dfs(ll u,ll p){
    val[u][1]++;
    for(ll i=0;i<g[u].size();i++){
        ll v=g[u][i].first;
        if(p==v) continue;
        ll s[m];
        memset(s,0,sizeof(s));
        ll w=g[u][i].second;
        dfs(v,u);
        for(ll j=0;j<m;j++){
            ll temp=(j*w)%m;
            s[(__gcd(temp,m))%m]+=val[v][j];
        }
        for(ll j=0;j<m;j++){
            if(!s[j]) continue;
            for(ll k=0;k<q[j].size();k++){
                ans+=val[u][q[j][k]]*s[j];
            }
        }
        for(ll j=0;j<m;j++){
            ll temp=(j*w)%m;
            val[u][(__gcd(temp,m))%m]+=val[v][j];
        }
    }
}

int main()
{

    scanf("%lli %lli",&n,&m);

    ll cnt=0;
    for(ll i=0;i<m;i++){
        if(i && m%i) continue;
        for(ll j=0;j<m;j++){
            if((i*j)%m==0 && (j==0 || i==0 || m%j==0)){
                q[i].pb(j);
                //cout<<i<<" "<<j<<endl;
                cnt++;
            }
        }
    }
    //cout<<cnt<<endl;

    for(ll i=1;i<n;i++){
        ll u,v,w;
        scanf("%lli %lli %lli",&u,&v,&w);
        w%=m;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }

    dfs(1,-1);
    printf("%lli\n",ans);

    return 0;
}