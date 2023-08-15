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

    read:
    while(t--){
        ll n,k;
        scanf("%lli %lli",&n,&k);

        if(n%10==0){
            ll ans=n*k;
            printf("%lli\n",ans);
            continue;
        }

        if(n%10==5){
            printf("%lli\n",max(n*k,(n+5)*(k-1)));
            continue;
        }
        ll ans=n*k;
        while(n%10!=2 && k>0){
            n+=n%10;
            k--;
            ans=max(ans,n*k);
        }
        ll l=1,r=k/4+(k%4!=0);
        ll ok=0;
        while(l<=r){
            ll m1=(l+l+r)/3;
            ll d1=m1*20;
            for(ll i=max(1LL,4*m1-4);i<=min(4*m1+4,k);i++){
                ll x=(i/4)*20;
                if(i%4==3) x+=14;
                if(i%4==2) x+=6;
                if(i%4==1) x+=2;
                ans=max(ans,(n+x)*(k-i));
            }

            ll m2=(l+r+r)/3;
            ll d2=m2*20;
            for(ll i=max(1LL,4*m2-4);i<=min(4*m2+4,k);i++){
                ll x=(i/4)*20;
                if(i%4==3) x+=14;
                if(i%4==2) x+=6;
                if(i%4==1) x+=2;
                ans=max(ans,(n+x)*(k-i));
            }
            
            if((n+d1)*(k-4*m1)<=(n+d2)*(k-4*m2)){
                if(l==m1) l=m1+1;
                else l=m1;
            }
            else{
                if(r==m2) r=m2-1;
                else r=m2;
            }
        }
        
        printf("%lli\n",ans);
    }

    return 0;
}