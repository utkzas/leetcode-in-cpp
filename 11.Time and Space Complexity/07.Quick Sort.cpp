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
void quickSort(vector<int> &arr, int lo, int hi){
    if(lo>hi){
        return;
    }
    
    int pivot=arr[hi];
    int pi=partition(arr,pivot,lo,hi);
    quickSort(arr,lo,pi-1);
    quickSort(arr,pi+1,hi);
    
}
int main(){
    
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int pivot;
    cin>>pivot;
    
    quickSort(arr,0,n-1);
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}






