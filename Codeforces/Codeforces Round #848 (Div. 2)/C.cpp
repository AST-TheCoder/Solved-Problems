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

    ll t;
    cin>>t;

    while(t--){
        ll n,k;
        cin>>n>>k;
        string a,b;
        cin>>a>>b;

        ll chk[26],cnt=0,c=0;
        memset(chk,-1,sizeof(chk));
        for(ll i=0;i<a.size();i++){
            if(chk[a[i]-'a']==-1){
                chk[a[i]-'a']=c;
                c++;
                cnt++;
            }
        }
        for(ll i=0;i<b.size();i++){
            if(chk[b[i]-'a']==-1){
                chk[b[i]-'a']=c;
                c++;
            }
        }

        for(ll i=0;i<n;i++){
            a[i]=(char)(chk[a[i]-'a']+'a');
            b[i]=(char)(chk[b[i]-'a']+'a');
        }
        ll p=(1<<cnt),ans=0;
        for(ll i=0;i<p;i++){
            c=0;
            for(ll j=0;j<cnt;j++){
                if(i&(1<<j)) c++;
            }
            if(c>k) continue;
            ll temp=0;
            for(ll j=0,s=0;j<n;j++){
                ll q=a[j]-'a';
                if(a[j]==b[j] || (i&(1<<q))) s++;
                else s=0;
                temp+=s;
            }
            ans=max(ans,temp);
        }
        cout<<ans<<endl;
    }

    return 0;
}