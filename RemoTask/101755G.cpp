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

vector<ll> x[2],p[2][800001],q[2][800001];
ll a[200001];

void m_sort(ll tp,ll n,ll l,ll r){
    if(l==r){
        p[tp][n].pb(x[tp][l]);
        q[tp][n].pb(x[tp][l]);
        return;
    }
    m_sort(tp,2*n,l,(l+r)/2);
    m_sort(tp,2*n+1,(l+r)/2+1,r);

    for(ll i=0,j=0;i<p[tp][2*n].size() || j<p[tp][2*n+1].size();){
        if(i==p[tp][2*n].size()){
            p[tp][n].pb(p[tp][2*n+1][j]);
            j++;
        }
        else if(j==p[tp][2*n+1].size()){
            p[tp][n].pb(p[tp][2*n][i]);
            i++;
        }
        else if(p[tp][2*n][i]<=p[tp][2*n+1][j]){
            p[tp][n].pb(p[tp][2*n][i]);
            i++;
        }
        else{
            p[tp][n].pb(p[tp][2*n+1][j]);
            j++;
        }
    }
    q[tp][n].pb(p[tp][n][0]);
    for(ll i=1;i<p[tp][n].size();i++) q[tp][n].pb(q[tp][n][i-1]+p[tp][n][i]);
}

ll query(ll tp,ll n,ll l,ll r,ll i,ll j,ll v){
    if(l>j || r<i) return 0;
    if(l>=i && r<=j){
        ll id=upper_bound(all(p[tp][n]),v)-p[tp][n].begin();
        ll ans=id*v;
        ans+=q[tp][n][q[tp][n].size()-1];
        if(id) ans-=2*q[tp][n][id-1];
        ans-=v*(q[tp][n].size()-id);
        return ans;
    }
    return query(tp,2*n,l,(l+r)/2,i,j,v)+query(tp,2*n+1,(l+r)/2+1,r,i,j,v);
}

int main()
{

    ll n,k;
    cin>>n>>k;

    x[0].pb(0);x[1].pb(0);
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        x[i%2].pb(a[i]);
    }

    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    
    m_sort(1,1,1,x[1].size()-1);
    m_sort(0,1,1,x[0].size()-1);

    ll ans=0;
    for(ll i=1;i<=n-k/2;i++){
        ll r=i+k-1;
        ll temp=min(i,(k+1)/2);
        ll l=i-2*temp+k+1;
        if(l>n) continue;
        ll tp=r%2;
        if(r>n){
            r-=2*(r-n);
        }
        //cout<<i<<" "<<l<<" "<<r<<endl;
        r=(r+1)/2;
        l=(l+1)/2;
        ans+=query(tp,1,1,x[tp].size()-1,l,r,a[i]);
    }
    cout<<ans<<endl;

    return 0;
}