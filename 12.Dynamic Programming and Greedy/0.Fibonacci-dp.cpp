#include <iostream>
#include<vector>
using namespace std;


//memoization
int fib(int n,vector<int>&arr){
    
    if(n==0 || n==1){
        return n;
    }
    
    if(arr[n]!=-1){   //here, i applied dp concept
        return arr[n];
    }
    
    int f1=fib(n-1,arr);
    int f2=fib(n-2,arr);
    
    int new_fib = f1+f2;
    
    arr[n]=new_fib; //memoised the answer
    return new_fib;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n+1,-1);
    
    cout<<fib(n,arr)<<endl;
    return 0;
}