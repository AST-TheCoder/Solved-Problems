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
        string s;
        cin>>s;
        ll n=s.size();
        s="-"+s;
        ll k;
        cin>>k;
        ll p=k;

        ll im[n+1][60];
        for(ll i=n;i>=1;i--){
            for(ll j='0';j<='9';j++){
                if(i==n) im[i][j]=Max;
                else im[i][j]=im[i+1][j];
            }
            im[i][s[i]]=i;
        }

        priority_queue<pair<ll,ll>> q;
        min_heap<ll> idx;
        ll f=0;

        q.push({s[1],1});
        for(ll i=2;i<=n && k;i++){
            while(!q.empty() && q.top().first>s[i] && k){
                if(s[i]!='0' || q.size()>1 || f==1){
                    idx.push(q.top().second);
                    q.pop();
                    k--;
                    continue;
                }
                ll mn=Max;
                for(ll j=q.top().first-1;j>'0';j--) mn=min(mn,im[i][j]);

                if(mn<=i+k-1){
                    idx.push(q.top().second);
                    k--;
                    while(i<mn){
                        k--;
                        idx.push(i);
                        i++;
                    }
                }
                else f=1;
                q.pop();
            }
            q.push({s[i],i});
        }
        string ans;
        for(ll i=1;i<=n && ans.size()<n-p;i++){
            if(!idx.empty() && i==idx.top()) idx.pop();
            else ans+=s[i];
        }
        cout<<ans<<endl;
    }

    return 0;
}