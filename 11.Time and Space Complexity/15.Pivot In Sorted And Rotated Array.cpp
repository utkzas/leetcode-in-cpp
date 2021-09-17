#include<bits/stdc++.h>
using namespace std;

int findSmallest(vector<int> &arr, int n){
    int lo=0;
    int hi=n-1;
    
    while(lo<hi){
        int mid=(lo+hi)/2;
        if(arr[mid]<arr[hi]){
            hi=mid;
        } else {
           lo=mid+1;
        }
    }
    return arr[hi];
}

int main(){
    int n;
    cin>>n;
    vector<int> arr (n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
 
    
    
    cout<<findSmallest(arr,n);
    return 0;
}