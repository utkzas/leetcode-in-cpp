#include <iostream>
#include<vector>
using namespace std;

int climbStairsWithVariableJumps(vector<int> arr, int i, vector<int>qb){
    // memoisation
   if(i==arr.size()){
       qb[i]=1;
       return qb[i];
   }
   
   if(qb[i]!=-1){
       return qb[i];
   }
   int count=0;
   
   for(int step=1; step<=arr[i];step++){
       if(i+step<=arr.size()){
           count=count+climbStairsWithVariableJumps(arr,i+step,qb);
       }
   }
   qb[i]=count;
   return qb[i];

}

int main(){
    int n;
    cin>>n;
    
    vector<int> arr(n);
    vector<int> qb(n+1,-1);
    
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }
    
    cout<<climbStairsWithVariableJumps(arr,0,qb)<<endl;
}