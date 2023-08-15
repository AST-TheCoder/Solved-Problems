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
        ll n,m,k;
        cin>>n>>m>>k;

        ll x,y;
        cin>>x>>y;
        ll a[k],b[k];
        for(ll i=0;i<k;i++) cin>>a[i]>>b[i];
        for(ll i=0;i<k;i++){
            ll p=a[i],q=b[i];

            ll d=abs(p-x)+abs(q-y);
            if(d%2==0){
                cout<<"NO"<<"\n";
                goto read;
            }
        }
        cout<<"YES"<<endl;
    }

    return 0;
}