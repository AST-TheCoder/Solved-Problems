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

ll a[(1<<18)+1];
vector<pair<pair<ll,ll>,pair<ll,ll>>> pre_cal[2000000];

void build(ll n,ll l,ll r,ll p){
    if(l==r){
        pre_cal[n].pb({{max(a[l],0LL),max(a[l],0LL)},{a[l],max(a[l],0LL)}});
        return;
    }

    ll left=2*n;
    ll right=2*n+1;

    build(left,l,(l+r)/2,p/2);
    build(right,(l+r)/2+1,r,p/2);

    for(ll i=0;i<p/2;i++){
        ll u=max(pre_cal[left][i].first.first,pre_cal[left][i].second.first+pre_cal[right][i].first.first);
        ll v=max(pre_cal[right][i].first.second,pre_cal[right][i].second.first+pre_cal[left][i].first.second);
        ll x=pre_cal[left][i].second.first+pre_cal[right][i].second.first;
        ll y=max(pre_cal[left][i].second.second,pre_cal[right][i].second.second);
        y=max(y,pre_cal[left][i].first.second+pre_cal[right][i].first.first);
        pre_cal[n].pb({{u,v},{x,y}});
    }

    for(ll i=0;i<p/2;i++){
        ll u=max(pre_cal[right][i].first.first,pre_cal[right][i].second.first+pre_cal[left][i].first.first);
        ll v=max(pre_cal[left][i].first.second,pre_cal[left][i].second.first+pre_cal[right][i].first.second);
        ll x=pre_cal[left][i].second.first+pre_cal[right][i].second.first;
        ll y=max(pre_cal[left][i].second.second,pre_cal[right][i].second.second);
        y=max(y,pre_cal[right][i].first.second+pre_cal[left][i].first.first);
        pre_cal[n].pb({{u,v},{x,y}});
    }

    return;
}

int main()
{

    ll n;
    cin>>n;

    for(ll i=0;i<(1<<n);i++) cin>>a[i];

    build(1,0,(1<<n)-1,(1<<n));
    ll idx=0;

    ll q;
    cin>>q;

    while(q--){
        ll k;
        cin>>k;

        idx^=(1<<k);
        cout<<pre_cal[1][idx].second.second<<endl;
    }

    return 0;
}