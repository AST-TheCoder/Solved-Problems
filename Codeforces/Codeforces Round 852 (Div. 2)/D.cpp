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

    ll a[n+1],b[n+1];
    for(ll i=1;i<=n;i++){
        ll x;
        cin>>x;
        a[x]=i;
    }
    for(ll i=1;i<=n;i++){
        ll x;
        cin>>x;
        b[x]=i;
    }

    ll p=min(a[1],b[1]),q=max(a[1],b[1]);
    ll ans=(p*(p-1))/2+((n-q)*(n-q+1))/2+((q-p-1)*(q-p))/2;
    
    for(ll i=1;i<=n;i++){
        p=min(p,min(a[i],b[i]));
        q=max(q,max(a[i],b[i]));
        if(i==n){
            ans++;
            break;
        }
        if((a[i+1]>=p && a[i+1]<=q) || (b[i+1]>=p && b[i+1]<=q)){
            continue;
        }
        ll x=1,y=n;
        if(a[i+1]<p) x=max(x,a[i+1]+1);
        if(b[i+1]<p) x=max(x,b[i+1]+1);

        if(a[i+1]>q) y=min(y,a[i+1]-1);
        if(b[i+1]>q) y=min(y,b[i+1]-1);
        ans+=(p-x+1)*(y-q+1);
    }
    cout<<ans<<endl;


    return 0;
}