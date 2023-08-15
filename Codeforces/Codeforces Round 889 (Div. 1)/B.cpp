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

bitset<200001> chk;
ll p[200001];
int main()
{

    ll n;
    cin>>n;

    ll a[n+1];
    for(ll i=1;i<=n;i++) cin>>a[i];
    ll ans=a[1];
    for(ll i=1;i<=200000;i++){
        p[i]=p[i-1];
        if(i<=n) p[i]+=a[i];
    }

    chk[1]=1;
    for(ll i=1;i<=200000;i++){
        if(chk[i]) ans=max(ans,p[i]-(i-1));
        if(i<=n){
            if(chk.any()){
                chk|=(chk<<a[i]);
                chk[i]=0;
            }
            else break;
        } 
    }

    cout<<ans<<endl;

    return 0;
}