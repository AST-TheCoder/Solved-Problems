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

    ll n,y;
    scanf("%lli %lli",&n,&y);

    map<ll,ll> m;
    for(ll i=0;i<n;i++){
        ll x,l,r;
        scanf("%lli %lli %lli",&x,&l,&r);
        m[x+y*l]++;
        m[x+y*r+1]--;
    }

    ll mx=0,temp=0,ans=0;
    for(auto it=m.begin();it!=prev(m.end());it++){
        temp+=it->second;
        if(temp>mx){
            mx=temp;
            ans=0;
        }
        if(temp==mx) ans+=next(it)->first-it->first;
    }

    printf("%lli %lli\n",mx,ans);

    return 0;
}