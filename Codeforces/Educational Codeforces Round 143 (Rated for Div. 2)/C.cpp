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

        ll a[n+1],b[n+1],ans[n+1],c[n+1],cnt[n+1];
        for(ll i=0;i<n;i++){
            cin>>a[i];
            ans[i]=0;
            cnt[i]=0;
        }
        for(ll j=0;j<n;j++){
            cin>>b[j];
            c[j]=b[j];
            if(j) b[j]+=b[j-1];
        }

        for(ll i=0;i<n;i++){
            ll val=a[i];
            if(i) val+=b[i-1];
            ll id=upper_bound(b,b+n,val)-b;
            //cout<<val<<" "<<id<<endl;
            if(id){
                ans[id]+=val-b[id-1];
                cnt[id-1]++;
                if(i) cnt[i-1]--;
            }
            else{
                ans[i]+=a[i];
            }
        }
        //for(ll i=0;i<n;i++) cout<<cnt[i]<<" ";
        //cout<<endl;

        for(ll i=n-1;i>=0;i--){
            //cout<<i<<" "<<cnt[i]<<endl;
            ans[i]+=cnt[i]*c[i];
            if(i) cnt[i-1]+=cnt[i];
        }

        for(ll i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<"\n";

    }

    return 0;
}