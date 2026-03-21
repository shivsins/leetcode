class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {    
        int ans=0;
        int n = isConnected.size();
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(isConnected, i, vis,n);
                ans++;
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& isConnected, int curr, vector<int> &vis, int n){
        vis[curr]=1;
        for(int i=0;i<n;i++){
            if(isConnected[curr][i]==1 && i!=curr){
                if(!vis[i]){
                    dfs(isConnected, i, vis, n);
                }
            }
        }
    }
};