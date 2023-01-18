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

vector<ll> pr[300001],g[300001];
ll chk[300001],par[300001];

int main()
{

    for(ll i=2;i<=300000;i++){
        if(pr[i].size()==0){
            for(ll j=i;j<=300000;j+=i){
                pr[j].pb(i);
            }
        }
    }

    ll n;
    cin>>n;

    vector<pair<ll,ll>> a;
    ll p[n+1];
    for(ll i=1;i<=n;i++){
        cin>>p[i];
    }

    ll s,t;
    cin>>s>>t;

    if(s==t){
        cout<<1<<endl<<s<<endl;
        return 0;
    }

    if(__gcd(p[s],p[t])!=1){
        cout<<2<<endl;
        cout<<s<<" "<<t<<endl;
        return 0;
    }

    a.pb({p[s],s});
    chk[p[s]]=1;
    for(ll i=0;i<pr[p[s]].size();i++) g[pr[p[s]][i]].pb(s);

    a.pb({p[t],t});
    chk[p[t]]=1;
    for(ll i=0;i<pr[p[t]].size();i++) g[pr[p[t]][i]].pb(t);

    for(ll i=1;i<=n;i++){
        if(chk[p[i]]) continue;
        chk[p[i]]=1;
        a.pb({p[i],i});
        for(ll j=0;j<pr[p[i]].size();j++) g[pr[p[i]][j]].pb(i);
    }

    ll d[n+1];
    memset(d,0,sizeof(d));

    queue<pair<ll,ll>> q;
    q.push(a[0]);
    d[a[0].second]=1;
    memset(chk,0,sizeof(chk));

    while(!q.empty()){
        ll u=q.front().second;
        ll w=q.front().first;
        q.pop();
        for(ll i=0;i<pr[w].size();i++){
            ll val=pr[w][i];
            if(chk[val]) continue;
            chk[val]=1;

            for(ll j=0;j<g[val].size();j++){
                ll v=g[val][j];
                if(d[v]) continue;
                q.push({p[v],v});
                d[v]=d[u]+1;
                par[v]=u;
            }
        }
    }

    if(!d[t]){
        cout<<-1<<endl;
        return 0;
    }

    vector<ll> ans;
    ll temp=t;
    while(temp){
        ans.pb(temp);
        temp=par[temp];
    }
    reverse(all(ans));

    cout<<ans.size()<<endl;
    for(ll i=0;i<ans.size();i++) cout<<ans[i]<<" ";cout<<endl;

    return 0;
}