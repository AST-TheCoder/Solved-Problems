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
const int N=1e6+10;
struct Trie{
	int tot, root, ch[N][30], pre[N];
	Trie() {root = tot = 0;}
	void insert(char *str){
		int cur = root;
		for(int i = 0; str[i]; i++){
			int x = str[i]-'a';
			if(ch[cur][x] == 0) ch[cur][x] = ++tot, pre[tot] = cur;
			cur = ch[cur][x];
		}
	}
}tre1, tre2;

int n,m,a,b,ans,pos1[10],pos2[10];
char s[N];

void dfs(int id){
	if(id == n * m - 1) {ans++; return;} 
	id++; int row = id / m, col = id % m;
	for(int i=0;i<=25;i++){
		if(tre1.ch[pos1[col]][i] && tre2.ch[pos2[row]][i]){
			pos1[col] = tre1.ch[pos1[col]][i];
			pos2[row] = tre2.ch[pos2[row]][i];
			dfs(id);
			pos1[col] = tre1.pre[pos1[col]];
			pos2[row] = tre2.pre[pos2[row]];
		}
	}
}

int main()
{
	scanf("%d%d",&n,&a);
	scanf("%d%d",&m,&b);
	for(ll i=1;i<=a;i++) scanf("%s",s), tre1.insert(s);
	for(ll i=1;i<=b;i++) scanf("%s",s), tre2.insert(s);
	dfs(-1);
	printf("%d\n", ans);
	return 0;
}