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

        ll a[n+1];
        priority_queue<pair<ll,ll>> q;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            if(i!=1){
                q.push({a[i]-i*k,a[i]});
            }
        }
        ll v=a[1];
        while(!q.empty()){
            if(-q.top().first>v){
                cout<<"NO"<<endl;
                goto read;
            }
            v+=q.top().second;
            q.pop();
        }
        cout<<"YES"<<endl;
    }

    return 0;
}