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

    ll n,k;
    cin>>n>>k;

    pair<double,double> a[n];
    for(ll i=0;i<n;i++) cin>>a[i].first;
    for(ll i=0;i<n;i++) cin>>a[i].second;

    double ans=0.0;
    for(ll i=0;i<n;i++) ans+=a[i].first*a[i].second;

    sort(a,a+n);
    ll s=0;
    double x=0.0;
    while(k--){
        double c=0.0;
        for(ll i=s;i<n;i++){
            if(a[i].first<ans){
                s=i+1;
                x+=a[i].second;
            }
            else c+=a[i].first*a[i].second;
        }
        ans=ans*x+c;
    }
    cout<<fixed<<setprecision(8)<<ans<<endl;

    return 0;
}