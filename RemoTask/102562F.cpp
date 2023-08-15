#include <bits/stdc++.h>

using namespace std;

int n;
string corr,temp;
vector< set< int > > mins;
char c;

int main()
{
    cin>>corr>>n;
    for(int i=0; i<n; i++){
        cin>>temp>>c;
        if(c=='+')continue;
        set<int> t;
        for(int i=0; i<temp.size(); i++){
            if(temp[i]!=corr[i]){
                t.insert(i+1);
            }
        }
        if(t.size()==3){
			mins.push_back(t);
			cout<<i<<endl;
		}
    }
    for(auto i : mins){
        for(auto j : mins){
            set<int> t;
            for(auto k : i)t.insert(k);
            for(auto k : j)t.insert(k);
            if(t.size()==6){
                cout<<"Yes\n";
                return 0;
            }

        }
    }
    cout<<"No\n";
    return 0;
}
