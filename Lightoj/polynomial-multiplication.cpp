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

ll rev_bit(ll val,ll log_2){
    ll res=0;
    for(ll i=0;i<log_2;i++){
        if(val&(1<<i)){
            ll pos=log_2-i-1;
            res|=(1<<pos);
        }
    }
    return res;
}

void fft(vector<complex<double>>& x,ll inv){

    ll log_2=round(log2(x.size()));
    for(ll i=0;i<x.size();i++){
        ll rev=rev_bit(i,log_2);
        if(i<rev) swap(x[i],x[rev]);
    }


    for(ll i=2;i<=x.size();i*=2){
        complex<double> omega=exp(complex<double>(0,2.0*pi/(double)i));
        if(inv) omega=complex<double>(1,0)/omega;
        for(ll j=0;j<x.size();j+=i){
            complex<double> w=1;
            for(ll k=j;k<j+i/2;k++){
                complex<double> p=x[k],q=x[k+i/2]*w;
                x[k]=p+q;
                x[k+i/2]=p-q;
                w*=omega;
            }
        }
    }
    return;
}

vector<ll> multiply(vector<ll>& x, vector<ll>& y){
    ll n=x.size(),m=y.size();
    ll deg=m+n-1,sz=1;
    while(sz<deg) sz*=2;

    vector<complex<double>> p,q,temp;
    for(ll i=0;i<sz;i++){
        if(i<n) p.pb(complex<double>((double)x[i],0.0));
        else p.pb(complex<double>(0.0,0.0));
        
        if(i<m) q.pb(complex<double>((double)y[i],0.0));
        else q.pb(complex<double>(0.0,0.0));
    }
    fft(p,0);
    fft(q,0);
    for(ll i=0;i<sz;i++){
        temp.pb(p[i]*q[i]);
    }
    fft(temp,1);

    vector<ll> ans;
    for(ll i=0;i<deg;i++){
        double val=temp[i].real()/(double)sz;
        ans.pb(round(val));
    }
    return ans;

}

int main()
{
    ll t,ii=0;
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

        ll m;
        scanf("%lli",&m);
        for(ll i=0;i<=m;i++){
            ll temp;
            scanf("%lli",&temp);
            y.pb(temp);
        }

        vector<ll> ans = multiply(x,y);
        while(ans.size()>1 && ans[ans.size()-1]==0) ans.pop_back();
        printf("Case %lli: %lli",++ii,(ll)ans.size()-1);
        for(ll i=0;i<ans.size();i++) printf(" %lli",ans[i]);
        printf("\n");
    }

    return 0;
}