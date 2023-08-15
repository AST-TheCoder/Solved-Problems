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
ll k,x,y,dp[500][500][250];

ll solve(ll l,ll r,ll p,ll q){
    if(r<l) return 0;
    if(l==r) return 1;
    if(dp[l][r][p]!=-1) return dp[l][r][p];
    ll ret=0;
    if(s[l]==s[r]){
        if(s[l]=='?'){
            if(x-p>=2) ret=max(ret,solve(l+1,r-1,p+2,q)+2);
            if(y-q>=2) ret=max(ret,solve(l+1,r-1,p,q+2)+2);
            if(x-p && y-q){
                ret=max(ret,solve(l+1,r,p,q+1));
                ret=max(ret,solve(l+1,r,p+1,q));
                ret=max(ret,solve(l,r-1,p,q+1));
                ret=max(ret,solve(l,r-1,p+1,q));
            }
        }
        else ret=max(ret,solve(l+1,r-1,p,q)+2);
    }
    else{
        if(s[l]=='?'){
            if(s[r]=='0'){
                if(x-p) ret=max(ret,solve(l+1,r-1,p+1,q)+2);
                if(y-q) ret=max(ret,solve(l+1,r,p,q+1));
                ret=max(ret,solve(l,r-1,p,q));
            }
            else{
                if(y-q) ret=max(ret,solve(l+1,r-1,p,q+1)+2);
                if(x-p) ret=max(ret,solve(l+1,r,p+1,q));
                ret=max(ret,solve(l,r-1,p,q));
            }
        }
        else if(s[r]=='?'){
            if(s[l]=='0'){
                if(x-p) ret=max(ret,solve(l+1,r-1,p+1,q)+2);
                if(y-q) ret=max(ret,solve(l,r-1,p,q+1));
                ret=max(ret,solve(l+1,r,p,q));
            }
            else{
                if(y-q) ret=max(ret,solve(l+1,r-1,p,q+1)+2);
                if(x-p) ret=max(ret,solve(l,r-1,p+1,q));
                ret=max(ret,solve(l+1,r,p,q));
            }
        }
        else{
            ret=max(ret,solve(l+1,r,p,q));
            ret=max(ret,solve(l,r-1,p,q));
        }
    }

    return dp[l][r][p]=ret;
}

int main()
{

    memset(dp,-1,sizeof(dp));
    cin>>s>>k;
    for(ll i=0;i<k;i++){
        ll pos;
        cin>>pos;
        if(s[pos-1]=='0') x++;
        else y++;
        s[pos-1]='?';
    }
    if(x>y){
        swap(x,y);
        for(ll i=0;i<s.size();i++){
            if(s[i]=='?') continue;
            if(s[i]=='1') s[i]='0';
            else s[i]='1';
        }
    }

    ll ans=solve(0,s.size()-1,0,0);
    cout<<ans<<endl;

    return 0;
}