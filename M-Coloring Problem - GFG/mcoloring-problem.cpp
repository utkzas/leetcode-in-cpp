// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.

bool solve(int sv, bool graph[101][101], int V, vector<int>& visited, int colors) {
    unordered_map<int, int> visitedColors;
    for(int i = 0; i < V; i++) {
        if(graph[sv][i] == true && visited[i] != -1) visitedColors[visited[i]] = 1;
    }
    if(visitedColors.size() == colors) return false;
    for(int i = 0; i < colors; i++) {
        if(visitedColors[i] > 0) continue;
        visited[sv] = i;
        bool isAll = true;
        int j = 0;
        for(j = 0; j < V; j++) {
            if(graph[sv][j] == true && visited[j] == -1) {
                if(solve(j, graph, V, visited, colors) == false) break;
            }
        }
        if(j == V) return true;
    }
    visited[sv] = -1;
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V) {
    vector<int> visited(V, -1);
    for(int i = 0; i < V; i++) {
        if(visited[i] == -1) {
            if(solve(i, graph, V, visited, m) == false) return false;
        }
    }
    return true;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends