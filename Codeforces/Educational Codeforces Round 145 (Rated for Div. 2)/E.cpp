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

    ll t=1;
    //cin>>t;

    while(t--){

        ll n,a,b;
        cin>>n>>a>>b;

        ll v[n];
        for(ll i=0;i<n;i++) cin>>v[i];
        //cout<<"ok"<<endl;
        ll ans[a+1][b+1];
        for(ll j=0;j<=b;j++){
            ll temp[n];
            temp[0]=v[0];
            if(v[0]<-j) temp[0]=-j;
            for(ll i=1;i<n;i++){
                temp[i]=v[i]+temp[i-1];
                if(temp[i]<-j) temp[i]=-j;
            }
            ll val=temp[n-1];
            for(ll i=a;i>=0;i--){
                if(i+j>a) ans[i][j]=ans[i][j-1];
                else{
                    ans[i][j]=max(0LL,i-val);
                    if(ans[i][j]>a) ans[i][j]=a;
                }
                ll sum=i+j;
                if(ans[i][j]+b<sum) ans[i][j]=sum-b;
            }
        }
        for(ll i=0;i<=a;i++){
            for(ll j=0;j<=b;j++) cout<<ans[i][j]<<" ";
            cout<<endl;
        }
    }

    return 0;
}