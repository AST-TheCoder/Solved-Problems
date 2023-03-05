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

ll dp[17][1<<16],m[17][17],n,nxt[17][1<<16];
vector<string> s;

ll solve(ll prev,ll mask){
    if(dp[prev][mask]!=-1) return dp[prev][mask];
    
    dp[prev][mask]=Max;
    for(ll i=0;i<n;i++){
        if(mask&(1<<i)) continue;
        ll val=solve(i,mask|(1<<i))+m[prev][i];
        if(val<dp[prev][mask]){
            dp[prev][mask]=val;
            nxt[prev][mask]=i;
        }
        if(val==dp[prev][mask]){
            ll id=nxt[prev][mask],chk=-1,len1=0,len2=0;
            for(ll j=s[id].size()-m[prev][id],k=s[i].size()-m[prev][i];j<s[id].size() && k<s[i].size();j++,k++){
                if(s[id][j]<s[i][k]){
                    chk=1;
                    break;
                }
                if(s[id][j]>s[i][k]){
                    chk=0;
                    break;
                }
                len1++,len2++;
            }
            if(!chk) nxt[prev][mask]=i;
            if(chk==-1){
                if(len1<len2) nxt[prev][mask]=i;
            }
        }
    }
    if(dp[prev][mask]==Max) dp[prev][mask]=0;
    //cout<<dp[prev][mask]<<" "<<prev<<" "<<mask<<endl;
    return dp[prev][mask];
}

void print(ll prev,ll mask){
    ll id=nxt[prev][mask];
    if(id==-1) return;
    ll len=m[prev][id];
    for(ll i=s[id].size()-len;i<s[id].size();i++) cout<<s[id][i];
    print(id,mask|(1<<id));
}

int main()
{

    ll t,ii=0;
    scanf("%lli",&t);

    while(t--){
        memset(dp,-1,sizeof(dp));
        memset(nxt,-1,sizeof(nxt));
        memset(m,0,sizeof(m));
        
        scanf("%lli",&n);

        string a[n];
        for(ll i=0;i<n;i++) cin>>a[i];

        s.clear();
        for(ll i=0;i<n;i++){
            ll chk=0;
            for(ll j=0;j<n;j++){
                if(j>=i && a[j]==a[i]) continue;
                if(a[i].size()>a[j].size()) continue;
                for(ll k=0;k<=a[j].size()-a[i].size();k++){
                    string temp=a[j].substr(k,a[i].size());
                    if(temp==a[i]){
                        chk=1;
                        break;
                    }
                }
                if(chk) break;
            }
            if(!chk){
                s.pb(a[i]);
            }
        }

        sort(all(s));
        n=s.size();
        
        for(ll i=0;i<n;i++){
            m[16][i]=s[i].size();
            for(ll j=0;j<n;j++){
                if(i==j) continue;
                m[i][j]=s[j].size();
                for(ll k=min(s[i].size(),s[j].size());k>0;k--){
                    string str1=s[i].substr(s[i].size()-k,k);
                    string str2=s[j].substr(0,k);
                    //cout<<k<<" "<<str1<<" "<<str2<<endl;
                    if(str1==str2){
                        m[i][j]=s[j].size()-k;
                        break;
                    }
                }
                //cout<<i<<" "<<j<<" "<<m[i][j]<<endl;
            }
        }

        ll len=solve(16,0);
        
        cout<<"Case "<<++ii<<": ";
        print(16,0);
        cout<<endl;
    }

    return 0;
}