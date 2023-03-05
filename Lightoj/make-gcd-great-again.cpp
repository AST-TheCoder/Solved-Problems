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

    ll t,ii=0;
    scanf("%lli",&t);
    while(t--){
        ll n;
        scanf("%lli",&n);
        ll a[n];
        for(ll i=0;i<n;i++) scanf("%lli",&a[i]);

        sort(a,a+n);
        ll cost=Max,ans;
        for(ll gcd=2;gcd<=a[n-1];gcd++){
            ll temp=0;
            for(ll i=n-1;i>=0;i--){
                ll d=a[i]%gcd;
                if(!d) continue;
                if(d) d=gcd-d;
                temp+=(2*d*a[i]+d*d);
                if(temp>cost) break;
            }
            if(temp<=cost){
                cost=temp;
                ans=gcd;
            }
        }
        printf("Case %lli: %lli %lli\n",++ii,cost,ans);
    }

    return 0;
}