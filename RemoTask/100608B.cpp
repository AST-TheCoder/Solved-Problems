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

const int N = 70;
int n, sum[N];
ll k, f[N];
char s[N];
int chk(int l1, int r1, int l2, int r2) {
	for (int i=l1,j=l2; i<=r1; ++i,++j) if (s[i]!='?'&&s[j]!='?'&&s[i]!=s[j]) return 0;
	return 1;
}
ll calc() {
	for (int i=1; i<=n; ++i) sum[i] = sum[i-1]+(s[i]=='?');
	for (int i=1; i<=n; ++i) {
		f[i] = 1ll<<sum[i];
		for (int j=1; j*2<=i; ++j) {
			if (chk(1,j,i-j+1,i)) f[i] -= f[j]<<sum[i-j]-sum[j];
		}
	}
	return f[n];
}
int main() {
	//freopen("borderless.in","r",stdin);
	//freopen("borderless.out","w",stdout);
	while (scanf("%d%lld", &n, &k), n||k) {
		for (int i=1; i<=n; ++i) s[i] = '?';
		for (int i=1; i<=n; ++i) {
			s[i] = 'a';
			ll w = calc();
			if (k>w) k -= w, s[i] = 'b';
		}
		s[n+1] = 0;
		puts(s+1);
	}
}