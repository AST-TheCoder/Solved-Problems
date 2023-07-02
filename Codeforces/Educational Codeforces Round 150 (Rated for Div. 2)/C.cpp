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

ll val[]={1,10,100,1000,10000};

int main()
{

    ll t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;

        ll a[s.size()];
        ll m[s.size()];
        memset(a,0,sizeof(a));
        memset(m,0,sizeof(m));
        ll x=s[s.size()-1];
        a[s.size()-1]=val[x-'A'];
        for(ll i=(ll)s.size()-2;i>=0;i--){
            m[i]=(x-'A');
            a[i]=a[i+1];
            if(x>s[i]){
                a[i]-=val[s[i]-'A'];
            }
            else{
                a[i]+=val[s[i]-'A'];
                x=s[i];
            }
        }
        ll ans=a[0];
        ll p[5];
        x=0;
        memset(p,0,sizeof(p));
        for(ll i=0;i<s.size();i++){
            for(ll j=0;j<=4;j++){
                ll temp=0;
                if(i+1!=s.size()) temp=a[i+1];
                if(j>=m[i]) temp+=val[j];
                else temp-=val[j];
                for(ll k=0;k<=4;k++){
                    if(k<max(j,m[i])) temp-=p[k];
                    else temp+=p[k];
                }
                temp-=x;
                ans=max(ans,temp);
                //cout<<temp<<" ";
            }
            for(ll j=0;j<s[i]-'A';j++){
                x+=p[j];
                p[j]=0;
            }
            p[s[i]-'A']+=val[s[i]-'A'];
        }
        cout<<ans<<endl;
    }

    return 0;
}