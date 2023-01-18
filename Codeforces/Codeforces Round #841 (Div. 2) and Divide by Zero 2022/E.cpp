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
        
        ll c[n+1];
        for(ll i=1;i<=n;i++) c[i]=n/i;
        for(ll i=n;i>=2;i--){
            c[i]=(c[i]*(c[i]-1))/2;
            for(ll j=i+i;j<=n;j+=i){
                c[i]-=c[j];
            }
        }

        
        ll ans=0;
        for(ll i=n;i>=2 && m;i--){
            c[i]/=(i-1);
            ll p=c[i]*(i-1);
            //cout<<i<<" "<<p<<" "<<m<<endl;
            if(p<=m){
                m-=p;
                ans+=i*c[i];
                continue;
            }
            c[i]=m;
            i++;
        }


        if(m) printf("-1\n");
        else printf("%lli\n",ans);

    }

    return 0;
}