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

ll dp[101][101][2],chk[101],n,p,q,x,y,mod=1000000007;

ll solve(ll i,ll v,ll d){
    cout<<i<<" "<<v<<" "<<d<<endl;
    if(d){
        ll id=n-1,ok=1;
        for(ll j=i;j<=n;j++){
            while(chk[id]) id--;
            if(j==p && id!=x) ok=0;
            if(j==q && id!=y) ok=0;
            id--;
        }
        return ok;
    }
    if(i==n) return 0;
    if(dp[i][v][d]!=-1) return dp[i][v][d];

    dp[i][v][d]=0;
    
    if(i==p){
        if(v>x) return 0;
        if(i==1 && x==n) return 0;
        chk[x]=1;
        ll temp=d;
        if(x==n) temp=1;
        dp[i][v][d]=solve(i+1,x,temp);
        chk[x]=0;
        return dp[i][v][d];
    }
    if(i==q){
        if(v>y) return 0;
        if(i==1 && y==n) return 0;
        chk[y]=1;
        ll temp=d;
        if(y==n) temp=1;
        dp[i][v][d]=solve(i+1,x,temp);
        chk[y]=0;
        return dp[i][v][d];
    }

    for(ll j=v+1;j<=n;j++){
        if(j==x || j==y) continue;
        ll temp=d;
        if(j==n) temp=1;
        chk[j]=1;
        dp[i][v][d]=(dp[i][v][d]+solve(i+1,j,temp))%mod;
        chk[j]=0;
    }

    return dp[i][v][d];

}

int main()
{

    ll t;
    scanf("%lli",&t);

    while(t--){

        memset(dp,-1,sizeof(dp));
        memset(chk,0,sizeof(chk));

        scanf("%lli %lli %lli %lli %lli",&n,&p,&q,&x,&y);

        ll ans=solve(1,0,0);
        printf("%lli\n",ans);
    }

    return 0;
}