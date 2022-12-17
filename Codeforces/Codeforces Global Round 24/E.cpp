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
        for(ll i=0;i<n;i++) cin>>a[i].first>>a[i].second;
        if(k<=a[0].first){
            cout<<"YES"<<endl;
            continue;
        }
        if(k>a[0].first+a[0].second){
            cout<<"NO"<<endl;
            continue;
        }

        k=k-a[0].second;
        sort(a+1,a+n);
        for(ll i=n-1,x=k;i>=1;i--){
            if(x<=a[i].first){
                cout<<"YES"<<endl;
                goto read;
            }
            if(i-1 && x-a[i-1].second<=a[i-1].first){
                cout<<"YES"<<endl;
                goto read;
            }
            if(x-a[i].second<=a[i].first){
                if(i+1!=n && a[i+1].second==Max){
                    cout<<"YES"<<endl;
                    goto read;
                }
                x-=a[i].second;
            }
            else a[i].second=Max;
        }
        cout<<"NO"<<endl;
    }

    return 0;
}