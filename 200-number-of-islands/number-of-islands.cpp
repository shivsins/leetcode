class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int pro = 0;
        set<pair<int,int>> vis;
        for(int i=0; i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    if(vis.find({i,j})==vis.end()){
                        pro++;
                        dfs(grid, vis, i,j,m,n);
                    }
                }
            }
        }
        return pro;
    }

    void dfs(vector<vector<char>>& grid, set<pair<int,int>> &vis, int tarx, int tary, int m, int n){
        vector<pair<int,int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        vis.insert({tarx,tary});
        for(auto p : dir){
            int x = tarx + p.first;
            int y = tary + p.second;
            if(x>=0 && x<m && y>=0 && y<n){
                if(grid[x][y]=='1' && vis.find({x,y})==vis.end()){
                    dfs(grid, vis, x, y, m, n);
                }
            }
        }
        return;
    }
};