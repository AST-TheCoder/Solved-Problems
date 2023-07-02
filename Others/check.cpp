#include <bits/stdc++.h>
using namespace std;
 
const long long M[3][9] = {
				{+1,+2,+2,    +1,+2,+2,   -1,-2,-2},
				{-2,-1,-2,    +2,+1,+2,   +2,+1,+2},
				{+2,+2,+3,    +2,+2,+3,   +2,+2,+3}
			}, mx = 207061, I = 0;
long long dp[mx];
int32_t main() {
    freopen("input.txt","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	queue<array<long long, 3>> q;
	q.push({3, 4, 5});
	while(!q.empty()) {
		auto u = q.front(); q.pop();
		if(u[0] > u[1]) swap(u[0], u[1]);
		dp[u[I]]++;
		array<array<long long, 3>, 3> v{};
		for(int j = 0; j < 9; j++) {
			for(int i = 0; i < 3; i++) {
				v[j/3][j%3] += u[i] * M[i][j];
			}
		}
		for(int i = 0; i < 3; i++) {
			if(v[i][I] < mx) {
				q.push(v[i]);
			}
		}
	}
	for(int i = mx - 1; i > 0; i--) {
		for(int j = i << 1; j < mx; j += i) {
			dp[j] += dp[i];
		}
	}
	for(int i = 1; i < mx; i++) dp[i] += dp[i - 1];
	int t=100000;
    while(t--) {
		int n=100000-t; cout << dp[n] << '\n';
	}
	return 0;
}
