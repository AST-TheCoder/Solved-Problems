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

#define f(i, x, n) for(int i = x; i < (int)(n); ++i)

int const N = 200000;
char s[N + 1];
vector<pair<int, int> > an;

void no() { printf("-1\n"); exit(0); }

inline void ad(int tp, int i) { an.push_back(make_pair(tp, i)); }

int main(){
	scanf("%s", s);
	int n = strlen(s);
	string v;
	f(i, 0, n)if (s[i] == 'c'){ // first remove all 'c' characters
		if (v.empty())no(); // 'c' is first character in string
		if (v.back() == 'a'){ // "ac"
			ad(3, v.size() + 1);
			v += 'b';
			v += 'a';
		}else {
			if (v.size() == 1)no(); // "bc"
			if (v[v.size() - 2] == 'a'){ // "abc"
				ad(4, v.size() - 1);
				v.pop_back();
				v.pop_back();
			}else { // "bbc"
				ad(2, v.size() - 1);
				ad(3, v.size());
				ad(4, v.size() + 1);
			}
		}
	}else v += s[i];
	string g;
	f(i, 0, v.size())if (v[i] == 'b'){ // string contains only 'a' and 'b'
		if (g.empty())no();
		ad(2, g.size() + 1);
		ad(4, g.size());
		g.pop_back();
	}else g += v[i];
	f(i, 0, g.size()){ // remove any left 'a' characters
		ad(1, 1);
		ad(2, 2);
		ad(4, 1);
	}
	printf("%d\n", (int)an.size());
	f(i, 0, an.size())printf("%d %d\n", an[i].first, an[i].second);
}