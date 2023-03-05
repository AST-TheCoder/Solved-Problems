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

ll chk[1000007];
vector<ll> pr;

int main()
{

    ll n,k;
    cin>>n>>k;

    if(n%k || k==1){
        cout<<0<<endl;
        return 0;
    }

    for(ll i=2;i<1000007;i++){
        if(!chk[i]){
            pr.pb(i);
            for(ll j=i;j<1000007;j+=i) chk[j]=1;
        }
    }

    ll ans=k;
    for(ll i=0;i<pr.size();i++){
        if(k%pr[i]) continue;
        ans/=pr[i];
        ans*=(pr[i]-1);
        while(k%pr[i]==0) k/=pr[i];
    }
    if(k!=1){
        ans/=k;
        ans*=(k-1);
    }
    cout<<ans<<endl;

    return 0;
}