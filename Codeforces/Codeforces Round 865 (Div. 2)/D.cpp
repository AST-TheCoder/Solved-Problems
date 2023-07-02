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

        ll x;
        cout<<"+ "<<n+1<<endl;
        cin>>x;
        if(x==-2) return 0;

        cout<<"+ "<<n<<endl;
        cin>>x;
        if(x==-2) return 0;

        ll id=0,mx=0;
        for(ll i=2;i<=n;i++){
            cout<<"? "<<1<<" "<<i<<endl;
            cin>>x;
            if(x==-2) return 0;
            if(x>mx){
                mx=x;
                id=i;
            }
        }

        ll d[n+1];
        for(ll i=1;i<=n;i++){
            if(i==id){
                d[id]=0;
                continue;
            }
            cout<<"? "<<id<<" "<<i<<endl;
            cin>>x;
            if(x==-2) return 0;
            d[i]=x;
        }
        cout<<"!";
        for(ll i=1;i<=n;i++){
            ll dis=(d[i]+1)/2;
            if(d[i]%2) cout<<" "<<dis;
            else cout<<" "<<n-dis;
        }
        for(ll i=1;i<=n;i++){
            ll dis=(d[i]+1)/2;
            if(n%2){
                ll val=(n+1)/2;
                if(d[i]%2) cout<<" "<<val-dis;
                else cout<<" "<<val+dis;
            }
            else{
                ll val=n/2;
                if(d[i]%2) cout<<" "<<val+dis;
                else cout<<" "<<val-dis;
            }
        }
        cout<<endl;
        cin>>x;
        if(x==-2) return 0;
    }

    return 0;
}