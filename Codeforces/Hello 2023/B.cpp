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

        for(ll i=-1000;i<=1000;i++){
            for(ll j=-1000;j<=1000;j++){
                if(!i || !j) continue;
                ll s=(n/2)*(i+j);
                if(n%2) s+=i;
                if(i+j!=s) continue;
                cout<<"YES"<<endl;
                for(ll k=1;k<=n;k++){
                    if(k%2) cout<<i<<" ";
                    else cout<<j<<" ";
                }
                cout<<endl;
                goto read;
            }
        }
        cout<<"NO"<<endl;
    }

    return 0;
}