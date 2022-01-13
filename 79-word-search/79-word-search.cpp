class Solution {
public:
   
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int n){
        if(n==word.size()) return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[n])
            return false;
        
        //mark as visited
        board[i][j]='0';
        
        //mark as visited 
        board[i][j] = '0';
        
		//branch out in all 4 directions
        bool status = dfs(board, word, i + 1, j, n + 1) ||  //down
                        dfs(board, word, i, j + 1, n + 1) ||  //right
                        dfs(board, word, i - 1, j, n + 1) ||  //up
                        dfs(board, word, i, j - 1, n + 1);  //left
        //revert back the char for subsequent searches
        board[i][j] = word[n];
        
        return status;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word=="") return false;
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
    		//check if the characters are equal then call DFS
                if(board[i][j] == word[0] && dfs(board, word, i, j, 0))
                return true;
                
            }
        }
        return false;
    }
};