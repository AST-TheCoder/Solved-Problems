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

ll sod(ll n){
    ll s=0;
    while(n){
        s+=(n%10);
        n/=10;
    }
    return s;
}

int main()
{

    ll t;
    scanf("%lli",&t);

    while(t--){
        ll n;
        scanf("%lli",&n);

        ll a=n/2,b=n-a,temp=9,p=1;

        ll chk=0;
        while(abs(sod(a)-sod(b))>1){
            ll x=abs(sod(a)-sod(b));
            if(x>9){
                a-=temp*p;
                b+=temp*p;
                p*=10;
                continue;
            }
            x/=2;
            a-=x*p;
            b+=x*p;
        }
        //cout<<chk<<endl;
        printf("%lli %lli\n",a,b);
    }

    return 0;
}