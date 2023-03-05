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
        ll l,r,mod=998244353;
        cin>>l>>r;

        ll d=(r/l);
        if(d==1){
            cout<<1<<" "<<(r-l+1)<<endl;
            continue;
        }
        ll p=log2(d);
        ll c=p;
        ll len=p+1;
        d=ceil(pow(2,p));
        p=(d/2)*3;


        ll x=r/d;
        ll y=r/p;
        if(y<l) y=l-1;

        //cout<<d<<" "<<x<<" "<<p<<" "<<y<<endl;
        ll ans=((x-y)+(y-l+1)*(c+1))%mod;
        cout<<len<<" "<<ans<<endl;
    }

    return 0;
}