#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    vector<int> arr(n);
    vector<int> qb(n+1,0);
    
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }
    //tabulation
    
    qb[n]=0;
    for(int i=n-1;i>=0;i--){
        int minn=INT_MAX;
        
        if(arr[i]>0){
            for(int j=1;j<=arr[i] && i+j<=n;j++){ 
                minn=min(minn,qb[i+j]);
            }
        }
        
        if(minn== INT_MAX){
            qb[i]=minn;
        } else {
           
            int a=minn+1;
            qb[i]=a;
        }
        
    }
   if(qb[0]==INT_MAX)
   cout<<"null";
   else
   cout<<qb[0];
}