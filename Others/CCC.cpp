#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define     fast            ios_base::sync_with_stdio(false);cin.tie(NULL)
#define     input           freopen('input.txt', 'r', stdin)
#define     output          freopen('output.txt', 'w', stdout)
#define     ll              long long int
#define     F               first
#define     S               second
#define     mem(a,v)        memset(a,v,sizeof(a))
#define     Max             1000000000000000007
#define     pb              push_back
#define     mp              make_pair
#define     PI              3.14159265358979323846 // acos(-1)  // 2.0 * acos(0.0)
//............................Lets Start.....................................//

ll cnt[200005], po[200005], mod = 1e9+7;

int main(){
	fast;
	po[0] = 1;
	ll v = 1;
	for(ll i = 1; i < 200005; i++) {
		v = (v*2)%mod;
		po[i] = v;
	}
	ll n,i,j,k,one=0, ans = 0;
	cin>>n;
	ll a[n+5];
	for(i=0; i<n; i++){
		cin>>a[i];
		if(a[i]==1){
			one++;
			continue;
		}
		vector <ll> p;
		for(j = 2; j * j <= a[i]; j++) {
			if(a[i] % j == 0) {
				p.push_back(j);
				while(a[i]%j == 0) {
					a[i] /= j;
				}
			}
		} 
		if(a[i] != 1) p.push_back(a[i]);
		ll sz = p.size(), c = i - one;
		//cout << sz << ' ';
		for(ll mask = 1; mask < (1<<sz); mask++) {
			ll ct = 0, val = 1;
			for(int k = 0; k < sz; k++) {
				if(mask & (1<<k)) {
					val *= p[k];
					ct++;
				}
			}
			if(ct % 2 == 1) c -= cnt[val];
			else c += cnt[val];
			cnt[val]++;
		}
		ll val = c;
		cout << val << ' ';
		ans += (po[c]-1+mod)%mod;
		ans %= mod;
	}
	ans += ((po[one]-1)*po[n-one])%mod;
	ans %= mod;

	cout << ans << endl;
}