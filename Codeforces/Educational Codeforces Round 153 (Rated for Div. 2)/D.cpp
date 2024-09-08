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

ll dp[101][101][1251],n,x,y,p;
string s;

ll solve(ll i,ll xx,ll pp){
    if(pp>p) return Max;
    if(i==n){
        if(pp==p) return 0;
        else return Max;
    }

    if(dp[i][xx][pp]!=-1) return dp[i][xx][pp];

    ll yy=i-xx,ret=Max;
    if(yy<y){
        ret=min(ret,solve(i+1,xx,pp+xx)+(s[i]!='0'));
    }
    if(xx<x){
        ret=min(ret,solve(i+1,xx+1,pp)+(s[i]!='1'));
    }

    return dp[i][xx][pp]=ret;
}

int main()
{

    cin>>s;
    n=s.size();

    x=count(all(s),'1');
    y=count(all(s),'0');

    memset(dp,-1,sizeof(dp));

    p=(x*y)/2;

    ll ans=solve(0,0,0);
    cout<<ans/2<<endl;

    return 0;
}