#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
#define      ll                  long long
#define      FastIO     ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
constexpr ll MOD = 998244353;
constexpr ll mod = 1e9  + 7;
 
const ll N=2e5+5;
 
/*
 * Outputs random number between 1 and 10^6, inclusive.
 * To generate different values, call "igen.exe" with different parameters.
 * For example, "igen.exe 1" returns 504077, but "igen.exe 3" returns 808747.
 *
 * It is typical behaviour of testlib generator to setup randseed by command line.
 */
 
 
int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n=rnd.next(1,100000);
    cout<<n<<endl;
    vector<int> v;
    for(ll i=1;i<=n;i++){
      v.push_back(rnd.next(1,100000));
    }
    for (int i = 1; i <=n; i++){
      cout << v[i];
      if(i!=n) cout<<" ";
      else cout<<endl;
    }
 
    return 0;
}
