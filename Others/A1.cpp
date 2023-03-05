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

ll dp[100001],cnt[100001];

int main()
{

    ll t,ii=0;
    cin>>t;

    while(t--){
        ll n,m;
        cin>>n>>m;

        for(ll i=0;i<=m;i++){
            dp[i]=0;
        }

        ll a[n],c[n],ans=0;
        for(ll i=0;i<n;i++) cin>>a[i];
        for(ll i=0;i<n;i++) cin>>c[i];

        dp[0]=1;
        for(ll i=0;i<n;i++){
            for(ll j=a[i];j<=m;j++){
                if(dp[j] || !dp[j-a[i]]) continue;
                if(cnt[j-a[i]]==c[i]){
                    cnt[j]=c[i];
                    continue;
                }
                ans++;
                dp[j]=1;
                cnt[j]=cnt[j-a[i]]+1;
            }
            for(ll j=0;j<=m;j++) cnt[j]=0;
        }
        cout<<"Case "<<++ii<<": "<<ans<<endl;
    }

    return 0;
}