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

void sort012(vector<int> &arr)
{
  // 0 to k-1 zero
  // k to j-1 one
  // i to k unknown
  // k+1 to end twos
  int i=0,j=0,k=arr.size()-1;
  
  while(i<=k){
      if(arr[i]==0){
         
         swap(arr,i,j);
          i++; 
          j++;
      } else if(arr[i]==1){
         i++; 
      } else {
          swap(arr,i,k);
          k--;
          
      }
  }
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> A(n, 0);
    input(A);

    sort012(A);
    print(A);
    return 0;
}