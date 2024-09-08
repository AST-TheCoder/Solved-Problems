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
    freopen("here_comes_santa_claus_input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll t,ii=0;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        double a[n+1];
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        double ans=(a[n-1]+a[n])/2-(a[1]+a[2])/2;
        if(n==5){
            ans=max((a[3]+a[5])/2-(a[1]+a[2])/2,(a[4]+a[5])/2-(a[1]+a[3])/2);
        }
        cout<<fixed<<setprecision(9)<<"Case #"<<++ii<<": "<<ans<<endl;
    }

    return 0;
}