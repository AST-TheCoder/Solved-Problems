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

ll g[101];

void grundy(ll x){
    ll cnt[101];
    memset(cnt,0,sizeof(cnt));
    for(ll i=2;i<=x;i++){
        ll temp=g[i-2]^g[x-i];
        cnt[temp]=1;
    }
    while(cnt[g[x]]) g[x]++;
}

int main()
{

    for(ll i=2;i<=100;i++){
        grundy(i);
    }

    ll t,ii=0;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        string a,b,c;
        cin>>a>>b>>c;

        ll chk=0;

        a=a+"X";
        b=b+"X";
        c=c+"X";
        for(ll i=1,s=0;i<a.size();i++){
            if((a[i]=='O' && a[i-1]=='O' && b[i]=='O' && b[i-1]=='O') || (b[i]=='O' && b[i-1]=='O' && c[i]=='O' && c[i-1]=='O')){
                s++;
                continue;
            }
            chk^=g[s+1];
            s=0;
        }
        if(chk) cout<<"Case "<<++ii<<": "<<"Jhinuk"<<endl;
        else cout<<"Case "<<++ii<<": "<<"Grandma"<<endl;
    }

    return 0;
}