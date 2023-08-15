#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define el '\n'
#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
typedef unsigned long long ull;

template<typename T, typename X>
using hashTable = gp_hash_table<T, X>;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// mt19937_64 for long long
mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());

const int N = 1e5 + 5;

int id;
bool vis[N];
vector<int> G[N];
set<int> artPoints;
int tin[N], lowLink[N];

void tarjan(int u, int par = -1)
{
    vis[u] = true;
    int children = 0;
    tin[u] = lowLink[u] = ++id;
    for(auto &v: G[u])
    {
        if(v == par)
            continue;

        if(vis[v])
            lowLink[u] = min(lowLink[u], tin[v]);
        else
        {
            children++;
            tarjan(v, u);
            lowLink[u] = min(lowLink[u], lowLink[v]);
            if(lowLink[v] >= tin[u] && par != -1)
                artPoints.insert(u);
        }
    }
    if(par == -1 && children > 1)
        artPoints.insert(u);
}

void doWork()
{
    int n, m;
    cin >> n >> m;
    vector<int> deg(n + 1);
    for(int i = 0, u, v; i < m; i++)
        cin >> u >> v, G[u].push_back(v), G[v].push_back(u), deg[u]++, deg[v]++;

    vector<int> r;
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
            tarjan(i), r.push_back(i);
    }

    if(r.size() > 2)
        return cout << "NO", void();
    else if(r.size() == 2)
    {
        int node = -1;
        for(auto &it: r)
        {
            if(!deg[it])
                node = it;
        }

        if(node == -1)
            return cout << "NO", void();

        artPoints.clear();
        for(int i = 1; i <= n; i++)
        {
            if(i == node)
                continue;
            artPoints.insert(i);
        }
    }


    map<int, int> mp;
    for(int i = 1; i <= n; i++)
        mp[deg[i]]++;
    
    for(int u = 1; u <= n; u++)
    {
        if(artPoints.count(u))
            continue;

        mp[deg[u]]--;
        for(auto &v: G[u])
        {
            mp[deg[v]]--;
            deg[v]--;
            mp[deg[v]]++;
        }

        if(mp[2] == n - 3 && mp[1] == 2)
            return cout << "YES", void();

        mp[deg[u]]++;
        for(auto &v: G[u])
        {
            mp[deg[v]]--;
            deg[v]++;
            mp[deg[v]]++;
        }
    }
    cout << "NO";
}

signed main()
{
    FIO
    int T = 1;
//    cin >> T;
    for(int i = 1; i <= T; i++)
        doWork();
}