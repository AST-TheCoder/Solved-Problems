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
    ll n,q;
    for(ll i=1;;i++){
        vector<double> xs,ys;
        cin>>n>>q;
        if(!n && !q) break;
        cout<<"Case"<<" "<<i<<":\n";
        for(ll i=0;i<n;i++){
            double temp_x,temp_y;
            cin>>temp_x>>temp_y;
            xs.pb(temp_x);
            ys.pb(temp_y);
        }
        for(ll i=0;i<=q;i++){
            int s=0,m=1;
            if(i) cin>>s>>m;
            double xq=0,yq=0,xy=0,sx=0,sy=0;
            ll n=xs.size();
            for(ll i=0;i<n;i++){
                sx+=xs[i]*(i==s?m:1);
                sy+=ys[i]*(i==s?m:1);
            }
            sx/=(n+m-1);
            sy/=(n+m-1);
            for(ll i=0;i<n;i++){
                xq+=(xs[i]-sx)*(xs[i]-sx)*(i==s?m:1);
                yq+=(ys[i]-sy)*(ys[i]-sy)*(i==s?m:1);
                xy+=(xs[i]-sx)*(ys[i]-sy)*(i==s?m:1);
            }
            double ans=(xq+yq)/2-sqrtl(((xq-yq)/2)*((xq-yq)/2)+xy*xy);
            cout<<fixed<<setprecision(5);
            if(i) cout<<i<<":"<<" ";
            cout<<ans/(n+m-1)<<'\n';
        }
    }

    return 0;
}