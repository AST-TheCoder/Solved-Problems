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
        ll n,x;
        cin>>n>>x;

        ll ans=0;
        for(ll i=0,ok=0;i<n;i++){
            ll p;
            cin>>p;
            if(!ok && (x|p)==x) ans|=p;
            else ok=1;
        }
        for(ll i=0,ok=0;i<n;i++){
            ll p;
            cin>>p;
            if(!ok && (x|p)==x) ans|=p;
            else ok=1;
        }
        for(ll i=0,ok=0;i<n;i++){
            ll p;
            cin>>p;
            if(!ok && (x|p)==x) ans|=p;
            else ok=1;
        }
        //cout<<ans<<endl;
        if(ans==x) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}