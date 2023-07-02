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

    ll t;
    scanf("%lli",&t);

    while(t--){
        ll n;
        scanf("%lli",&n);

        ll a[n],b[n],mh=0,mw=0,ar=0;
        for(ll i=0;i<n;i++){
            scanf("%lli %lli",&a[i],&b[i]);
            mh=max(mh,a[i]);
            mw=max(mw,b[i]);
            ar+=(a[i]*b[i]);
        }

        //cout<<ar<<" "<<mh<<" "<<mw<<endl;

        vector<pair<ll,pair<ll,ll>>> p,q;
        for(ll i=0;i<n;i++){
            p.pb({a[i],{b[i],i}});
            q.pb({b[i],{a[i],i}});
        }

        sort(all(p),greater<pair<ll,pair<ll,ll>>>());
        sort(all(q),greater<pair<ll,pair<ll,ll>>>());
        
        set<pair<ll,ll>> ans;
        if(ar%mh==0){
            ll h=mh;
            ll w=ar/mh;
            ll chk[n];
            memset(chk,0,sizeof(chk));

            ll i=0,j=0;
            while(h>0 && w>0){
                if(i==n || j==n) break;
                if(p[i].first!=h && q[j].first!=w) break;
                if(p[i].first!=h){
                    h-=q[j].second.first;
                    chk[q[j].second.second]=1;

                    while(i<n && chk[p[i].second.second]) i++;
                    while(j<n && chk[q[j].second.second]) j++;
                }
                else if(q[j].first!=w){
                    w-=p[i].second.first;
                    chk[p[i].second.second]=1;

                    while(i<n && chk[p[i].second.second]) i++;
                    while(j<n && chk[q[j].second.second]) j++;
                }
                else{
                    h-=q[j].second.first;
                    w-=p[i].second.first;
                    chk[p[i].second.second]=1;
                    chk[q[j].second.second]=1;

                    while(i<n && chk[p[i].second.second]) i++;
                    while(j<n && chk[q[j].second.second]) j++;
                }
            }

            if(!h && !w) ans.insert({mh,ar/mh});
        }
        if(ar%mw==0){
            ll h=ar/mw;
            ll w=mw;
            
            ll chk[n];
            memset(chk,0,sizeof(chk));

            ll i=0,j=0;
            while(h>0 && w>0){
                if(i==n || j==n) break;
                if(p[i].first!=h && q[j].first!=w) break;
                if(p[i].first!=h){
                    h-=q[j].second.first;
                    chk[q[j].second.second]=1;

                    while(i<n && chk[p[i].second.second]) i++;
                    while(j<n && chk[q[j].second.second]) j++;
                }
                else if(q[j].first!=w){
                    w-=p[i].second.first;
                    chk[p[i].second.second]=1;

                    while(i<n && chk[p[i].second.second]) i++;
                    while(j<n && chk[q[j].second.second]) j++;
                }
                else{
                    h-=q[j].second.first;
                    w-=p[i].second.first;
                    chk[p[i].second.second]=1;
                    chk[q[j].second.second]=1;

                    while(i<n && chk[p[i].second.second]) i++;
                    while(j<n && chk[q[j].second.second]) j++;
                }
            }

            if(!h && !w) ans.insert({ar/mw,mw});
        }
        printf("%lli\n",(ll)ans.size());
        for(auto x: ans){
            printf("%lli %lli\n",x.first,x.second);
        }
    }

    return 0;
}