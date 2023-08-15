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

const int MOD = 1000000000;
const int MAXN = 10;
const int MAXK = 400;

typedef vector < vector <long long> > matrix;

long long dp[MAXN][MAXK + 1], reduction[MAXN + 1][MAXK + 1], C[2 * MAXN][MAXK + 1];

void multiply(matrix& A, matrix& B){
    memset(C, 0, sizeof C);

    for(int i_1 = 0; i_1 < MAXN; i_1++)
        for(int j_1 = 0; j_1 <= MAXK; j_1++)
            for(int i_2 = 0; i_2 < MAXN; i_2++)
                for(int j_2 = 0; j_1 + j_2 <= MAXK; j_2++)
                    C[i_1 + i_2][j_1 + j_2] = (C[i_1 + i_2][j_1 + j_2] + A[i_1][j_1] * B[i_2][j_2]) % MOD;

    for(int i = 2 * MAXN - 2; i >= MAXN; i--)
        for(int j = MAXK; j >= 0; j--)
            for(int i_d = 1; i_d <= MAXN; i_d++)
                for(int j_d = 0; j + j_d <= MAXK; j_d++)
                    C[i - i_d][j + j_d] = (C[i - i_d][j + j_d] + C[i][j] * reduction[i_d][j_d]) % MOD;

    for(int i = 0; i < MAXN; i++)
        for(int j = 0; j <= MAXK; j++)
            A[i][j] = C[i][j];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    n--;

    for(int i = 0; i < m; i++){
        int d, p;
        cin >> d >> p;
        reduction[d][p]++;
    }

    dp[0][0] = 1;
    for(int i = 1; i < MAXN; i++)
        for(int j = 0; j <= MAXK; j++)
            for(int i_d = 1; i_d <= i; i_d++)
                for(int j_d = 0; j_d <= j; j_d++)
                    dp[i][j] = (dp[i][j] + dp[i - i_d][j - j_d] * reduction[i_d][j_d]) % MOD;

    matrix A(MAXN, vector <long long> (MAXK + 1, 0));
    matrix B(MAXN, vector <long long> (MAXK + 1, 0));

    A[0][0] = 1;
    B[1][0] = 1;

    for(int i = 0; i < 30; i++){
        if(n & (1 << i))multiply(A, B);
        multiply(B, B);
    }

    long long res = 0;
    for(int i = 0; i < MAXN; i++)
        for(int j_1 = 0; j_1 <= k; j_1++)
            for(int j_2 = 0; j_1 + j_2 <= k; j_2++)
                res = (res + dp[i][j_1] * A[i][j_2]) % MOD;

    cout << res << '\n';

    return 0;
}