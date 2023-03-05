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
        ll h,w;
        cin>>h>>w;

        ll a[h+2][w+2],dp[h+2][w+2];
        memset(dp,0,sizeof(dp));

        for(ll i=1;i<=h+1;i++){
            for(ll j=0;j<=w+1;j++){
                if(!j || j==w+1 || i==h+1) a[i][j]=0;
                else cin>>a[i][j];
            }
        }
        ll ans=0;
        for(ll i=h;i>=1;i--){
            for(ll j=1;j<=w;j++){
                dp[i][j]=a[i][j]+max(dp[i+1][j-1],max(dp[i+1][j],dp[i+1][j+1]));
                if(i==1) ans=max(ans,dp[i][j]);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
