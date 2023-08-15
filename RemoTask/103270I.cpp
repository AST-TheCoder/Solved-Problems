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

ll dis[4][501][501],n,m;
string g[501];
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};

void bfs(ll x,ll y,ll i){
    queue<pair<ll,ll>> q;
    q.push({x,y});

    dis[i][x][y]=0;
    while(!q.empty()){
        ll px=q.front().first;
        ll py=q.front().second;
        q.pop();
        for(ll j=0;j<4;j++){
            ll temp_x=px+dx[j];
            ll temp_y=py+dy[j];

            if(temp_x<0 || temp_x>=n || temp_y<0 || temp_y>=m || dis[i][temp_x][temp_y]!=Max || g[temp_x][temp_y]=='#') continue;
            dis[i][temp_x][temp_y]=dis[i][px][py]+1;
            q.push({temp_x,temp_y});
        }
    }
}

int main()
{
    cin>>n>>m;
    for(ll i=0;i<n;i++){
        cin>>g[i];
        for(ll j=0;j<m;j++){
            for(ll k=0;k<4;k++){
                dis[k][i][j]=Max;
            }
        }
    }

    for(ll i=0;i<4;i++){
        ll x,y;
        cin>>x>>y;
        bfs(x,y,i);
    }

    ll ans=Max;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            ll temp=0;
            for(ll k=0;k<4;k++) temp+=dis[k][i][j];
            ans=min(ans,temp);
        }
    }
    if(ans==Max) cout<<"IMPOSSIBLE"<<endl;
    else cout<<ans<<endl;

    return 0;
}