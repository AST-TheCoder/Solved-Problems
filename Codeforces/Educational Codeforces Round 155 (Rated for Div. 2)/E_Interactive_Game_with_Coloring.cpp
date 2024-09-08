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

int main()
{

    ll n;
    cin>>n;

    ll p[n+1];
    ll c[n+1];
    memset(c,0,sizeof(c));
    for(ll i=2;i<=n;i++){
        cin>>p[i];
        c[p[i]]++;
    }

    ll x[n+1],k=1,chk[n+1][n+1];
    x[1]=1;
    memset(chk,0,sizeof(chk));
    for(ll i=2;i<=n;i++){
        if(!c[i]) continue;
        if(c[i]>1){
            if(x[p[i]]==1) x[i]=2;
            else x[i]=1;
            k=max(k,x[i]);
            continue;
        }
        x[i]=x[p[i]]+1;
        for(ll j=1;j<=k;j++){
            if(j==x[p[i]]) continue;
            if(chk[j][x[p[i]]]) continue;
            x[i]=j;
            break;
        }
        k=max(k,x[i]);
        chk[x[p[i]]][x[i]]=1;
    }

    cout<<k<<endl;
    for(ll i=2;i<=n;i++) cout<<x[p[i]]<<" ";
    cout<<endl;

    while(1){
        ll v;
        cin>>v;
        if(v==-1) return 0;
        if(v==1) return 0;
        ll col[k+1],mn=Max,mx=0,cnt=0;
        for(ll i=1;i<=k;i++){
            cin>>col[i];
            if(!col[i]) continue;
            cnt++;
            mn=min(mn,col[i]);
            mx=max(mx,col[i]);
        }

        if(cnt==1){
            for(ll i=1;i<=k;i++){
                if(col[i]){
                    cout<<i<<endl;
                    break;
                }
            }
        }
        else if(mn==mx){
            ll i1=-1,i2;
            for(ll i=1;i<=k;i++){
                if(col[i]){
                    if(i1==-1) i1=i;
                    else{
                        i2=i;
                        break;
                    }
                }
            }
            if(chk[i1][i2]) cout<<i1<<endl;
            else cout<<i2<<endl;
        }
        else{
            for(ll i=1;i<=k;i++){
                if(col[i]==1){
                    cout<<i<<endl;
                    break;
                }
            }
        }
    }

    return 0;
}