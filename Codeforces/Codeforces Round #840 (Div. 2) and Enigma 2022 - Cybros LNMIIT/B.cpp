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

    read:
    while(t--){

        ll n,k;
        cin>>n>>k;

        pair<ll,ll> a[n];
        for(ll i=0;i<n;i++) cin>>a[i].first;
        for(ll i=0;i<n;i++) cin>>a[i].second;

        sort(a,a+n);
        for(ll i=n-2;i>=0;i--) a[i].second=min(a[i].second,a[i+1].second);
        ll s=k;

        for(ll i=0;i<n;i++){
            if(s<a[i].first){
                k-=a[i].second;
                if(k<=0){
                    cout<<"NO"<<endl;
                    goto read;
                }
                s+=k;
                i--;
            }
        }

        cout<<"YES"<<endl;
    }

    return 0;
}