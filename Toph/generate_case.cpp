#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll randval(ll beg,ll len){
    unsigned seed1 = chrono::system_clock::now().time_since_epoch().count();
    mt19937 generator(seed1);
	uniform_int_distribution<ll> distribution(beg, len);

    return distribution(generator);
}

int main()
{
    ll n=1000,sum=0,len=0;
    freopen("input.txt","w",stdout);

    cout<<n<<endl;
    for(ll i=0;i<n;i++){
        ll ran=100000-n+i+1;
        ran-=sum;
        ll x=randval(1,min(ran,100LL)),mx=0;
        cout<<x<<endl;
        len+=x;
        for(ll j=0;j<x;j++){
            ll val=randval(1,min(1000LL,ran));
            mx=max(val,mx);
            ll cnt=randval(1,1000);
            cout<<val<<" "<<cnt<<endl;
        }
        sum+=mx;
    }
    fclose(stdout);
    //cout<<len<<endl;

    return 0;
}