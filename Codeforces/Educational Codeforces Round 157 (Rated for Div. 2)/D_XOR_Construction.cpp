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

    ll n;
    cin>>n;

    vector<ll> v[32];

    ll a[n];
    for(ll i=1;i<n;i++) cin>>a[i];

    for(ll i=0,q=2;i<32;i++){
        ll x=(n/q)*(q/2);
        if(n%q>q/2){
            x+=((n%q)-(q/2));
        }
        q*=2;
        ll c=0;
        for(ll j=0,p=0;j<n;j++){
            if(!j){
                v[i].pb(0);
                a[j]=0;
            }
            else{
                if(a[j]&(1<<i)){
                    if(!p) p=1;
                    else p=0;
                }
                if(p) c++;
                v[i].pb(p);
            }
        }
        if(c!=x){
            for(ll j=0;j<n;j++){
                if(v[i][j]) v[i][j]=0;
                else v[i][j]=1;
            }
        }
    }

    ll ans[n];
    memset(ans,0,sizeof(ans));
    for(ll j=0;j<n;j++){
        for(ll i=0,p=1;i<32;i++){
            if(v[i][j]) ans[j]+=p;
            p*=2;
        }
        cout<<ans[j]<<" ";
    }
    cout<<endl;

    return 0;
}