#include<iostream>

#include<vector>

using namespace std;

void floodfill(vector<vector<int>> maze, int row, int col,vector<vector<bool>> visited, string psf) {
 //base case

 if(row==maze.size()-1 && col==maze[0].size()-1){ //destination reached
     cout<<psf<<endl; 
     return;
 }
 
 if(row<0 || col<0 || row>=maze.size() || col>=maze[0].size()|| maze[row][col] == 1 || visited[row][col]==true ){
        return;
 }

 
 visited[row][col]=true;
 
 floodfill(maze,row-1,col,visited,psf+"t"); //top
 floodfill(maze,row,col-1,visited,psf+"l"); //left
 floodfill(maze,row+1,col,visited,psf+"d"); //bottom
 floodfill(maze,row,col+1,visited,psf+"r"); //right
 
 visited[row][col]=false; // jab poora circle ghoom lia aur tab bhi destination me nahi fasa toh wapis jao
}

int main() {
    int n, m;
    cin >> n >> m;
    vector < vector < int >> arr(n, vector < int > (m));
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    vector <vector<bool>> visited (n,vector<bool> (m));
    floodfill(arr, 0,0,visited,"");
    
}




