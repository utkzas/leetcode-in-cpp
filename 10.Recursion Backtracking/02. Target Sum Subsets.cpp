#include<bits/stdc++.h>
using namespace std;
 // sos== sum of subsets
 // set holds the elements
void printTargetSumSubsets(vector<int>arr, int idx,string set, int sos, int tar){
    
    if(sos>tar)
    return;
    
    if(idx==arr.size()){
        if(sos==tar) cout<<set<<"."<<endl;
        
        return;
    }
    string s=to_string(arr[idx]);
    printTargetSumSubsets(arr,idx+1,set+s+", ", sos+arr[idx], tar);

    printTargetSumSubsets(arr,idx+1,set, sos, tar);
}

int main() {
    int n,tar;
    cin>>n;
    vector<int> arr (n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>tar;
    
    printTargetSumSubsets(arr,0,"",0,tar);
	return 0;
}