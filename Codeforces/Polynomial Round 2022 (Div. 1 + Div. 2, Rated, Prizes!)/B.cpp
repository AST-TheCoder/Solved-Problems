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
        ll n,m,k;
        cin>>n>>m>>k;

        ll a[m+1];
        for(ll i=1;i<=m;i++){
            cin>>a[i];
        }

        if(k>m){
            cout<<"NO"<<endl;
            continue;
        }
        sort(a+1,a+m+1,greater<ll>());

        ll chk=n%k;
        for(ll i=1;i<=chk;i++){
            a[i]--;
            n--;
        }
        
        sort(a+1,a+m+1,greater<ll>());

        for(ll i=1;i<=m;i++){
            ll d=(a[i]-1)*k+1;
            if(d>n){
                cout<<"NO"<<endl;
                goto read;
            }
        }

        cout<<"YES"<<endl;
    }

    return 0;
}