class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> ind(numCourses, 0);
        for(vector<int> edge : prerequisites){
            adj[edge[1]].push_back(edge[0]);
            ind[edge[0]]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        int count = 0;
        vector<int> vis(numCourses, 0);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            count++;
            vis[curr]=1;
            for(int node : adj[curr]){
                if(vis[node]==0){
                    if(--ind[node]==0){
                        q.push(node);
                    }
                }
            }
        }
        return count==numCourses;
    }
};