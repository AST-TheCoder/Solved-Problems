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

        if(n==3){
            ll a,b,c;
            cin>>a>>b>>c;
            if((a+b+c)%2){
                cout<<"YES"<<endl;
                cout<<1<<" "<<2<<" "<<3<<endl;
            }
            else cout<<"NO"<<endl;
            continue;
        }
        vector<ll> p,q;
        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;

            if(x%2) p.pb(i+1);
            else q.pb(i+1);
        }
        if(p.size()==0){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        if(p.size()>=3){
            cout<<p[0]<<" "<<p[1]<<" "<<p[2]<<endl;
        }
        else{
            cout<<p[0]<<" "<<q[0]<<" "<<q[1]<<endl;
        }
    }

    return 0;
}