// This soln doesn't parse int so this wont work in c++
// either use java or any other approach to do this question

#include <iostream>

#include <vector>

using namespace std;

void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
}

// used for swapping ith and jth elements of array
void swap(vector<int> &arr, int i, int j)
{
    cout << ("Swapping index " + to_string(i) + " and index " + to_string(j)) << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}



void countSort(vector<int>&arr,int divi, int mod, int range){
    vector<int> freq(range);
    vector<int> answ(arr.size());
    //to update frequencies of elements in freq arr
    for(int i=0;i<arr.size();i++){
        freq[arr[i]/divi%mod]++;
    }
    
    //to make freq arr, a cumulative freq arr
    for(int i=1;i<freq.size();i++){
        freq[i]=freq[i]+freq[i-1];
    }
    
    // stable sorting(filling answ arr)
    // iterate over the main arr
    // find index at which element freq is present
    // now reduce that freq
    for(int i=arr.size()-1;i>=0;i--){
        int pos=freq[arr[i]/divi%mod]-1;
        answ[pos]=arr[i];
        freq[((arr[i]))/divi%mod]--;
        
    }
    
    // filling original arr with answ arr
    for(int i=0;i<arr.size();i++)
    arr[i]=answ[i];
    
   
  
}

void sortDates(vector<int> &arr)
{
  countSort(arr,1000000,100,32); //days
  countSort(arr,10000,100,13); //months
  countSort(arr,1,10000,2501); //years
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> A(n, 0);
    input(A);

    sortDates(A);
    print(A);
    return 0;
}