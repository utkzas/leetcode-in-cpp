#include <iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }
    
    // tabulation method
    vector<int> qb(n+1,0);
    
    qb[n]=1;
    
    for(int i=n-1;i>=0;i--){
        for(int j=1;j<=arr[i] && i+j<qb.size();j++){
            qb[i]+=qb[i+j];
        }
    }
    cout<<qb[0];
}










