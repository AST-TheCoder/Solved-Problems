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

    read:
    while(t--){
        ll a,b,c,k;
        cin>>a>>b>>c>>k;

        ll p1=1,p2=1,q1=1,q2=1,r1=1,r2=1;
        for(ll i=1;i<=6;i++){
            if(i<=a) p1*=10;
            if(i<a) p2*=10;
            if(i<=b) q1*=10;
            if(i<b) q2*=10;
            if(i<=c) r1*=10;
            if(i<c) r2*=10;
        }
        p1--;
        q1--;
        r1--;
        for(ll i=p2;i<=p1;i++){
            ll x=max(q2,r2-i);
            ll y=min(q1,r1-i);
            ll d=y-x+1;
            if(d<=0) continue;
            if(k>d){
                k-=d;
                continue;
            }
            else{
                cout<<i<<" "<<"+"<<" "<<x+k-1<<" "<<"="<<" "<<i+x+k-1<<endl;
                goto read;
            }
        }
        cout<<-1<<endl;
    }

    return 0;
}