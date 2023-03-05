#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 1000000000000000001

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;

int main()
{

    ll t,ii=0;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        ll l=1,r=Max-1;
        ll ans=Max;
        while(l<=r){
            ll m=(l+r)/2;
            ll temp=m,c=0;

            while(temp){
                c+=temp/5;
                temp/=5;
            }

            if(c==n){
                ans=m;
                r=m-1;
            }
            else if(c>n) r=m-1;
            else l=m+1;
        }

        cout<<"Case "<<++ii<<": ";
        if(ans==Max) cout<<"impossible"<<endl;
        else cout<<ans<<endl;
    }

    return 0;
}