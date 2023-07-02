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

    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];

        ll dp[n+1],nxt[n+1];
        memset(dp,0,sizeof(dp));
        memset(nxt,-1,sizeof(nxt));

        for(ll i=n-1;i>=0;i--){
            dp[i]=dp[i+1];
            if(nxt[a[i]]!=-1){
                dp[i]=max(dp[i],nxt[a[i]]-i+1);
            }
            nxt[a[i]]=max(nxt[a[i]],dp[i+1]+i);
        }

        cout<<dp[0]<<endl;
    }

    return 0;
}