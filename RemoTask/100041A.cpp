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

ll dp[101][5001],id[101][5001];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll n,k;
    cin>>n>>k;

    vector<pair<ll,ll>> x[k+1];
    ll s[k+1];
    memset(s,0,sizeof(s));

    for(ll i=1;i<=n;i++){
        ll l,c;
        cin>>l>>c;
        x[c].pb({l,i});
        s[c]+=l;
    }

    if(s[1]==1 || x[1].size()<2){
        cout<<"NO"<<endl;
        return 0;
    }
    for(ll i=2;i<=k;i++){
        if(s[i]!=s[i-1] || x[i].size()<2){
            cout<<"NO"<<endl;
            return 0;
        }
    }

    for(ll i=1;i<=k;i++){
        dp[i][0]=1;
        for(ll j=0;j<x[i].size();j++){
            for(ll v=s[1];v-x[i][j].first>=0;v--){
                if(dp[i][v]) continue;
                dp[i][v]=dp[i][v-x[i][j].first];
                if(dp[i][v]) id[i][v]=j;
            }
        }
    }

    ll p=0;
    for(ll i=1;i<=s[1]/2;i++){
        ll ok=0;
        for(ll j=1;j<=k;j++){
            if(!dp[j][i]){
                ok=1;
            }
        }
        if(!ok){
            p=i;
            break;
        }
    }
    if(!p){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(ll i=1;i<=k;i++){
        for(ll j=p;j>0;){
            cout<<x[i][id[i][j]].second<<" ";
            j-=x[i][id[i][j]].first;
        }
    }
    cout<<endl;

    return 0;
}