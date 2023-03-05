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

vector<vector<ll>> a,ans,b;
ll mod;

void mul(vector<vector<ll>>& p, vector<vector<ll>>& q){
    vector<vector<ll>> res;

    for(ll i=0;i<p.size();i++){
        vector<ll> temp;
        for(ll j=0;j<q[0].size();j++){
            ll val=0;
            for(ll k=0;k<q.size();k++){
                val=(val+(p[i][k]*q[k][j]))%mod;
            }
            temp.pb(val);
        }
        res.pb(temp);
    }
    p=res;
}

void mat_exponention(ll p){
    if(p==1){
        ans=a;
        return;
    }
    if(p%2){
        mat_exponention(p-1);
        mul(ans,a);
        return;
    }
    mat_exponention(p/2);
    mul(ans,ans);
}

int main()
{

    ll t,ii=0;
    cin>>t;

    while(t--){
        ll a1,b1,c1,a2,b2,c2;
        cin>>a1>>b1>>c1>>a2>>b2>>c2;
        ll f[3],g[3];
        cin>>f[0]>>f[1]>>f[2];
        cin>>g[0]>>g[1]>>g[2];
        cin>>mod;
        a1%=mod;
        b1%=mod;
        c1%=mod;
        a2%=mod;
        b2%=mod;
        c2%=mod;
        for(ll i=0;i<3;i++){
            f[i]%=mod;
            g[i]%=mod;
        }
        ll q;
        cin>>q;
        cout<<"Case "<<++ii<<":\n";
        while(q--){
            a.clear();
            b.clear();
            ans.clear();

            ll n;
            cin>>n;
            if(n<=2){
                cout<<f[n]<<" "<<g[n]<<endl;
                continue;
            }

            a.pb({a1,b1,c1,0,0,0});
            a.pb({1,0,0,0,0,0});
            a.pb({0,0,0,0,1,0});
            a.pb({0,0,0,a2,b2,c2});
            a.pb({0,0,0,1,0,0});
            a.pb({0,1,0,0,0,0});
            mat_exponention(n-2);
            b.pb({f[2]});
            b.pb({f[1]});
            b.pb({g[0]});
            b.pb({g[2]});
            b.pb({g[1]});
            b.pb({f[0]});
            mul(ans,b);
            cout<<ans[0][0]<<" "<<ans[3][0]<<endl;
        }
    }

    return 0;
}