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
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;

int main()
{

    ll n,ans=0;
    cin>>n;
    pair<ll,string> temp[n];
    string s[n];
    for(ll i=0;i<n;i++){
        cin>>temp[i].second;
        temp[i].first=temp[i].second.size();
    }

    sort(temp,temp+n);
    for(ll i=0;i<n;i++) s[i]=temp[i].second;

    ordered_set<ll> v[6];

    for(ll i=0;i<n;i++){
        ll sum=0;
        for(ll j=0;j<s[i].size();j++) sum+=s[i][j]-'0';
        if(s[i].size()%2){
            for(ll j=1;j<=s[i].size();j+=2){
                ll len=(s[i].size()+j)/2;
                ll x=0,y=0,px=0,py=0;
                for(ll k=0;k<s[i].size();k++){
                    if(k<len) x+=s[i][k]-'0';
                    else px+=s[i][k]-'0';
                    if(k>=s[i].size()-len) y+=s[i][k]-'0';
                    else py+=s[i][k]-'0';
                }
                //cout<<s[i]<<" "<<len<<" "<<x<<" "<<px<<" "<<y<<" "<<py<<endl;
                px=x-px;
                ll l=v[j].order_of_key(px);
                ll r=v[j].order_of_key(px+1);
                ans+=(r-l);
                //cout<<l<<" "<<r<<endl;
                py=y-py;
                l=v[j].order_of_key(py);
                r=v[j].order_of_key(py+1);
                ans+=(r-l);
                //cout<<l<<" "<<r<<endl;
            }
        }
        else{
            for(ll j=2;j<=s[i].size();j+=2){
                ll len=(s[i].size()+j)/2;
                ll x=0,y=0,px=0,py=0;
                for(ll k=0;k<s[i].size();k++){
                    if(k<len) x+=s[i][k]-'0';
                    else px+=s[i][k]-'0';
                    if(k>=s[i].size()-len) y+=s[i][k]-'0';
                    else py+=s[i][k]-'0';
                }
                //cout<<s[i]<<" "<<len<<" "<<x<<" "<<px<<" "<<y<<" "<<py<<endl;
                px=x-px;
                ll l=v[j].order_of_key(px);
                ll r=v[j].order_of_key(px+1);
                ans+=(r-l);
                //cout<<l<<" "<<r<<endl;
                py=y-py;
                l=v[j].order_of_key(py);
                r=v[j].order_of_key(py+1);
                ans+=(r-l);
                //cout<<l<<" "<<r<<endl;
            }
        }
        v[s[i].size()].insert(sum);
        ans++;
    }

    cout<<ans<<endl;

    return 0;
}