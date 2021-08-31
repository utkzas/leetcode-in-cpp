#include<bits/stdc++.h>
using namespace std;

// used for swapping i and j element of array
void swap(vector<int> &arr, int i, int j) {
    cout << "Swapping " << arr[i] << " and " << arr[j] << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

//return true if ith element is greater than jth element
//comparing if pehle wala is greater, agr hai toh respect dekar usko aage rakho
bool isGreater(vector<int> & arr,int i, int j){
    cout<<"Comparing "<<arr[j]<<" and "<<arr[i]<<endl;
    if(arr[i] > arr[j]) return true;
    else return false;
}
 
void print(vector<int>& arr){
    for(auto x: arr){
        cout<<x<<endl;
    }
}

void insertionSort(vector<int>& arr){
    
    for(int i=1;i<arr.size();i++){
        for(int j=i-1;j>=0;j--){ //reverse bubble sort bhi keh skte hain isko: i ko compare krna start karo sorted subarray ke andar se
            if(isGreater(arr,j,j+1)){
                swap(arr,j,j+1);
            } else {
                break;
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
   
   insertionSort(arr);
   
   print(arr);
   return 0; 
}