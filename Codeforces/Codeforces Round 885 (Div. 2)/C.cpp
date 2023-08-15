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

        ll a[n],b[n];
        vector<ll> x;
        for(ll i=0;i<n;i++) cin>>a[i];
        for(ll i=0;i<n;i++) cin>>b[i];

        for(ll i=0;i<n;i++){
            if(!a[i] && !b[i]) continue;
            ll op=0;
            while(a[i]){
                if(!b[i]){
                    op++;
                    break;
                }
                if(a[i]<2*b[i]){
                    op++;
                    ll temp=abs(a[i]-b[i]);
                    a[i]=b[i];
                    b[i]=temp;
                    continue;
                }
                ll d=a[i]-b[i];
                d=(d/(2*b[i]))+(d%(2*b[i])!=0);
                a[i]-=2*d*b[i];
                op+=3*d;
            }
            x.pb(op);
        }
        sort(all(x));
        for(ll i=1;i<x.size();i++){
            if((x[i]-x[0])%3){
                cout<<"NO"<<"\n";
                goto read;
            }
        }
        cout<<"YES"<<"\n";
    }

    return 0;
}