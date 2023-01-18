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

ll chk[200000];

int main()
{

    ll n;
    cin>>n;

    ll a[n];
    for(ll i=0;i<n;i++) cin>>a[i];

    chk[100000]=1;

    ll ans=1,mod=998244353;
    for(ll i=1;i<n-1;i++){
        ans=(2*ans-chk[100000+a[i]]+mod)%mod;
        //cout<<i<<" "<<ans<<endl;
        ll temp[200000];
        memset(temp,0,sizeof(temp));
        for(ll j=a[i];j<200000-a[i];j++){
            temp[j-a[i]]=(temp[j-a[i]]+chk[j])%mod;
            temp[j+a[i]]=(temp[j+a[i]]+chk[j])%mod;
        }
        for(ll j=0;j<200000;j++) chk[j]=(chk[j]+temp[j])%mod;
    }

    cout<<ans<<endl;

    return 0;
}