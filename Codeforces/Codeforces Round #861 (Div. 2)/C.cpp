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

string l,r,str_ans,res;
ll dp[20][2][2][2][10][10],temp;

void solve(ll pos,ll p,ll q,ll chk,ll x,ll y){
    if(pos==l.size()){
        temp=y-x;
        str_ans=res;
        return;
    }

    if(dp[pos][p][q][chk][x][y]) return;
    dp[pos][p][q][chk][x][y]=1;

    ll lo=max((ll)(l[pos]-'0'),x);
    if(p) lo=x;
    ll hi=min((ll)(r[pos]-'0'),y);
    if(q) hi=y;

    if(!chk && l[pos]=='0'){
        res+='0';
        solve(pos+1,0,1,0,x,y);
        res.erase(res.begin()+(res.size()-1));
    }

    if(lo>hi){
        return;
    }

    for(ll i=lo;i<=hi;i++){
        ll temp_p=p;
        if(i>l[pos]-'0') temp_p=1;

        ll temp_q=q;
        if(i<r[pos]-'0') temp_q=1;

        ll temp_chk=chk;
        if(i!=0) temp_chk=1;

        res+=(char)(i+'0');
        solve(pos+1,temp_p,temp_q,temp_chk,x,y);
        res.erase(res.begin()+(res.size()-1));
    }
}

int main()
{

    ll t;
    cin>>t;

    read:
    while(t--){
        cin>>l>>r;
        if(l.size()==1){
            cout<<l<<endl;
            goto read;
        }

        while(l.size()!=r.size()) l="0"+l;

        memset(dp,0,sizeof(dp));
        for(ll d=0;d<=9;d++){
            for(ll i=0;i<=9;i++){
                ll p=i,q=i+d;
                if(!p && !q) continue;
                if(q>9) continue;
                str_ans.clear();
                res.clear();
                temp=10;
                solve(0,0,0,0,p,q);
                if(temp==10) continue;
                while(str_ans[0]=='0') str_ans.erase(str_ans.begin());
                cout<<str_ans<<endl;
                goto read;
            }
        }
        
    }

    return 0;
}