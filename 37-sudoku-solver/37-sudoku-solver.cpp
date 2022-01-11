class Solution {
public:
    bool isValid(vector<vector<char>>& board,int x,int y,char po){
    for(int j=0;j<board.size();j++){ // check if val present in any of our column
        if(board[x][j]==po){
            return false;
        }
    }
    for(int i=0;i<board.size();i++){
        if(board[i][y]==po){
            return false;
        }
    }
    int sub_i = x/3 * 3; // top left corner of the sub-matrix
    int sub_j = y/3 * 3; // top left corner of the sub-matrix
    for(int i=0;i<3;i++){ // checking in whole sub matrix for the possible option
        for(int j=0;j<3;j++){
            if(board[sub_i+i][sub_j+j]==po){
                return false;
            }
        }
    }
    return true;
}
    bool solveSudokuH(vector<vector<char>>& board, int i=0, int j=0) {
     if (i == 9){
      return true;
    }
        int ni=0,nj=0; // next i and next j
        if(j==9){ // if it is at extreme right column
            ni=i+1;
            nj=0;
        } else {
            ni=i;
            nj=j+1;
        }
        //cout<<board[i][j];
        if(board[i][j]!='.')
        {
            return solveSudokuH(board,ni,nj);
        }else {
            for(char po='1';po<='9';po++){
                //cout<<"yo";
                if(isValid(board,i,j,po)){    
                    board[i][j]=po;
                   // without return here, the board reverts to initial state
                    if(solveSudokuH(board,ni,nj))
                        return true;
                    board[i][j]='.';
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board, int i=0, int j=0) {
    solveSudokuH(board,i,j);
    }
    
};