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

ll dp[1000001];

int main()
{

    ll t;
    cin>>t;

    while(t--){
        ll w,f;
        cin>>w>>f;

        ll n;
        cin>>n;

        ll s=0;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
            s+=a[i];
        }
        for(ll i=1;i<=s;i++) dp[i]=0;
        ll ans=s;
        dp[0]=1;
        ans=min(ans,s/w+(s%w!=0));
        ans=min(ans,s/f+(s%f!=0));

        for(ll i=0;i<n;i++){
            for(ll j=s;j>=a[i];j--){
                if(dp[j-a[i]]) dp[j]=1;
                if(dp[j]){
                    ans=min(ans,max(j/w+(j%w!=0),(s-j)/f+((s-j)%f!=0)));
                    ans=min(ans,max(j/f+(j%f!=0),(s-j)/w+((s-j)%w!=0)));
                }
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}