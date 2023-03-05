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
    read:
    while(t--){
        ll n,k;
        cin>>n>>k;

        string s;
        cin>>s;

        ll cnt[26];
        memset(cnt,0,sizeof(cnt));
        for(ll i=0;i<n;i++){
            cnt[s[i]-'a']++;
        }

        vector<char> v;
        for(ll i=0;i<26;i++){
            if(cnt[i]) v.pb((char)(i+'a'));
            for(ll j=i;j<26;j++){
                if(!cnt[i] || !cnt[j]) continue;
                ll d=abs(cnt[i]-cnt[j]);
                if(d>k){
                    cout<<-1<<endl;
                    goto read;
                }
            }
        }

        string ans;
        while(ans.size()<n){
            char ch=v[v.size()-1];
            ll x=min(k,cnt[ch-'a']);
            cnt[ch-'a']-=x;
            while(x--) ans+=ch;
            while(cnt[ch-'a']--){
                for(ll i=(ll)v.size()-2;i>=0;i--){
                    ans+=v[i];
                    cnt[v[i]-'a']--;
                    if(!cnt[v[i]-'a']){
                        v.erase(v.begin()+i);
                    }
                }
                ans+=ch;
            }
            v.pop_back();
        }
        reverse(all(ans));
        cout<<ans<<endl;
    }

    return 0;
}