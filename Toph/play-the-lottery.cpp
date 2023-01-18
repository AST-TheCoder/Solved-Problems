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

ll cnt[100007],mod=786433,pos[100007];
vector<pair<ll,ll>> v[100007];

bool cmp(vector<pair<ll,ll>> x, vector<pair<ll,ll>> y){
    if(x.size()<=y.size()) return true;
    return false;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output_mine.txt","w",stdout);
    memset(pos,-1,sizeof(pos));
    ll n;
    cin>>n;

    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;

        for(ll j=0;j<x;j++){
            pair<ll,ll> y;
            cin>>y.first>>y.second;
            v[i].pb(y);
        }
    }
    sort(v,v+n,cmp);
    vector<ll> sum;
    sum.pb(0);
    cnt[0]=1;

    for(ll i=0;i<n;i++){
        vector<ll> temp,c;
        for(ll j=0;j<v[i].size();j++){
            for(ll k=0;k<sum.size();k++){
                ll s=v[i][j].first+sum[k];
                if(pos[s]==-1){
                    pos[s]=temp.size();
                    temp.pb(s);
                    c.pb((cnt[sum[k]]*v[i][j].second)%mod);
                    continue;
                }
                ll val=(cnt[sum[k]]*v[i][j].second)%mod;
                c[pos[s]]=(c[pos[s]]+val)%mod;
            }
        }
        for(ll j=0;j<sum.size();j++) cnt[sum[j]]=0;
        sum.clear();
        for(ll j=0;j<temp.size();j++){
            pos[temp[j]]=-1;
            if(!c[j]) continue;
            sum.pb(temp[j]);
            cnt[temp[j]]=c[j];
        }
        temp.clear();
        c.clear();
        //sort(all(sum)); cout<<i<<endl; for(ll i=0;i<sum.size();i++) cout<<sum[i]<<" "<<cnt[sum[i]]<<endl; cout<<endl;
    }

    sort(all(sum));
    for(ll i=0;i<sum.size();i++) cout<<sum[i]<<" "<<cnt[sum[i]]<<"\n";

    return 0;
}