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
        ll n;
        cin>>n;

        vector<ll> p;
        ll a[n],m=1,s=0;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            if(a[i]>1) p.pb(i);
            if(Max/m<a[i]) m=Max;
            else m*=a[i];
            s=a[i];
        }

        if(m==Max){
            cout<<p[0]+1<<" "<<p[p.size()-1]+1<<endl;
            continue;
        }

        ll ans=s,l=0,r=0;
        for(ll i=0;i<p.size();i++){
            ll temp=s;
            m=a[p[i]];
            temp-=m;
            for(ll j=i+1;j<p.size();j++){
                temp-=a[p[j]];
                temp-=(p[j]-p[j-1]-1);
                m*=a[p[j]];
                if(temp+m>ans){
                    ans=temp+m;
                    l=p[i];
                    r=p[j];
                }
            }
        }
        cout<<l+1<<" "<<r+1<<endl;
    }

    return 0;
}