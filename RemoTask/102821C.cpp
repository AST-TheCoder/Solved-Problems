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
        ll n,m;
        scanf("%lli %lli",&n,&m);

        double a,b;
        scanf("%lf %lf",&a,&b);
        double x[n+1],c[n+1];
        c[0]=0.0;
        for(ll i=1;i<=n;i++){
            scanf("%lf",&x[i]);
        }

        sort(x+1,x+n+1);
        for(ll i=1;i<=n;i++) c[i]=c[i-1]+x[i];

        printf("Case %lli:\n",++ii);
        while(m--){
            double p,q;
            scanf("%lf %lf",&p,&q);
            double ans=0.0;

            double u=a*q+b;
            double v=b*p+q;
            double w=a*p-1.0;

            ll id1=lower_bound(x+1,x+n+1,-u/w)-x;
            ll id2=lower_bound(x+1,x+n+1,-v/w)-x;

            ans+=abs(c[id1-1]*w+(double)(id1-1)*u-((double)(n-id1+1)*u+w*(c[n]-c[id1-1])));
            ans+=abs(c[id2-1]*w+(double)(id2-1)*v-((double)(n-id2+1)*v+w*(c[n]-c[id2-1])));
            printf("%.10f\n",ans);
        }
    }

    return 0;
}