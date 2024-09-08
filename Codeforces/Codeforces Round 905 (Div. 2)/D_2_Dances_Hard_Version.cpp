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
        ll n,m,mx=0;
        cin>>n>>m;
        ll a[n],b[n];
        a[0]=0;
        for(ll i=1;i<n;i++) cin>>a[i];
        for(ll i=0;i<n;i++) cin>>b[i];

        multiset<ll> x;
        for(ll i=0;i<n;i++){
            x.insert(b[i]);
            mx=max(mx,b[i]);
        }
        ll ans=0,cnt=0;
        sort(a,a+n);
        for(ll i=0;i<n;i++){
            multiset<ll>::iterator it=x.upper_bound(a[i]);
            if(it==x.end()) break;
            x.erase(it);
            cnt++;
        }
        
        sort(b,b+n,greater<ll>());
        vector<ll> v,u;
        for(ll i=0;i<cnt;i++){
            v.pb(b[i]);
            u.pb(a[i]);
        }

        if(cnt!=n) u.pb(a[cnt]);
        else u.pb(Max);

        ll temp=n-cnt,d=0;

        for(ll i=0;i<cnt;i++){
            d=min(u[i+1],v[v.size()-1]-1);
            if(d>m) d=m;
            ans+=(d-u[i])*temp;
            if(d==m) break;
            //cout<<d<<" "<<u[i]<<" "<<temp<<endl;
            v.pop_back();
            if(d==u[i+1]){
                continue;
            }
            temp++;
            cnt--;
            u.pop_back();
            u[i]=d;
            i--;
        }
        ans+=(m-d)*temp;

        cout<<ans<<endl;
    }

    return 0;
}