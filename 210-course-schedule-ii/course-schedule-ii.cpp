class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> ind(numCourses, 0);
        vector<int> ans;
        for (auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
            ind[edge[0]]++;
        }
        queue<int> q;
        int count = 0;
        for(int i=0; i<numCourses; i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            count++;
            ans.push_back(curr);
            for(int it : adj[curr]){
                ind[it]--;
                if(ind[it]==0){
                    q.push(it);
                }
            }
        }
        if(count==numCourses) return ans;
        return {};
    }
};