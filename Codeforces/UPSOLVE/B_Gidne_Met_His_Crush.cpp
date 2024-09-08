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

double p_val[1001],val[1001];

double power(double n, ll p){
    if(val[p]==n) return p_val[p];
    if(p==0) return 1.0;
    if(p%2){
        val[p]=n;
        return p_val[p]=n*power(n,p-1);
    }
    double x=power(n,p/2);
    val[p]=n;
    return p_val[p]=x*x;
}

int main()
{
    for(ll i=0;i<=1000;i++) val[i]=-1.0;

    ll t;
    scanf("%lli",&t);

    while(t--){
        ll n;
        double d;
        scanf("%lli %lf",&n,&d);

        double c[n],con=0.0;
        ll p[n],mx=0;

        for(ll i=0;i<n;i++){
            scanf("%lf %lli",&c[i],&p[i]);
            mx=max(mx,p[i]);
            if(!p[i]) con+=c[i];
        }

        if(con>d || (!mx && con!=d)){
            printf("-1\n");
            continue;
        }

        double l=0.0,r=1e9;

        while(r-l>=0.000000001){
            double m=(l+r)/2,temp=0.0;
            for(ll i=0;i<n;i++){
                temp+=c[i]*power(m,p[i]);
            }
            if(temp<=d) l=m;
            else r=m;
        }
        printf("%.11f\n",l);

    }

    return 0;
}