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

ll chk[200001];

int main()
{

    for(ll i=2;i<=200000;i++){
        if(!chk[i]){
            for(ll j=2*i;j<=200000;j+=i) chk[j]=1;
        }
    }

    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;
        if(n==1){
            cout<<1<<endl;
            continue;
        }
        if(n==2){
            cout<<"2 1"<<endl;
            continue;
        }
        ll a[n+1];
        for(ll i=1;i<=n;i++) a[i]=i;
        swap(a[2],a[1]);
        swap(a[3],a[n]);
        swap(a[2],a[(n+1)/2]);
        for(ll i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<endl;
    }

    return 0;
}