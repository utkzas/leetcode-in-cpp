#include<iostream>
#include<vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
 if(sr==dr && sc==dc)
 {
     vector<string> ans;
     ans.push_back("");
     return ans;
 }

 
 vector<string> paths;
 //horizontal
 for(int ms=1;ms<=dc-sc;ms++)
 {
     vector<string>hpaths=getMazePaths(sr,sc+ms,dr,dc);
     for(string hpath:hpaths)
     {
         paths.push_back("h"+(to_string)(ms)+hpath);
     }
 }
 //vertical
 for(int ms=1;ms<=dr-sr;ms++)
 {
     vector<string>vpaths=getMazePaths(sr+ms,sc,dr,dc);
     for(string vpath:vpaths)
     {
         paths.push_back("v"+(to_string)(ms)+vpath);
     }
 }
 //diagonal
 for(int ms=1;ms<=dc-sc;ms++)
 {
     vector<string>dpaths=getMazePaths(sr+ms,sc+ms,dr,dc);
     for(string dpath:dpaths)
     {
         paths.push_back("d"+(to_string)(ms)+dpath);
     }
 }
 return paths;
}

void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}


int main() {
    int n,m; cin >> n >> m;
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);

    return 0;
}