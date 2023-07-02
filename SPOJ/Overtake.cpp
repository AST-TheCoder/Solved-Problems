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

double lb,sb,db,lc,sc,dc,lt,st;
double solve(double lb, double sb, double db, double lc, double sc, double dc, double lt, double st){
    if(sb>=sc){
        double t=(db+lt)/(st-sb);
        if(t*sc+dc-t*st<lc) return (double)Max;
        
        return (dc+lt)/(st-sc);
    }
    double t=(dc-lc)/(st-sc);
    double temp=0.0;
    if(dc-lc-db<lt) temp=(lc+lt+db-dc)/(sc-sb);
    t=max(t,temp);
    t+=(lc+lt)/(st-sc);
    return t;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t,ii=0;
    cin>>t;

    while(t--){
        cin>>lb>>sb>>db>>lc>>sc>>dc>>lt>>st;
        cout<<"Case "<<++ii<<": ";
        if(st<=sb || st<=sc){
            cout<<-1<<"\n";
            continue;
        }
        if(sb==sc){
            if(dc>=db){
                if(dc-lc-db<lt){
                    cout<<-1<<"\n";
                    continue;
                }
            }
            else if(db-lb-dc<lt){
                cout<<-1<<"\n";
                continue;
            }
        }
        double ans=solve(lb,sb,db,lc,sc,dc,lt,st);
        ans=min(ans,solve(lc,sc,dc,lb,sb,db,lt,st));

        cout<<fixed<<setprecision(4)<<ans<<"\n";
    }

    return 0;
}