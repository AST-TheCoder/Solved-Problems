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

ll dp[1000001],add_sum=500000,min_sum,max_sum;

int main()
{

    ll n,ans=Max;
    cin>>n;

    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<0) min_sum+=a[i];
        else max_sum+=a[i];
    }
    max_sum+=add_sum;
    min_sum+=add_sum;

    dp[add_sum]=1;
    for(ll i=0;i<n;i++){
        if(a[i]<0){
            for(ll j=min_sum;j-a[i]<=max_sum;j++){
                dp[j]|=dp[j-a[i]];
            }
            continue;
        }
        for(ll j=max_sum;j-a[i]>=min_sum;j--){
            dp[j]|=dp[j-a[i]];
        }
    }

    for(ll i=min_sum;i<=max_sum;i++){
        if(!dp[i]) continue;
        ll p=min_sum-add_sum;
        ll q=max_sum-add_sum;
        ll x=i-add_sum;
        ans=min(ans,abs(2*x-(p+q)));
    }
    cout<<ans<<endl;

    return 0;
}