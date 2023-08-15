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
        ll n,q;
        scanf("%lli %lli",&n,&q);

        char s[n+5];
        scanf("%s",s);

        ll cnt[n+1];
        memset(cnt,0,sizeof(cnt));
        for(ll i=0;i<n;i++){
            cnt[i+1]=cnt[i];
            if(s[i]=='1') cnt[i+1]++;
        }

        ll p1=79,p2=647;
        ll m1=1000001491,m2=1000003579;

        ll b1[n+1],b2[n+1];
        b1[0]=1;
        b2[0]=1;
        for(ll i=1;i<=n;i++){
            b1[i]=(b1[i-1]*p1)%m1;
            b2[i]=(b2[i-1]*p2)%m2;
        }

        ll v1[n+1],v2[n+1];
        v1[0]=v2[0]=0;
        for(ll i=1;i<=n;i++){
            v1[i]=v1[i-1];
            v2[i]=v2[i-1];
            if(s[i-1]=='1'){
                v1[i]=(v1[i]+b1[i])%m1;
                v2[i]=(v2[i]+b2[i])%m2;
            }
            b1[i]=(b1[i]+b1[i-1])%m1;
            b2[i]=(b2[i]+b2[i-1])%m2;
        }

        set<pair<ll,ll>> x;
        while(q--){
            ll l,r;
            scanf("%lli %lli",&l,&r);
            ll h1=v1[n],h2=v2[n];

            h1=(h1-v1[r]+v1[l-1]+m1)%m1;
            h2=(h2-v2[r]+v2[l-1]+m2)%m2;

            ll c=cnt[r]-cnt[l-1];
            h1=(h1+b1[r]-b1[r-c]+m1)%m1;
            h2=(h2+b2[r]-b2[r-c]+m2)%m2;

            x.insert({h1,h2});
        }
        printf("%lli\n",(ll)x.size());
    }

    return 0;
}