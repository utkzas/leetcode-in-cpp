#include<bits/stdc++.h>
using namespace std;


// used for swapping i and j element of array
void swap(vector<int> &arr, int i, int j) {
    cout << "Swapping " << arr[i] << " and " << arr[j] << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


void countSort(vector<int> & arr, int minn, int maxx){
    int range=maxx-minn+1;
    vector<int> freq(range);
    
    //to update frequencies of elements in freq arr
    for(int i=0;i<arr.size();i++){
        int index=arr[i]-minn;
        freq[index]++;
    }
    
    //to make freq arr, a cumulative freq arr
    for(int i=1;i<freq.size();i++){
        freq[i]=freq[i]+freq[i-1];
    }
    
    int answ[arr.size()]={0};
    
    // iterate over the main arr
    // find index at which element freq is present
    // now reduce that freq
    for(int i=arr.size()-1;i>=0;i--){
        int val=arr[i];
        int pos=freq[val-minn];
        int index=pos-1;
        answ[index]=val;
        freq[val-minn]--;
        
    }
    
    for(int i=0;i<arr.size();i++)
    arr[i]=answ[i];
}

int main(){
    
    int n;
    cin>>n;
    vector<int> arr(n);
    int maxx=INT_MIN;
    int minn=INT_MAX;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        maxx=max(arr[i],maxx);
        minn=min(arr[i],minn);
    }
    
    
    countSort(arr,minn,maxx);
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}