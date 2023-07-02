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
        ll n,m;
        cin>>n>>m;

        priority_queue<ll> p,q;
        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;
            p.push(x);
        }
        for(ll i=0;i<m;i++){
            ll x;
            cin>>x;
            q.push(x);
        }

        while(p.size() && q.size()){
            ll x=p.top(),y=q.top();
            p.pop();
            q.pop();
            ll a=x-y,b=y-x;
            if(a>0) p.push(a);
            if(b>0) q.push(b);
        }

        if(p.size()) cout<<"Tsondu"<<endl;
        else if(q.size()) cout<<"Tenzing"<<endl;
        else cout<<"Draw"<<endl;
    }

    return 0;
}