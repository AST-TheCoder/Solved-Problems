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

double pi=2.0*acos(0.0);

void fft(vector<complex<double>>& x,ll beg,ll gap,ll inv){
    if(gap>=x.size()) return;

    fft(x,beg,gap*2,inv);
    fft(x,beg+gap,gap*2,inv);

    complex<double> omega=exp(complex<double>(0,2.0*pi*(double)gap/(double)x.size())),w=1;
    if(inv) omega=complex<double>(1,0)/omega;

    vector<complex<double>> temp;
    for(ll i=beg,j=beg,k=beg+x.size()/2;i<x.size();i+=2*gap,j+=gap,k+=gap){
        complex<double> val=w*x[i+gap];
        temp.pb(x[i]+val);
        temp.pb(x[i]-val);
        w*=omega;
    }
    for(ll i=beg,j=0;j<temp.size();i+=gap,j+=2){
        x[i]=temp[j];
        x[i+x.size()/2]=temp[j+1];
    }
    temp.clear();
    return;
}

vector<ll> multiply(vector<ll>& x, vector<ll>& y){
    ll n=x.size(),m=y.size();
    ll deg=m+n-1,sz=1;
    while(sz<deg) sz*=2;

    vector<complex<double>> p,q,temp;
    for(ll i=0;i<sz;i++){
        if(i<n) p.pb(complex<double>(x[i],0));
        else p.pb(complex<double>(0,0));
        
        if(i<m) q.pb(complex<double>(y[i],0));
        else q.pb(complex<double>(0,0));
    }
    fft(p,0,1,0);
    fft(q,0,1,0);
    for(ll i=0;i<sz;i++){
        temp.pb(p[i]*q[i]);
    }
    fft(temp,0,1,1);

    vector<ll> ans;
    for(ll i=0;i<deg;i++){
        temp[i]/=(double)sz;
        ans.pb(real(temp[i])+0.5);
    }
    return ans;

}

int main()
{
    ll t;
    scanf("%lli",&t);

    while(t--){
        vector<ll> x,y;
        ll n;
        scanf("%lli",&n);
        for(ll i=0;i<=n;i++){
            ll temp;
            scanf("%lli",&temp);
            x.pb(temp);
        }

        for(ll i=0;i<=n;i++){
            ll temp;
            scanf("%lli",&temp);
            y.pb(temp);
        }

        reverse(all(x));
        reverse(all(y));

        vector<ll> ans = multiply(x,y);
        reverse(all(ans));
        for(ll i=0;i<ans.size();i++) printf("%lli ",ans[i]);
        printf("\n");
    }

    return 0;
}