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
        if(m!=1) cout<<min(n+1,m)<<endl;
        else cout<<0<<endl;
        for(ll i=0,c=0;i<n;i++){
            for(ll j=0,k=c;j<m;j++){
                cout<<k<<" ";
                k++;
                k%=m;
            }
            cout<<endl;
            c++;
            c%=m;
            if(c==m-1) c=0;
        }
    }

    return 0;
}