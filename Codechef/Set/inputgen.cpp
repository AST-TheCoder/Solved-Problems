#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
#define min_heap priority_queue <ll, vector<ll>, greater<ll> >

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll t=20,i;

int main()
{
    ll val[]={a4,b10,c55,d134,e728,f1057,g4321,h8790,i10001,j13029,k31313,l49876,m82347,n100000,o145142,p154123,q267189,r317383,s498721,t500000};

    char s[20]="in/a.in";
    while(t--){
        freopen(s,"w",stdout);

        cout<<val[i]<<endl;

        fclose(stdout);
        s[3]++;
        i++;
    }

    return 0;
}