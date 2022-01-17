// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    private:
    void solve(int x,int y,string s, vector<vector<int>> &arr, vector<string> &answ){
        int n=arr.size();
        
        // out of bounds and not possible path me jane se roklia
        if(x<0 || x>=n || y<0 || y>=n || arr[x][y]==0) 
        return;
        
        if(x==n-1 && y==n-1){ // pahunch gaye, yay!
            answ.push_back(s);  
            return;
        }
        int dx[] = {1,0,0,-1}, dy[]= {0,-1,1,0}; //types of moves D,L,R,U
        char ch[] = {'D','L','R','U'};////directions
        arr[x][y]=0; //idk isko 0 kyu mark kia
        for(int k=0;k<4;k++){
            solve(x+dx[k],y+dy[k],s+ch[k],arr,answ); //chaaron direction me bhej dia
        }
        arr[x][y]=1;
    }
    public:
    vector<string> findPath(vector<vector<int>> &arr, int n) {
        // Your code goes here
        vector<string> answ;
        solve(0,0,"",arr,answ);
        return answ;
    }
};


    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends