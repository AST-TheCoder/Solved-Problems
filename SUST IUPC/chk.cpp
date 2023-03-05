#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'

bool vis[1000][1000];
bool bfs(int n, int m)
{
    memset(vis, false, sizeof(vis));
    // cin >> n >> m;
    queue<pair<int, int>> Q;
    vis[1][1] = true;
    Q.push({1, 1});
    while (!Q.empty())
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int dist = (x - i) * (x - i) + (y - j) * (y - j);
                if ((int)sqrt(dist) * sqrt(dist) == dist && !vis[i][j] && x != i && y != j)
                {
                    Q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }
    }
    return vis[n][m];
}
int solve()
{
    int n, m;
    cin >> n >> m;
    int a = n, b = m;
    if(n > m) swap(n, m);
    string ans1 = "";
    if(n == 1 && m == 1) {
        ans1 = "YES";
        // cout << "YES" << endl;
        // return 0;
    }
    else if(n <= 10 && m <= 10)
    {
        ans1 = (bfs(n, m) ? "YES" : "NO" );
    }
    else if(n == 1 || n == 2 || n == 3)
    {
        ans1 = "NO";
    }
    else if((n == 4 && (m - 5) % 8 == 0) || (n == 5 && m % 2 == 0) || (n == 6 && (m - 1) % 2 == 0))
    {
        ans1 = "YES";
    }
    else if(n >= 7 && m > 7)
    {
        ans1 = "YES";
    }
    else
    {
        ans1 = "NO";
    }
    cout << ans1 << endl;

    return 0;
}

int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int ii = 1; ii <= t; ii++)
    {
        cout<<"Case "<<ii<<": ";
        solve();
    }
    // cout << "END" << endl;
}