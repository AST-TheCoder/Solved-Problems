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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;

    while(t--){
        ll n,m;
        cin>>n>>m;

        string s[n];
        for(ll i=0;i<n;i++) cin>>s[i];

        for(ll j=0;j<m-1;j++){
            ll c=0;
            for(ll i=0;i<n;i++){
                if(s[i][j]=='L'){
                    if(c%2){
                        s[i][j]='B';
                        s[i][j+1]='W';
                    }
                    else{
                        s[i][j]='W';
                        s[i][j+1]='B';
                    }
                    c++;
                }
            }
        }

        for(ll i=0;i<n-1;i++){
            ll c=0;
            for(ll j=0;j<m;j++){
                if(s[i][j]=='U'){
                    if(c%2){
                        s[i][j]='B';
                        s[i+1][j]='W';
                    }
                    else{
                        s[i][j]='W';
                        s[i+1][j]='B';
                    }
                    c++;
                }
            }
        }
        ll chk=0;
        for(ll i=0;i<n;i++){
            ll x=0,y=0;
            for(ll j=0;j<m;j++){
                if(s[i][j]=='W') x++;
                if(s[i][j]=='B') y++;
            }
            if(x!=y) chk=1;
        }

        for(ll j=0;j<m;j++){
            ll x=0,y=0;
            for(ll i=0;i<n;i++){
                if(s[i][j]=='W') x++;
                if(s[i][j]=='B') y++;
            }
            if(x!=y) chk=1;
        }

        if(chk){
            cout<<-1<<endl;
            continue;
        }

        for(ll i=0;i<n;i++) cout<<s[i]<<"\n";
    }

    return 0;
}