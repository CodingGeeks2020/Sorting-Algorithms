#include <bits/stdc++.h>
#define ll long long int
#define line cout<<endl;
#define getarr(arr) for(auto &i:arr)cin>>i;
#define putarr(arr) for(auto &i:arr)cout<<i<<" ";
#define swap(x, y) do { typeof(x) SWAP = x; x = y; y = SWAP; } while (0);
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    getarr(arr);
    int max = INT_MIN;
    for(int i = 0;i<n;i++)
    {
        if(max<arr[i])
        max = arr[i];
    }
    int total[max+1];
    memset(total,0,sizeof(total));
    for(int i = 0;i<n;i++)
    {
        total[arr[i]]++;
    }
    int place = 0;
    for(int i = 0;i<max+1;i++)
    {
        while(total[i]--)
        {
            arr[place] = i;
            place++;
        }
    }
    putarr(arr);
    return 0;
}