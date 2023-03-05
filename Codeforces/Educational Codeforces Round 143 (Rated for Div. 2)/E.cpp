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

        ll a[n+5],csum[n+5];
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
        a[0]=a[n+1]=-Max;

        ll c[n+5];
        csum[0]=a[0];
        for(ll i=0;i<=n+1;i++){
            c[i]=a[i]+i;
            csum[i]=a[i]+csum[i-1];
        }

        ll next_s[n+5],prev_s[n+5];

        stack<pair<ll,ll>> s;
        s.push({a[n+1],n+1});

        for(ll i=n;i>=1;i--){
            while(s.top().first>c[i]) s.pop();
            next_s[i]=s.top().second;
            if(s.top().first==c[i]) s.pop();
            s.push({c[i],i});
        }
        for(ll i=n+1;i>=0;i--){
            c[i]=a[i]+(n-i+1);
        }

        while(!s.empty()) s.pop();
        s.push({a[0],0});
        for(ll i=1;i<=n;i++){
            while(s.top().first>c[i]) s.pop();
            prev_s[i]=s.top().second;
            if(s.top().first==c[i]) s.pop();
            s.push({c[i],i});
        }

        ll next_ans[n+5],prev_ans[n+5];
        next_ans[n+1]=0;
        for(ll i=n;i>=1;i--){
            ll id=next_s[i];
            ll temp=next_ans[id];
            ll ran=id-i-1;
            ll s=csum[id-1]-csum[i];
            if(ran>=a[i]){
                ran=a[i]-1;
                temp=0;
                s=csum[n]-csum[i];
            }
            ll x=(a[i]-ran-1)*ran;
            ran=(ran*(ran+1))/2;
            x+=ran;
            temp+=(s-x);
            next_ans[i]=temp;
            //cout<<i<<" "<<next_s[i]<<" "<<temp<<endl;
        }

        prev_ans[0]=0;
        for(ll i=1;i<=n;i++){
            ll id=prev_s[i];
            ll temp=prev_ans[id];
            ll ran=i-id-1;
            ll s=csum[i-1]-csum[id];
            if(ran>=a[i]){
                ran=a[i]-1;
                temp=0;
                s=csum[i-1]-csum[0];
            }
            ll x=(a[i]-ran-1)*ran;
            ran=(ran*(ran+1))/2;
            x+=ran;
            temp+=(s-x);
            prev_ans[i]=temp;
        }

        ll ans=Max;
        for(ll i=1;i<=n;i++){
            ans=min(ans,prev_ans[i]+next_ans[i]+a[i]);
        }
        cout<<ans<<endl;

    }

    return 0;
}