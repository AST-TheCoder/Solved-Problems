#include<iostream>
using namespace std;

// template<class T>
// void q1(T arr[],int siz, int cnt){
//     if(cnt>=siz) return;
//     if(cnt==0) arr[cnt]=7;
//     else arr[cnt]=3*arr[cnt-1]/8;
//     q1(arr,siz,cnt+1);
// }

int q2(int arr[], int siz, int n, int idx){
    if(idx>=siz || arr[idx]>=n) return 0;
    int ans = arr[idx] + q2(arr, siz, n, idx + 1);
}

// 1 3 8 13 19
// n = 11
// size = 5

int main()
{
    // double arr[20];
    // q1(arr,20,0);
    // for(int i=0;i<20;i++) cout<<arr[i]<<" ";
    // cout<<endl;

    int a[10];
    for(int i=0;i<10;i++) cin>>a[i];
    int n;
    cin>>n;

    int ans = q2(a, 10, n, 0);
    cout<<ans<<endl;


}