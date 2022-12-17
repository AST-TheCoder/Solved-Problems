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

ll sc[3166];
vector<ll> p;

int main()
{

    for(ll i=2;i<3166;i++){
        if(!sc[i]){
            p.pb(i);
            for(ll j=i;j<3166;j+=i) sc[j]=1;
        }
    }

    ll t;
    scanf("%lli",&t);
    while(t--){
        ll a,b;
        scanf("%lli %lli",&a,&b);
        if(__gcd(a,b)!=1){
            printf("0\n");
            continue;
        }
        ll d=abs(a-b);
        if(d==1){
            printf("-1\n");
            continue;
        }

        ll ans=d-(a%d);

        for(ll i=0;i<p.size() && p[i]*p[i]<=d;i++){
            if(d%p[i]==0){
                ans=min(ans,p[i]-(a%p[i]));
                while(d%p[i]==0) d/=p[i];
            }
        }
        if(d!=1) ans=min(ans,d-(a%d));
        printf("%lli\n",ans);
    }

    return 0;
}