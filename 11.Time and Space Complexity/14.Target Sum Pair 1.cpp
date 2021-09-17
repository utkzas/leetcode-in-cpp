#include<bits/stdc++.h>
using namespace std;

int targetSumPair(vector<int>&arr, int target){
    sort(arr.begin(),arr.end());
    
    int li=0; //left index
    int ri=arr.size()-1; //right index
    while(li<ri){
        if(arr[li]+arr[ri]<target){ // ri is already max, li must be increased 
            li++;
        } else if(arr[li]+arr[ri]>target){ //li is already min, ri must be decreased 
            ri--;
        } else { //li==ri  matlab kaam hogya dono chalte bano
            cout<<arr[li]<<", "<<arr[ri]<<endl;
            li++;
            ri--;
        }
        //cout<<arr[li];
    }
    
    return 0;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr (n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int target;
    cin>>target;
    
    
    targetSumPair(arr,target);
    return 0;
}