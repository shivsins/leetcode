class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;
        vector<vector<int>> dir = {{1,0},{-1,0}, {0,-1}, {0,1}, {-1,1}, {1,1}, {1,-1}, {-1,-1}};
        queue<vector<int>> q;
        q.push({0,0,1});
        vector<vector<int>> vis(n, vector<int>(n,0));
        vis[0][0]=1;
        while(!q.empty()){
            vector<int> curr = q.front();
            q.pop();
            if(curr[0]==n-1 && curr[1]==n-1){
                return curr[2];
            }
            for(vector<int> d:dir){
                int nx = curr[0]+d[0];
                int ny = curr[1]+d[1];
                if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0 && vis[nx][ny]==0){
                    vis[nx][ny]=1;
                    q.push({nx,ny,curr[2]+1});
                }
            }
        }
        return -1;
    }
};