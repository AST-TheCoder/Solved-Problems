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

        ll l=2,r=1420000000;
        ll ans=2,v=1;
        while(l<=r){
            ll m=(l+r)/2;

            ll x;
            if(m%2){
                x=m-1;
                x/=2;
                x*=m;
            }
            else{
                x=m;
                x/=2;
                x*=(m-1);
            }
            //cout<<m<<" "<<x<<endl;
            if(x>n) r=m-1;
            else{
                ans=m;
                v=x;
                l=m+1;
            }
        }

        //cout<<"chk"<<" "<<v<<" "<<ans<<endl;
        ans+=n-v;
        cout<<ans<<endl;
    }

    return 0;
}