#include "testlib.h"
#include <iostream>
#include <random>
using namespace std;
 
#define      ll                  long long
#define pb push_back
#define      FastIO     ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
constexpr ll MOD = 998244353;
constexpr ll mod = 1e9  + 7;
 
const ll N = 2e5 + 5;
 
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
 
    //int t_l=5,t_r=5;
 
    int t = 2;
 
    cout<< t <<'\n';
 
    for(ll tt=0;tt<t;tt++){
 
 
        //int n_l= 4,n_r=4;
     
        int n = 100000;
        cout<<n<<'\n';
        string s;
        for(int i=0;i<10000;i++) s+='B';
        for(int i=0;i<80000;i++) s+='U';
        for(int i=0;i<10000;i++) s+='B';
        cout<<s<<'\n';
    }
    
 
    return 0;
}
