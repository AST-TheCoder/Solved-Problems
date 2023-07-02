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

ll a[1000001],cnt[1000001],c[1000001],mod=1000000007;
ll lpf[1000001];

ll upd(ll i,ll ans){
    ll x=a[i];
    set<ll> temp;
    while(x!=1){
        c[lpf[x]]++;
        temp.insert(lpf[x]);
        x/=lpf[x];
    }
    for(auto p: temp){
        while(cnt[p]<c[p]){
            ans=(ans*p)%mod;
            cnt[p]++;
        }
        c[p]=0;
    }
    return ans;
}

int main()
{

    for(ll i=2;i<=1000000;i++){
        if(!lpf[i]){
            for(ll j=i;j<=1000000;j+=i){
                lpf[j]=i;
            }
        }
    }

    ll n;
    cin>>n;

    for(ll i=1;i<=n;i++){
        cin>>a[i];
        assert(a[i]>1 && a[i]<=1000000);
    }
    
    vector<ll> q;
    ll l=1,r=n;
    for(ll i=1;i<n;i++){
        char x;
        cin>>x;
        if(x=='B'){
            q.pb(0);
            l++;
        }
        else if(x=='E'){
            q.pb(1);
            r--;
        }
    }

    ll ans=a[l];
    while(a[l]!=1){
        cnt[lpf[a[l]]]++;
        a[l]/=lpf[a[l]];
    }
    vector<ll> res;
    for(ll i=n-2;i>=0;i--){
        res.pb(ans);
        if(q[i]==0){
            l--;
            ans=upd(l,ans);
        }
        else{
            r++;
            ans=upd(r,ans);
        }
    }
    res.pb(ans);
    reverse(all(res));

    for(ll i=0;i<n;i++){
        cout<<res[i]<<endl;
    }

    return 0;
}