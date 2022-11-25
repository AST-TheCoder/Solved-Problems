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
        if(n%x){
            cout<<-1<<endl;
            continue;
        }
        ll a[n+1];
        for(ll i=1;i<=n;i++) a[i]=i;
        a[1]=x;
        
        for(ll i=2*x;i<=n;i+=x){
            if(n%i) continue;
            swap(a[x],a[i]);
            x=i;
        }

        a[n]=1;

        for(ll i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<endl;
    }

    return 0;
}