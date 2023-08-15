#include <bits/stdc++.h>
#define inf (0x7f7f7f7f)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
typedef long long ll;
using namespace std;
template <class T>
inline void read(T &x){
	int ch = 0, f = 0; x = 0;
	for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = 1;
	for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
	if(f) x = -x;
}
#define fi first
#define se second
const int N = 600005;
vector<pair<int, int> > e[N];
unordered_map<int, int> mp[N];
int s[N], t[N], n, m;
long double pre[N];
namespace SA{
	int s[N];
	int sa[N], rk[N<<1], t[N], ork[N<<1], id[N], f[N][21], Log[N],
	height[N], n, m;
	inline void suffix_sort(){
		for(int i = 1; i <= n; i++) ++t[rk[i]=s[i]];
		for(int i = 1; i <= m; i++) t[i] += t[i-1];
		for(int i = n; i >= 1; i--) sa[t[rk[i]]--] = i;
		for(int w = 1, p = 0, i; p < n; w <<= 1, m = p){
			for(p = 0, i = n; i > n - w; i--) id[++p] = i;
			for(i = 1; i <= n; i++)
				if(sa[i] > w) id[++p] = sa[i] - w;
			for(i = 0; i <= m; i++) t[i] = 0;
			for(i = 1; i <= n; i++) ++t[rk[id[i]]];
			for(i = 1; i <= m; i++) t[i] += t[i-1];
			for(i = n; i >= 1; i--) sa[t[rk[id[i]]]--] = id[i];
			for(i = 1; i <= n; i++) ork[i] = rk[i];
			for(p = 0, i = 1; i <= n; i++){
				rk[sa[i]] = (ork[sa[i]] == ork[sa[i-1]] &&
				ork[sa[i]+w] == ork[sa[i-1]+w]) ? p : ++p;
			}
		}
		for(int i = 1, p = 0; i <= n; i++){
			if(rk[i] == 1) continue;
			p = p ? p - 1 : 0;
			int j = sa[rk[i]-1];
			while(max(i, j) + p <= n && s[i+p] == s[j+p]) p++;
			height[rk[i]] = p;
		}
	}
	inline int getlcp(int x, int y){
		if(x > n || y > n) return 0;
		if(x == y) return n - x + 1;
		int a = rk[x], b = rk[y];
		if(a > b) swap(a, b);
		a++;
		int g = Log[b-a+1];
		return min(f[a][g], f[b-(1<<g)+1][g]);
	}
	inline void init(int *str, int len){
		n = len, m = n;
		for(int i = 1; i <= n; i++) s[i] = str[i];
		suffix_sort();
		for(int i = 1; i <= n; i++) f[i][0] = height[i];
		for(int i = 2; i <= n; i++) Log[i] = Log[i>>1] + 1;
		for(int j = 1; j <= 20; j++)
			for(int i = 1; i + (1 << j) - 1 <= n; i++)
				f[i][j] = min(f[i][j-1], f[i+(1<<(j-1))][j-1]);

	}
	inline void clear(){
		for(int i = 0; i <= max(n, m); i++)
			sa[i] = rk[i] = t[i] = ork[i] = 
			id[i] = height[i] = s[i] = 0;
	}
}
inline void solve(){
	SA::clear();
	read(n), read(m);
	for(int i = 1, l, r; i <= n; i++){
		read(l), read(r);
		e[i].resize(r - l + 1);
		mp[i].clear();
		for(int j = l, x; j <= r; j++){
			read(x);
			e[i][j-l] = make_pair(x, j);
			mp[i][j] = x;
		}
		sort(e[i].begin(), e[i].end(), greater<pair<int, int> >());
		s[i] = e[i][0].se;
		pre[i] = log((long double) e[i][0].fi / 1e9);
	}
	s[n+1] = n + 1;
	for(int i = 1, x; i <= m; i++)
		read(x), s[n+i+1] = t[i] = x;
	for(int i = 1; i <= n; i++) pre[i] += pre[i-1];
	SA::init(s, n + m + 1);
	for(int i = 1; i <= n - m + 1; i++){
		int p = i, len = 0;
		long double prob = 1.0;
		while(p - i <= m && prob > 1e-9){
			int lcp = SA::getlcp(p, (n + 1) + (len + 1));
			int q = p + lcp - 1;
			if(q >= p) prob *= exp(pre[q] - pre[p-1]);
			if(q - i + 1 == m) break;
			prob *= (long double) mp[q+1][t[(len+1)+lcp]] / 1e9;
			len += lcp + 1;
			p = q + 2;
		}
		printf("%.12Lf\n", prob);
	}
}
int main(){
	int T; read(T);
	for(int i = 1; i <= T; i++){
		printf("Case #%d:\n", i);
		solve();
	}
	return 0;	
}