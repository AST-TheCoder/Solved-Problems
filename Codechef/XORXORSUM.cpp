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

    ll n;
    cin>>n;

    ll a[n],ans=0;
    for(ll i=0;i<n;i++) cin>>a[i];

    sort(a,a+n);
    for(ll i=0;i<n;i++){
        ll val=0;
        for(ll j=0,p=1,x=0,s=0;j<=62;j++,p*=2,s/=2){
            if(a[i]&(1LL<<j)) s++;
            if(!x){
                if(s%2){
                    s++;
                    val+=p;
                    if(a[i]&p) x=0;
                    else x=1;
                }
                else{
                    if(a[i]&p) x=1;
                    else x=0;
                }
            }
            else{
                if(s%2){
                    if(a[i]&p) x=1;
                    else x=0;
                }
                else{
                    s++;
                    val+=p;
                    if(a[i]&p) x=0;
                    else x=1;
                }
            }
        }
        ll id1=lower_bound(a,a+n,val)-a;
        ll id2=upper_bound(a,a+n,val)-a;
        ans+=(id2-id1);
        //cout<<a[i]<<" "<<val<<endl;
    }

    cout<<ans/2<<endl;

    return 0;
}