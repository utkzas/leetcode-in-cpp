#include<bits/stdc++.h>
using namespace std;

//function to display 2d array
void displayBoard(vector<vector<int>> &chess,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<chess[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
//move is no. of moves taken (which are max n*n)
void printKnightsTour(vector<vector<int>> &chess, int n,int r, int c, int move){
    if(r<0 || c<0 || c>=n || r>=n || chess[r][c]!=0)
    return;
    if (move==n*n) {
        chess[r][c]=move;
        displayBoard(chess,n);
        chess[r][c]=0;
        return;    
    }
    
    
    chess[r][c]=move;
    printKnightsTour(chess,n,r-2,c+1,move+1);
    printKnightsTour(chess,n,r-1,c+2,move+1);
    printKnightsTour(chess,n,r+1,c+2,move+1);
    printKnightsTour(chess,n,r+2,c+1,move+1);
    printKnightsTour(chess,n,r+2,c-1,move+1);
    printKnightsTour(chess,n,r+1,c-2,move+1);
    printKnightsTour(chess,n,r-1,c-2,move+1);
    printKnightsTour(chess,n,r-2,c-1,move+1);
    chess[r][c]=0;
}

int main(){
    int n,r,c;
    cin>>n>>r>>c;
    vector<vector<int>> kt(n, vector <int> (n,0));
    printKnightsTour(kt,n,r,c,1);
}





