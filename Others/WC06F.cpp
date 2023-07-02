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

ll par[200001];

ll find_par(ll x){
    if(x==par[x]) return x;
    return par[x]=find_par(par[x]);
}

void dsu(ll u,ll v){
    u=find_par(u);
    v=find_par(v);
    if(u!=v){
        par[u]=v;
    }
}

int main()
{

    ll n;
    scanf("%lli",&n);
    set<ll> v;
    for(ll i=1;i<=n;i++){
        par[i]=i;
        v.insert(i);
    }

    ll q;
    scanf("%lli",&q);


    while(q--){
        ll tp,p,q;
        scanf("%lli %lli %lli",&tp,&p,&q);
        if(tp==1){
            dsu(p,q);
        }
        if(tp==2){
            set<ll>::iterator it=v.upper_bound(p);
            vector<ll> val;
            it--;
            ll id=*it;
            it++;
            while(it!=v.end() && *it<=q){
                dsu(id,*it);
                val.pb(*it);
                it++;
            }
            while(val.size()){
                v.erase(val[val.size()-1]);
                val.pop_back();
            }
        }
        if(tp==3){
            p=find_par(p);
            q=find_par(q);
            if(p==q) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}