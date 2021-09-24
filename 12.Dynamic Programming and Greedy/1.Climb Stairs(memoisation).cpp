#include <iostream>
#include<vector>
using namespace std;

int countPaths(int n, vector<int> &qb){
    // memoisation
    if(n==0){
        return 1;
    } else if(n<0){
        return 0;
    }

    
    if(qb[n]!=-1)
    return qb[n];
        cout<<"Hello"<<n<<endl;
    int nm1=countPaths(n-1,qb); //n minus one
    int nm2=countPaths(n-2,qb); //n minus two
    int nm3=countPaths(n-3,qb); //n minus three
    int paths=nm1+nm2+nm3;
    
    qb[n]=paths;
    return paths;

}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n+1,-1);
    cout<<countPaths(n,arr)<<endl;
}