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
        ll a=0,b=0,c=0,d=0;
        for(ll i=1,j=0;n;i+=2,j^=1){
            ll s=i+i-1;
            if(s>n) s=n;
            n-=s;
            if(!j){
                a+=(s+1)/2;
                b+=s/2;
            }
            else{
                c+=s/2;
                d+=(s+1)/2;
            }
        }
        cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    }

    return 0;
}