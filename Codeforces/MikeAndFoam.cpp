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

ll chk[500001],cnt[500001];
vector<ll> pr;

int main()
{

    for(ll i=2;i<=500000;i++){
        if(!chk[i]){
            pr.pb(i);
            for(ll j=i;j<=500000;j+=i) chk[j]=1;
        }
        chk[i]=0;
    }
    

    ll n,q;
    scanf("%lli %lli",&n,&q);

    ll a[n+1],ans=0;
    for(ll i=1;i<=n;i++) scanf("%lli",&a[i]);

    while(q--){
        ll idx;
        scanf("%lli",&idx);
        ll val=a[idx];

        vector<ll> p;

        for(ll i=0;i<pr.size() && pr[i]*pr[i]<=val;i++){
            if(val%pr[i]) continue;
            while(val%pr[i]==0) val/=pr[i];
            p.pb(pr[i]);
        }

        if(val!=1) p.pb(val);

        vector<pair<ll,ll>> temp;
        temp.pb({1,0});
        for(ll i=0;i<p.size();i++){
            ll sz=temp.size();
            for(ll j=0;j<sz;j++){
                val=temp[j].first*p[i];
                ll c=temp[j].second+1;
                temp.pb({val,c});
            }
        }

        for(ll i=0;i<temp.size();i++){
            val=temp[i].first;
            ll c=temp[i].second;
            if(!chk[idx]){
                if(c%2) ans-=cnt[val];
                else ans+=cnt[val];
                cnt[val]++;
            }
            else{
                cnt[val]--;
                if(c%2) ans+=cnt[val];
                else ans-=cnt[val];
            }
        }

        chk[idx]=(chk[idx]==0);
        printf("%lli\n",ans);
    }

    return 0;
}