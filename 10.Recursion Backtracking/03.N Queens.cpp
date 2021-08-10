#include <iostream>
#include<vector>

using namespace std;

bool isSafeForQueen(vector<vector<int>> chess, int row, int col){
    //vertical check
    for(int i=row-1, j=col; i>=0;i--){
        if(chess[i][j]==1)
        return false;
    }
    
    //horizontal left check
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
        if(chess[i][j] == 1)
        return false;
    }
    
    // horizontal right check
    for(int i=row-1, j=col+1; i>=0 && j<=chess.size(); i--, j++){
        if(chess[i][j] == 1)
        return false;
    }
    
    //otherwise
    return true;
}

void printNQueens(vector<vector<int>> chess, string qsf, int row){
        if(row==chess.size()){
            cout<<qsf<<"."<<endl;
            return;
        }
        
        for(int col=0;col<chess.size();col++){
            if(isSafeForQueen(chess,row,col)){
            chess[row][col]=1;
            
            string r=to_string(row);
            string c=to_string(col);
            
            printNQueens(chess,qsf+r+"-"+c+", ",row+1);
            
            chess[row][col]=0;    
            }
            
        }
    }
    
    int main(){
        int n;
        cin>>n;
        vector<vector<int>> arr (n,vector<int> (n));
        printNQueens(arr,"",0);
        return 0;
    }