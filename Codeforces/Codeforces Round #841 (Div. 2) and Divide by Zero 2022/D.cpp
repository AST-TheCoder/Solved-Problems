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
    scanf("%lli",&t);

    while(t--){
        ll n,m;
        scanf("%lli %lli",&n,&m);


        ll a[n][m];
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++) scanf("%lli",&a[i][j]);
        }

        ll l=1,r=n,ans=1;

        while(l<=r){

            ll v=(l+r)/2;

            ll temp[n][m];
            for(ll i=0;i<n;i++){
                for(ll j=0;j<m;j++) temp[i][j]=-1;
            }

            for(ll i=0;i<n;i++){
                deque<pair<ll,ll>> q;
                for(ll j=0;j<m;j++){
                    
                    while(!q.empty() && a[i][j]<q.back().first) q.pop_back();
                    q.push_back({a[i][j],j});

                    if(j+1>=v){
                        temp[i][j-v+1]=q.front().first;
                        if(q.front().second==j-v+1) q.pop_front();
                    }
                }
            }

            ll f=0;
            for(ll j=0;j<m;j++){
                deque<pair<ll,ll>> q;
                for(ll i=0;i<n;i++){
                    while(!q.empty() && temp[i][j]<q.back().first) q.pop_back();
                    q.push_back({temp[i][j],i});

                    if(i+1>=v){
                        ll val=q.front().first;
                        if(q.front().second==i-v+1) q.pop_front();
                        if(val>=v){
                            f=1;
                            break;
                        }
                    }
                }
                if(f) break;
            }

            if(f){
                ans=v;
                l=v+1;
            }
            else r=v-1;

        }
        printf("%lli\n",ans);
    }

    return 0;
}