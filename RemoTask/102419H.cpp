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
const int sz=2e3+10;
int re[sz][2], st[sz], yk[sz], us[sz];
vector <int> to[sz];
bool dfs(int v)
{
    us[v]=1;
    for(int a=0; a<2; a++)
    {
        int ne=re[v][a];
        if(int(to[ne].size())<st[ne])
        {
            to[ne].push_back(v);
            return true;
        }
        while(yk[ne]<to[ne].size())
        {
            int p=yk[ne]++, v2=to[ne][p];
            if(!us[v2] and dfs(v2))
            {
                to[ne][p]=v;
                return true;
            }
        }
    }
    return false;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, su=0;
    cin>>n>>m;
    for(int a=0; a<n; a++)
    {
        cin>>st[a];
        if(st[a]>0) su+=st[a];
    }
    vector <int> sp[2];
    for(int a=0; a<m; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        re[a][0]=u, re[a][1]=v;
        if(st[u]==-1 or st[v]==-1) sp[1].push_back(a);
        else sp[0].push_back(a);
    }
    for(int i=0; i<2; i++)
    {
        for(int a=0; a<sp[i].size(); a++)
        {
            int v=sp[i][a];
            for(int a=0; a<m; a++) us[a]=0;
            for(int b=0; b<n; b++) yk[b]=0;
            int add=dfs(v);
            su-=add;
            if(!add)
            {
                if(i==0)
                {
                    cout<<"NO";
                    return 0;
                }
                if(st[re[v][0]]==-1) swap(re[v][0], re[v][1]);
            }
        }
    }
    if(su)
    {
        cout<<"NO";
        return 0;
    }
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<to[a].size(); b++)
        {
            int nu=to[a][b];
            if(re[nu][1]!=a) swap(re[nu][0], re[nu][1]);
        }
    }
    cout<<"YES\n";
    for(int a=0; a<m; a++) printf("%d %d\n", re[a][0]+1, re[a][1]+1);
}
