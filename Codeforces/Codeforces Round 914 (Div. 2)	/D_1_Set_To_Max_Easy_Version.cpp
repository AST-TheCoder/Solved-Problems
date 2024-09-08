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
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        ll b[n];
        for(ll i=0;i<n;i++){
            cin>>b[i];
        }

        for(ll i=0;i<n;i++){
            if(a[i]>b[i]){
                cout<<"NO"<<endl;
                goto read;
            }
            if(a[i]==b[i]) continue;
            ll chk=0;
            for(ll j=i;j<n;j++){
                if(a[j]>b[i]) break;
                if(b[j]<b[i]) break;
                if(a[j]==b[i]){
                    chk=1;
                    break;
                }
            }
            for(ll j=i;j>=0;j--){
                if(a[j]>b[i]) break;
                if(b[j]<b[i]) break;
                if(a[j]==b[i]){
                    chk=1;
                    break;
                }
            }
            if(!chk){
                cout<<"NO"<<endl;
                goto read;
            }
        }
        cout<<"YES"<<endl;
    }

    return 0;
}