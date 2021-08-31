#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeTwoSortedArrays(vector<int> &A, vector<int> &B)
{
    int i = 0, j = 0;
    vector<int> answ;
    while (i < A.size() && j < B.size())
    {
        if (A[i] < B[j])
        {
            answ.push_back(A[i]);
            i++;
        }
        else if (A[i] == B[j])
        { //boundary
            answ.push_back(A[i]);
            answ.push_back(B[j]);
            i++;
            j++;
        }
        else
        {
            answ.push_back(B[j]);
            j++;
        }
    }

    while (i < A.size())
    {
        answ.push_back(A[i]);
        i++;
    }

    while (i < B.size())
    {
        answ.push_back(B[j]);
        j++;
    }

    return answ;
}

void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

void output(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> A(n, 0);
    input(A);

    cin >> m;
    vector<int> B(m, 0);
    input(B);

    vector<int> ans = mergeTwoSortedArrays(A, B);
    output(ans);
    return 0;
}
