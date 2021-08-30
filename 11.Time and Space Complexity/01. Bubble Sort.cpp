#include<bits/stdc++.h>
using namespace std;

// used for swapping i and j element of array
void swap(vector<int> &arr, int i, int j) {
    cout << "Swapping " << arr[i] << " and " << arr[j] << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

//return true if ith element is smaller than jth element
//comparing if peeche wala is greater, agr hai toh respect dekar usko aage bulao
bool isSmaller(vector<int> & arr,int i, int j){
    cout<<"Comparing "<<arr[i]<<" and "<<arr[j]<<endl;
    if(arr[i] < arr[j]) return true;
    else return false;
}
 
void print(vector<int>& arr){
    for(auto x: arr){
        cout<<x<<endl;
    }
}

void bubbleSort(vector<int>& arr){
    for(int i=1;i<arr.size();i++){
        for(int j=0;j<arr.size()-i;j++){ // arr.size-i is the unsorted subarray
            if(isSmaller(arr,j+1,j)){ 
                swap(arr,j+1,j);
            }
        }
        
    }
}

int main(){
   int n;
   cin>>n;
   vector<int> arr(n);
   for(int i=0;i<n;i++)
   cin>>arr[i];
   
   bubbleSort(arr);
   
   print(arr);
   return 0; 
}