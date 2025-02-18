#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        if (visited[node] == 1) return true; 
        if (visited[node] == 2) return false; 
        
        visited[node] = 1;
        for (int neighbor : adj[node]) {
            if (dfs(neighbor, adj, visited)) {
                return true;
            }
        }
        visited[node] = 2;
        return false;
    }
    
   bool canFinish(int N, vector<vector<int>>& arr) {
        vector<vector<int>> adj(N);
        for (auto& edge : arr) {
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> visited(N, 0);
        for (int i = 0; i < N; i++) {
            if (visited[i] == 0 && dfs(i, adj, visited)) {
                return false; 
            }
        }
        return true ; 
    }
};