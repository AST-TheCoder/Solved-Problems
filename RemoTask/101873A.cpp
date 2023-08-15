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

int main(){
	ll n;
	cin>>n;
	vector<double> p[n+1];
	p[n].pb(1005.1);
	p[n].pb(-1003);
	p[n].pb(2);
	for(ll i=0;i<n;i++){
        for(ll j=0;j<3;j++){
            double x;
            cin>>x;
            p[i].pb(x);
        }
    }
	sort(p,p+n+1);
	vector<pair<double,double>> a,b;
	
	a.pb({1005,1005});
	a.pb({-1005,1005});
	a.pb({-1005,-1005});
	
	b.pb({1005.2,1005.2});
	b.pb({-1005.2,1005.2});
	b.pb({-1005.2,-1005.2});
	
	double x=-1e5;
	for(ll i=0;i<=n;i++){
		if(p[i][0]!=x){
			if(x>=-1e3){
				a.pb({x-0.1,1003.2});
				a.pb({x+0.6,1003.2});
				a.pb({x+0.6,-1005});
				
				b.pb({x+0.1,1003});
				b.pb({x+0.4,1003});
				b.pb({x+0.4,-1005.2});
			}
			a.pb({p[i][0]-0.1,-1005});
			b.pb({p[i][0]+0.1,-1005.2});
			x=p[i][0];
		}
		a.pb({p[i][0]+(p[i][2]-2)*0.2-0.1,p[i][1]});
		b.pb({p[i][0]+(p[i][2]-2)*0.2+0.1,p[i][1]});
	}
	
	cout<<a.size()-1<<endl;
	for(ll i=0;(ll)i<a.size()-1;i++) cout<<a[i].first<<" "<<a[i].second<<endl;	
	cout<<b.size()-1<<endl;
	for(ll i=0;(ll)i<b.size()-1;i++) cout<<b[i].first<<" "<<b[i].second<<endl;

    return 0;
}