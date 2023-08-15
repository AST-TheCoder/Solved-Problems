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

int n,m,a[250010];
ll f[2][2][2][10][10];

int main()
{
	while(scanf("%d%d", &n, &m)!=EOF){
		for(int i = 1; i <= n; ++i) scanf("%d", a + i);
		memset(f, 0x3f, sizeof f);
		if (n == 1)
			printf("%d\n", a[1]);
		else if (n == 2)
			printf("%d\n", min(a[1], a[2]));
		else
		{
			for (int i = 0; i < 2; ++i)
				for (int j = 0; j < 2; ++j)
					for (int k = 0; k < 2; ++k)
						for (int o = 0; o < 2; ++o)
						{
							if (i + j == 0 || i + j == 2) continue;
							ll &x = f[0][i][j][k][o];
							x = 0;
							if (i == 1) 
								x += a[1];	
							if (j == 1)
								x += a[2];
							if (k == 1) 
								x += i == 0 ? a[1] : a[2];
							if (o == 1)
								x -= i == 1 ? a[1] : a[2];
						}
			f[0][1][1][0][0] = a[1] + a[2];
			f[0][1][1][0][1] = min(a[1], a[2]);
			f[0][1][1][0][2] = 0;
			for (int i = 3; i <= n; ++i)
			{
				int now = i & 1, pre = (i & 1) ^ 1;
				for (int j = 0; j < 2; ++j)
					for (int k = 0; k < 2; ++k)
						for (int q = 0; q <= m; ++q)
							for (int w = 0; w <= m; ++w)
								f[now][j][k][q][w] = (ll)1e18;
				for (int j = 0; j < 2; ++j)
					for (int k = 0; k < 2; ++k)
						for (int o = 0; o < 2; ++o)
							for (int q = 0; q <= m; ++q) 
								for (int w = 0; w <= m; ++w) 
								{
									if (j + k + o == 0) continue;
									ll x = f[pre][j][k][q][w];
									if (o == 0) 
									{
										f[now][k][o][q][w] = min(f[now][k][o][q][w], x);
										if (q < m)
											f[now][k][o][q + 1][w] = min(f[now][k][o][q + 1][w], x + a[i]);
									}
									else
									{
										f[now][k][o][q][w] = min(f[now][k][o][q][w], x + a[i]);
										if (w < m)
											f[now][k][o][q][w + 1] = min(f[now][k][o][q][w + 1], x);
									}
								}
			}
			ll res = (ll)1e18;
			for (int i = 0; i < 2; ++i)
				for (int j = 0; j < 2; ++j)
					for (int k = 0; k <= m; ++k)
						if (i + j)
							res = min(res, f[n & 1][i][j][k][k]);
			printf("%lld\n", res);
		}
	}
	return 0;
}
