#include<bits/stdc++.h>
using namespace std;


// used for swapping i and j element of array
void swap(vector<int> &arr, int i, int j) {
    cout << "Swapping " << arr[i] << " and " << arr[j] << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(vector<int> &arr,int pivot,int lo,int hi){
    // 0 to j-1 <=pivot
    // j to i-1  >pivot
    // i to end  unknown status
    cout<<"pivot -> "<<pivot<<endl;
    int i=lo,j=lo;
    while(i<=hi){
        if(arr[i]>pivot){
            i++;
        } else {
            swap(arr,i,j);
            i++;
            j++;
        }
    }
    
    cout<<"pivot index -> "<<(j-1)<<endl;
    return (j-1);
}

int quickSelect(vector<int> arr,int lo, int hi, int k){
    int pivot=arr[hi];
    int pi=partition(arr, pivot, lo, hi);
    
    if(k>pi){
        return quickSelect(arr,pi+1,hi,k);
    } else if(k<pi){
        return quickSelect(arr,lo,pi-1,k);
    } else {
        return arr[pi];
    }
}


int main(){
    
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    
    cout<<quickSelect(arr,0,arr.size()-1,k-1);
    
    return 0;
}