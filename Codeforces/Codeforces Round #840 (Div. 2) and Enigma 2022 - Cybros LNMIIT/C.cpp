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

        ll a[n];
        ll m=0;

        for(ll i=0;i<n;i++){
            cin>>a[i];
            m=max(m,a[i]);
        }

        if(n==2){
            cout<<max(a[0]+a[1],2*abs(a[1]-a[0]))<<endl;
            continue;
        }
        if(n>3 || m==a[0] || m==a[2]){
            cout<<n*m<<endl;
            continue;
        }

        ll s=a[0]+a[1]+a[2];
        s=max(s,3*abs(a[2]-a[0]));
        s=max(s,3*a[0]);
        s=max(s,3*a[2]);
        s=max(s,2*abs(a[0]-a[1])+a[2]);
        s=max(s,2*abs(a[2]-a[1])+a[0]);
        s=max(s,3*max(abs(a[0]-a[1]),abs(a[1]-a[2])));


        cout<<s<<endl;

    }

    return 0;
}