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

void selectionSort(vector<int>& arr){
    
    for(int i=0;i<arr.size()-1;i++){
        int m=i;
        for(int j=i+1;j<arr.size();j++){
            if(isSmaller(arr,j,m)){
               m=j; 
            }
        } 
        swap(arr,i,m);
    }
}

int main(){
   int n;
   cin>>n;
   vector<int> arr(n);
   for(int i=0;i<n;i++)
   cin>>arr[i];
   
   selectionSort(arr);
   
   print(arr);
   return 0; 
}