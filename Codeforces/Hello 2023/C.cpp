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
        ll n,m;
        cin>>n>>m;

        ll a[n+1];
        for(ll i=1;i<=n;i++) cin>>a[i];

        ll c[n+1],ans=0;
        c[0]=0;
        for(ll i=1;i<=n;i++) c[i]=c[i-1]+a[i];
        ll chk=c[m];

        priority_queue<ll> temp;
        for(ll i=m;i>=1;i--){
            while(c[i]<chk){
                ll val=temp.top();
                temp.pop();
                chk-=2*val;
                ans++;
            }
            if(a[i]>0) temp.push(a[i]);
        }
        while(!temp.empty()) temp.pop();
        chk=c[m];

        for(ll i=m+1;i<=n;i++){
            if(a[i]<0) temp.push(-a[i]);
            while(c[i]<chk){
                ll val=temp.top();
                temp.pop();
                chk-=2*val;
                ans++;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}