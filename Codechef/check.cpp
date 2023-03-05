#include<bits/stdc++.h>
using namespace std;
const int MAX = 105;
int grundy[MAX];
int vis[MAX + 5];
int cas;
void solve(){
	cout << "Case "<<++cas<<": ";
	int n;
	cin >> n;
	string s[3];
	cin >> s[0] >> s[1] >> s[2];
	int ans = 0;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(s[1][i] == 'X' || (s[0][i] == 'X' && s[2][i] == 'X')){
			ans ^= grundy[cnt];
			cnt = 0;
		}
		else if(cnt > 0 && ((s[0][i] == 'X' && s[2][i - 1] == 'X') || (s[0][i - 1] == 'X' && s[2][i] == 'X'))){
			ans ^= grundy[cnt];
			cnt = 1;
		}
		else cnt++;
	}
	ans ^= grundy[cnt];
	cout << (ans ? "Jhinuk" : "Grandma") << '\n';

}

int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	grundy[0] = grundy[1] = 0;
	for(int i = 2; i < MAX; i++){
		memset(vis, 0, sizeof vis);
		for(int j = 2; j <= i; j++){
			int cur = grundy[j - 2] ^ grundy[i - j];
			vis[cur] = 1;
		}
		while(vis[grundy[i]]) grundy[i]++;
	}
    for(int i=100;i>=0;i--) cout<<i<<" "<<grundy[i]<<endl;
	cin >> t;
	while(t--) solve();
}