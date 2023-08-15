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

const int N = 2e6 + 1, M = 22;

int MOD=1000000007;
int dp[M][N];
int INV[M];


int binpow(int a, int b) {
    if (b == 0) return 1;
    int ans = binpow(a, (b / 2));
    ans = 1ll * ans * ans % MOD;
    if (b % 2) ans = 1ll * ans * a % MOD;
    return ans;
}

int inv(int x) {return binpow(x, MOD - 2);}

void prec() {
    dp[0][0] = dp[0][1] = 1;
    for (int i = 0; i < N; i++) dp[1][i] = 1;
    dp[1][0] = dp[1][1] = 0;
    for (int i = 1; i < M - 1; i++) {
        for (int j = 1; j < N; j++) {
            if (!dp[i][j]) continue;
            for (int k = 2 * j; k < N; k += j)
                dp[i + 1][k] = (dp[i + 1][k] + dp[i][j]) % MOD;
        }
    }
    for (int i = 1; i < M; i++) INV[i] = inv(i);
}


void solve() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    int curr = 1;
    for (int i = 1; i < min(m + 1, M); i++) {
        curr = (1ll * curr * (m - i + 1)) % MOD;
        curr = (1ll * curr * INV[i]) % MOD;
        ans = (ans + 1ll * dp[i][n] * curr % MOD) % MOD;
    }
    cout << ans << "\n";
}

int main(void){
    prec();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
