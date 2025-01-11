class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int pro = 0;
        vector<int> vis(n,0);
        for(int i=0; i<n;i++){
            if(!vis[i]){
                pro++;
                dfs(isConnected, vis, i, n);
            }
        }
        return pro;
    }

    void dfs(vector<vector<int>>& isConnected, vector<int> &vis, int tar, int n){
        for(int j=0;j<n;j++){
            if(tar!=j &&  isConnected[tar][j]==1 && !vis[j]){
                vis[j]=1;
                dfs(isConnected, vis, j,n);
            }
        }
        return;
    }
};