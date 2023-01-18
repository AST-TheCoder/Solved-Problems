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

    while(t--){
        ll w,d,h;
        cin>>w>>d>>h;
        ll a,b,p,q;
        cin>>a>>b>>p>>q;

        ll x=h+abs(a-p);
        x+=min(b+q,2*d-b-q);

        ll y=h+abs(b-q);
        y+=min(a+p,2*w-a-p);

        cout<<min(x,y)<<endl;
    }

    return 0;
}