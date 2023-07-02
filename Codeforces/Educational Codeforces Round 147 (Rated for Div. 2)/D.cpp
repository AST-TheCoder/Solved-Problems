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
        ll n,k;
        cin>>n>>k;
        ll l[n],r[n];
        for(ll i=0;i<n;i++) cin>>l[i];
        for(ll i=0;i<n;i++) cin>>r[i];

        min_heap<ll> q;
        ll ans=Max,temp=0,pos=0;
        for(ll i=0;i<n;i++){
            temp+=l[i]-pos;
            pos=l[i];
            if(r[i]-l[i]+1<k){
                temp+=r[i]-pos;
                pos=r[i];
                k-=(r[i]-l[i]+1);
                temp+=2;
                q.push(r[i]-l[i]+1);
                //cout<<i<<" "<<temp<<" "<<k<<endl;
                continue;
            }
            //cout<<i<<" "<<temp<<" "<<k<<endl;
            ans=min(ans,temp+k+1);
            if(!q.empty()){
                ll x=q.top();
                q.pop();
                k+=x;
                i--;
                temp-=2;
            }
            //cout<<i<<" "<<temp<<" "<<k<<endl;
        }
        if(ans==Max) ans=-1;
        cout<<ans<<endl;
    }

    return 0;
}