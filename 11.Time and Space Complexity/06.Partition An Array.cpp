#include<bits/stdc++.h>
using namespace std;

// used for swapping i and j element of array
void swap(vector<int> &arr, int i, int j) {
    cout << "Swapping " << arr[i] << " and " << arr[j] << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void partition(vector<int> &arr,int pivot){
    // 0 to j-1 <=pivot
    // j to i-1  >pivot
    // i to end  unknown status
    int i=0;
    int j=0;
    while(i<arr.size()){
        if(arr[i]>pivot){
            i++;
        } else {
            swap(arr,i,j);
            i++;
            j++;
        }
    }
    
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
    
    partition(arr,pivot);
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}