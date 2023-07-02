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
 
ll spf[100007],cnt[100007];
 
int main()
{
    freopen("input.txt","r",stdin);
    for(ll i=2;i<100007;i++){
        if(!spf[i]){
            for(ll j=i;j<100007;j+=i){
                if(!spf[j]) spf[j]=i;
            }
        }
    }
 
    for(ll i=3;i<100007;i++){
        ll x=i;
        vector<ll> pr;
        while(x!=1){
            pr.pb(spf[x]);
            pr.pb(spf[x]);
            x/=spf[x];
        }
        sort(all(pr));
        vector<ll> div;
        div.pb(1);
        ll sz=1;
        for(ll j=0;j<pr.size();j++){
            if(j && pr[j]!=pr[j-1]) sz=div.size();
            ll up_sz=div.size();
            for(ll k=up_sz-sz;k<up_sz;k++) div.pb(div[k]*pr[j]);
        }
        sort(all(div));
        set<pair<ll,ll>> xxx;
        for(ll j=0;j<div.size();j++){
            ll d=div[j];
            ll v=(i*i)/d,m;
            if(v%2 != d%2) continue;
            m=v-d+1;
            if(m/2<i) continue;
            ll p=m/2;
            ll q=(m+(d-1)*2)/2+1;
            if(p>q){
                cout<<p<<" "<<q<<endl;
            }
            if(i*i+p*p!=q*q) cout<<i<<" "<<p<<" "<<q<<endl;
            xxx.insert({p,q});
            cnt[i]++;
        }
        if(xxx.size()!=cnt[i]) cout<<i<<endl;
    }
    for(ll i=1;i<100007;i++) cnt[i]+=cnt[i-1];
    
    ll ran=100000;

    ll t=ran;
    //scanf("%lli",&t);
    while(t--){
        ll x=ran-t;
        //scanf("%lli",&x);
        //printf("%lli\n",cnt[x]);

        ll temp;
        cin>>temp;
        if(temp!=cnt[x]) cout<<x<<" "<<temp<<" "<<cnt[x]<<endl;
    }
 
    return 0;
}
