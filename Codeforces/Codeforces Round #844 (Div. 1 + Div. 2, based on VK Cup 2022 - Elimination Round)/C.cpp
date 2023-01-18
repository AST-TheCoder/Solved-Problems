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
        ll n;
        cin>>n;

        string s,temp;
        cin>>s;

        ll cnt[26];
        memset(cnt,0,sizeof(cnt));

        ll d=Max,div=0;
        pair<ll,char> x[26];
        for(ll i=0;i<n;i++){
            cnt[s[i]-'a']++;
            temp+='*';
        }
        for(ll i=0;i<26;i++){
            x[i]={cnt[i],(char)(i+'a')};
        }
        sort(x,x+26);

        for(ll i=1;i<=26;i++){
            if(n%i) continue;
            ll val=n/i,c=0;
            for(ll j=0;j<26;j++){
                if(j<26-i){
                    c+=x[j].first;
                    continue;
                }
                if(x[j].first<=val) continue;
                c+=(x[j].first-val);
            }
            if(c<d){
                d=c;
                div=i;
            }
        }
        ll val=n/div;
        memset(cnt,0,sizeof(cnt));

        for(ll i=25;div;i--,div--){
            char c=x[i].second;
            cnt[c-'a']=val;
        }

        for(ll i=0;i<n;i++){
            if(cnt[s[i]-'a']){
                cnt[s[i]-'a']--;
                temp[i]=s[i];
            }
        }
        for(ll i=0,j=0;;){
            while(i<n && temp[i]!='*') i++;
            if(i==n) break;
            while(j<26 && !cnt[j]) j++;
            if(j==26) break;
            temp[i]=(char)(j+'a');
            cnt[j]--;
        }
        cout<<d<<"\n";
        cout<<temp<<"\n";
    }

    return 0;
}