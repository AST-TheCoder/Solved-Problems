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
        ll n;
        cin>>n;

        ll a[n],b[n];
        for(ll i=0;i<n;i++) cin>>a[i];
        for(ll i=0;i<n;i++) cin>>b[i];

        ll p=-1,q=n;
        for(ll i=0;i<n;i++){
            if(a[i]!=b[i]){
                if(p==-1) p=i;
                q=i;
            }
        }
        if(p==-1){
            ll m=1;
            p=0,q=0;
            for(ll i=1,j=0;i<n;i++){
                if(a[i]<a[i-1] || i+1==n){
                    if(i-j>m){
                        m=i-j;
                        p=j,q=i-1;
                    }
                    j=i;
                }
            }
            cout<<p+1<<" "<<q+1<<endl;
            continue;
        }

        while(p && b[p-1]<=b[p]) p--;
        while(q<n-1 && b[q+1]>=b[q]) q++;
        cout<<p+1<<" "<<q+1<<endl;
    }

    return 0;
}