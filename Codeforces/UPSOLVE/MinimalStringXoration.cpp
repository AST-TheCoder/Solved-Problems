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

string s;
vector<ll> val[2000000];
vector<pair<ll,ll>> ans[2000000];
ll base=131,mod=1000000891,inv[1000000],mul[1000000];

ll chk(ll x,ll y,ll left,ll right,ll n,ll i,ll j,ll p){
    ll l=1,r=p,id=j,pp=log2(p);
    ll temp_left=left,temp_right=right;
    ll left_n=n,right_n=n;

    while(l<=r){
        pp--;
        p/=2;
        ll m=(l+r)/2;

        ll u,v;
        if(temp_left&(1<<pp)){
            ll temp=temp_left^(1<<pp);
            u=x-val[2*left_n][temp];
            if(u<0) u+=mod;
        }
        else{
            ll temp=temp_left;
            u=x-val[2*left_n+1][temp];
            if(u<0) u+=mod;
        }
        if(temp_right&(1<<pp)){
            ll temp=temp_right^(1<<pp);
            v=y-val[2*right_n][temp];
            if(v<0) v+=mod;
        }
        else{
            ll temp=temp_right;
            v=y-val[2*right_n+1][temp];
            if(v<0) v+=mod;
        }

        if(u!=v){
            id=i+m-1;
            r=m-1;
            x=(u*inv[p])%mod;
            y=(v*inv[p])%mod;
            if(temp_left&(1<<pp)){
                temp_left^=(1<<pp);
                left_n=2*left_n+1;
            }
            else left_n=2*left_n;

            if(temp_right&(1<<pp)){
                temp_right^=(1<<pp);
                right_n=2*right_n+1;
            }
            else right_n=2*right_n;
        }
        else{
            l=m+1;
            x=x-u;
            if(x<0) x+=mod;
            y=y-v;
            if(y<0) y+=mod;

            if(temp_left&(1<<pp)){
                temp_left^=(1<<pp);
                left_n=2*left_n;
            }
            else left_n=2*left_n+1;

            if(temp_right&(1<<pp)){
                temp_right^=(1<<pp);
                right_n=2*right_n;
            }
            else right_n=2*right_n+1;
        }
    }

    //cout<<(id^left)<<" "<<(id^right)<<" "<<id<<endl;
    if(s[id^left]>s[id^right]) return 0;
    else return 1;
}

void build(ll n,ll l,ll r,ll p){
    if(l==r){
        val[n].pb(s[l]-'a');
        ans[n].pb({s[l]-'a',0});
        return;
    }

    ll left=2*n;
    ll right=2*n+1;

    build(left,l,(l+r)/2,p/2);
    build(right,(l+r)/2+1,r,p/2);

    for(ll i=0;i<p/2;i++){
        ll v=(val[left][i]*mul[p/2]+val[right][i])%mod;
        val[n].pb(v);
        ans[n].pb({v,i});
    }
    for(ll i=0;i<p/2;i++){
        ll v=(val[right][i]*mul[p/2]+val[left][i])%mod;
        val[n].pb(v);
        ans[n].pb({v,i+p/2});
    }

}

int main()
{

    mul[0]=1;
    inv[0]=1;
    ll temp=129771108;
    for(ll i=1;i<300000;i++){
        mul[i]=(mul[i-1]*base)%mod;
        inv[i]=(inv[i-1]*temp)%mod;
    }

    ll n;
    cin>>n;
    cin>>s;

    build(1,0,(1<<n)-1,(1<<n));
    
    pair<ll,ll> idx=ans[1][0];
    for(ll i=1;i<ans[1].size();i++){
        if(idx.first==ans[1][i].first) continue;
        ll cmp=chk(idx.first,ans[1][i].first,idx.second,ans[1][i].second,1,0,(1<<n)-1,(1<<n));
        if(!cmp) idx=ans[1][i];
    }

    //cout<<ans[1][0].second<<endl;

    string res;
    for(ll i=0;i<s.size();i++) res+=s[i^idx.second];
    cout<<res<<"\n";

    return 0;
}