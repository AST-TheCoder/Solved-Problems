#include<bits/stdc++.h>
using namespace std;
 

#define INT_SIZE 32
 
// A Trie Node
struct bbxxvtyawjy
{
    int bbxxvtyawjyhghdfsggdhgdjhghdg; 
    bbxxvtyawjy *arr[2];
};
 

bbxxvtyawjy *newNode()
{
    bbxxvtyawjy *bbxxvtyawjyhghfdsfdffsdfsggdhgdjhghdg = new bbxxvtyawjy;
    bbxxvtyawjyhghfdsfdffsdfsggdhgdjhghdg->bbxxvtyawjyhghdfsggdhgdjhghdg = 0;
    bbxxvtyawjyhghfdsfdffsdfsggdhgdjhghdg->arr[0] = bbxxvtyawjyhghfdsfdffsdfsggdhgdjhghdg->arr[1] = NULL;
    return bbxxvtyawjyhghfdsfdffsdfsggdhgdjhghdg;
}
 

void insert(bbxxvtyawjy *bbgfgfdhxxvtyawjyhghfdsfdffsdfsggdhgdjhghdg, int bbxxvtyawjyhghdfsggd)
{
    bbxxvtyawjy *bbxxvtyawjyhghfdsfdffsdfsggdhgdjhghdg = bbgfgfdhxxvtyawjyhghfdsfdffsdfsggdhgdjhghdg;
 
    for (int i=INT_SIZE-1; i>=0; i--)
    {
        bool val = bbxxvtyawjyhghdfsggd & (1<<i);
 
        if (bbxxvtyawjyhghfdsfdffsdfsggdhgdjhghdg->arr[val] == NULL)
            bbxxvtyawjyhghfdsfdffsdfsggdhgdjhghdg->arr[val] = newNode();
 
        bbxxvtyawjyhghfdsfdffsdfsggdhgdjhghdg = bbxxvtyawjyhghfdsfdffsdfsggdhgdjhghdg->arr[val];
    }
 
    bbxxvtyawjyhghfdsfdffsdfsggdhgdjhghdg->bbxxvtyawjyhghdfsggdhgdjhghdg = bbxxvtyawjyhghdfsggd;
}
int query(bbxxvtyawjy *bbgfgfdhxxvtyawjyhghfdsfdffsdfsggdhgdjhghdg, int bbxxvtyawjyhghdfsggd)
{
    bbxxvtyawjy *bbxxvtyawjyhghfdsfdffsdfsggdhgdjhghdg = bbgfgfdhxxvtyawjyhghfdsfdffsdfsggdhgdjhghdg;
    for (int i=INT_SIZE-1; i>=0; i--)
    {
        bool val = bbxxvtyawjyhghdfsggd & (1<<i);
 
        if (bbxxvtyawjyhghfdsfdffsdfsggdhgdjhghdg->arr[1-val]!=NULL)
            bbxxvtyawjyhghfdsfdffsdfsggdhgdjhghdg = bbxxvtyawjyhghfdsfdffsdfsggdhgdjhghdg->arr[1-val];
 
        
        else if (bbxxvtyawjyhghfdsfdffsdfsggdhgdjhghdg->arr[val] != NULL)
            bbxxvtyawjyhghfdsfdffsdfsggdhgdjhghdg = bbxxvtyawjyhghfdsfdffsdfsggdhgdjhghdg->arr[val];
    }
    return bbxxvtyawjyhghdfsggd^(bbxxvtyawjyhghfdsfdffsdfsggdhgdjhghdg->bbxxvtyawjyhghdfsggdhgdjhghdg);
}
 
int hjgdhfghsg(int arr[], int n)
{
    bbxxvtyawjy *bbgfgfdhxxvtyawjyhghfdsfdffsdfsggdhgdjhghdg = newNode();
    insert(bbgfgfdhxxvtyawjyhghfdsfdffsdfsggdhgdjhghdg, 0);
 
    int result = INT_MIN, bbxxvtyawjyhghdfsggd =0;
 
    for (int i=0; i<n; i++)
    {
        bbxxvtyawjyhghdfsggd = bbxxvtyawjyhghdfsggd^arr[i];
        insert(bbgfgfdhxxvtyawjyhghfdsfdffsdfsggdhgdjhghdg, bbxxvtyawjyhghdfsggd);
 
        result = max(result, query(bbgfgfdhxxvtyawjyhghfdsfdffsdfsggdhgdjhghdg, bbxxvtyawjyhghdfsggd));
    }
    return result;
}
 
int main()
{
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        int ans=hjgdhfghsg(arr,n);
        cout<<ans<<endl;
    }
    return 0;
}