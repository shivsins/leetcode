#include <vector>
using namespace std;

class Solution {
public:
    // bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
    //     if (visited[node] == 1) return true; 
    //     if (visited[node] == 2) return false; 
        
    //     visited[node] = 1;
    //     for (int neighbor : adj[node]) {
    //         if (dfs(neighbor, adj, visited)) {
    //             return true;
    //         }
    //     }
    //     visited[node] = 2;
    //     return false;
    // }
    
   bool canFinish(int N, vector<vector<int>>& arr) {
        vector<vector<int>> adj(N);
        vector<int> ind(N, 0);
        for (auto& edge : arr) {
            adj[edge[1]].push_back(edge[0]);
            ind[edge[0]]++;
        }
        queue<int> q;
        int count = 0;
        for(int i=0; i<N; i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            count++;
            for(int it : adj[curr]){
                ind[it]--;
                if(ind[it]==0){
                    q.push(it);
                }
            }
        }
        if(count==N) return true;
        return false;
        
        // vector<int> visited(N, 0);
        // for (int i = 0; i < N; i++) {
        //     if (visited[i] == 0 && dfs(i, adj, visited)) {
        //         return false; 
        //     }
        // }
        // return true ; 
    }
};