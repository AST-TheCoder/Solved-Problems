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
        ll x[3],y[3];
        for(ll i=0;i<3;i++){
            cin>>x[i]>>y[i];
        }

        if((x[0]!=x[1] && x[1]!=x[2] && x[2]!=x[0]) || (y[0]!=y[1] && y[1]!=y[2] && y[2]!=y[0])) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}