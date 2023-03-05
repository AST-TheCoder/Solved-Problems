#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 10000000000000000

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;

ll dp[1001][15001];

int main()
{

    ll t,ii=0,mod=100000007;
    scanf("%d",&t);
    
    while(t--){
        ll n,k,s;
        scanf("%d %d %d",&n,&k,&s);

        for(ll i=0;i<=n;i++){
            for(ll j=0;j<=s;j++) dp[i][j]=0;
        }

        dp[0][0]=1;
        for(ll i=0;i<=n;i++){
            for(ll j=i;j<=s;j++){
                if(!i) continue;

                dp[i][j]=dp[i-1][j-1];
                if(j>k){
                    long long int temp=((k+1)*dp[i-1][j-k-1])%mod;
                    if(j-k-1!=0){
                        temp=(dp[i-1][j-k-1]-dp[i-1][j-k-2]+mod)%mod;
                        temp=((k+1)*temp)%mod;
                        temp=(temp+dp[i-1][j-k-2])%mod;
                    }
                    dp[i][j]-=temp;
                    if(dp[i][j]<0) dp[i][j]+=mod;
                }
            }
            for(ll j=1;j<=s && i!=n;j++){
                dp[i][j]+=dp[i][j-1];
                if(dp[i][j]>=mod) dp[i][j]-=mod;
            }
            for(ll j=1;j<=s && i!=n;j++){
                dp[i][j]+=dp[i][j-1];
                if(dp[i][j]>=mod) dp[i][j]-=mod;
            }
        }
        
        printf("Case %d: %d\n",++ii,dp[n][s]);
    }

    return 0;
}