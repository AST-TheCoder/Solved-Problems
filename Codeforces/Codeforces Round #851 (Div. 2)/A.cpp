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

        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];

        ll c=0;
        for(ll i=0;i<n;i++){
            if(a[i]==2) c++;
        }
        if(c%2){
            cout<<-1<<endl;
            continue;
        }
        c/=2;
        for(ll i=0;i<n-1;i++){
            if(a[i]==2) c--;
            if(!c){
                cout<<i+1<<endl;
                goto read;
            }
        }
    }

    return 0;
}