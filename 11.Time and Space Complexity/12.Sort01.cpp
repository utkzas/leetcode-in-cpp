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



void sort01(vector<int>&arr){
    // 0 to j-1 zero
    // j to i-1 ones
    // i to end unknown
    int i=0;
    int j=0;
    while(i<arr.size()){
        if(arr[i]==1){
            i++;
        } else {
            swap(arr,i,j);
            j++;
            i++;
        }
    }
}

 
int main()
{
    int n, m;
    cin >> n;
    vector<int> A(n, 0);
    input(A);

    sort01(A);
    print(A);
    return 0;
}