#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

void solve(int n,int arr[], int x,int index)
{
    if(index==n)
    return;
    
    if(arr[index]==x)
    {   cout<<index<<endl;
        solve(n,arr,x,index+1);
    }
    else solve(n,arr,x,index+1);
    
}
int main() {
  
      int t;
      cin>>t;
      int arr[t];
      for(int i=0;i<t;i++)
      cin>>arr[i];
     int x;
     cin>>x;
     
solve(t,arr,x,0);     
  return 0;
}