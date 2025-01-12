class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        set<pair<int,int>> vis;
        for(int i=0; i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(vis.find({i,j})==vis.end()){
                        int area = 0;
                        dfs(grid, vis, i,j,m,n, area);
                        ans = max(area, ans);
                    }
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& grid, set<pair<int,int>> &vis, int tarx, int tary, int m, int n, int &area){
        vector<pair<int,int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        vis.insert({tarx,tary});
        area++;
        for(auto p : dir){
            int x = tarx + p.first;
            int y = tary + p.second;
            if(x>=0 && x<m && y>=0 && y<n){
                if(grid[x][y]==1 && vis.find({x,y})==vis.end()){
                    dfs(grid, vis, x, y, m, n, area);
                }
            }
        }
        return;
    }
};