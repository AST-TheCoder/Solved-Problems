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

ll u[3000][3000],r[3000][3000],l[3000][3000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;

    while(t--){
        ll n,ans=0;
        cin>>n;

        string s[n];
        for(ll i=0;i<n;i++) cin>>s[i];
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                u[i][j]=l[i][j]=r[i][j]=0;
            }
        }

        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                if(i){
                    if(j) r[i][j]+=r[i-1][j-1];
                    else l[i][j]+=l[i-1][j];
                    if(j<n-1) l[i][j]+=l[i-1][j+1];
                    else r[i][j]+=r[i-1][j];
                }
            }
            ll m=0;
            for(ll j=0;j<n;j++){
                m+=l[i][j];
                ll temp=r[i][j];
                if(s[i][j]=='0'){
                    if(m%2){
                        ans++;
                        l[i][j]++;
                        r[i][j]++;
                    }
                }
                else{
                    if(m%2==0){
                        ans++;
                        l[i][j]++;
                        r[i][j]++;
                    }
                }
                //cout<<i<<" "<<j<<" "<<m<<endl;
                m-=temp;
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}