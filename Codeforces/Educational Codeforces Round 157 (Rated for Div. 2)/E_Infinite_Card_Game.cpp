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

ll n,m;
pair<ll,ll> a[300007],b[300007],p[300007],q[300007];
ll dp[2][1000007];

ll solve(ll id,ll pre){
    if(dp[id][pre]!=-2) return dp[id][pre];
    //cout<<id<<" "<<pre<<endl;
    dp[id][pre]=0;
    if(!id){
        pair<ll,ll> temp={pre,Max};
        ll idx=upper_bound(q,q+m,temp)-q;
        if(idx==m){
            return dp[id][pre]=1;            
        }
        return dp[id][pre]=solve(1,q[idx].second);
    }
    else{
        pair<ll,ll> temp={pre,Max};
        ll idx=upper_bound(p,p+n,temp)-p;
        if(idx==n){
            return dp[id][pre]=-1;            
        }
        return dp[id][pre]=solve(0,p[idx].second);
    }
}

int main()
{

    ll t;
    cin>>t;

    while(t--){
        cin>>n;

        vector<ll> xx;

        for(ll i=0;i<n;i++) cin>>a[i].first;
        for(ll i=0;i<n;i++){
            cin>>a[i].second;
            p[i]=a[i];
            dp[0][a[i].second]=-2;
            dp[1][a[i].second]=-2;
            xx.pb(a[i].second);
        }
        sort(p,p+n);
        for(ll i=n-2;i>=0;i--){
            p[i].second=max(p[i].second,p[i+1].second);
        }
        cin>>m;
        for(ll i=0;i<m;i++) cin>>b[i].first;
        for(ll i=0;i<m;i++){
            cin>>b[i].second;
            q[i]=b[i];
            dp[1][b[i].second]=-2;
            dp[0][b[i].second]=-2;
        }
        sort(q,q+m);
        for(ll i=m-2;i>=0;i--){
            q[i].second=max(q[i].second,q[i+1].second);
        }

        ll ax=0,ay=0,az=0;
        sort(all(xx),greater<ll>());
        for(ll i=0;i<n;i++){
            ll temp=solve(0,xx[i]);
            //cout<<temp<<endl;
            if(temp==1) ax++;
            if(temp==0) ay++;
            if(temp==-1) az++;
        }
        cout<<ax<<" "<<ay<<" "<<az<<endl;
    }

    return 0;
}