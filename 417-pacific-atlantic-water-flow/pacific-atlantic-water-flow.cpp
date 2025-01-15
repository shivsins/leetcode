class Solution {
public:

    void dfs(vector<vector<int>>& heights, int m, int n, set<pair<int,int>> &visit, int r, int c, int previous){
        if(r<0 || c<0 || r==m || c==n) return;
        if(visit.find({r,c})!=visit.end() || heights[r][c]<previous) return;
        visit.insert({r,c});
        dfs(heights, m, n, visit, r+1, c, heights[r][c]);
        dfs(heights, m, n, visit, r-1, c, heights[r][c]);
        dfs(heights, m, n, visit, r, c+1, heights[r][c]);
        dfs(heights, m, n, visit, r, c-1, heights[r][c]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        set<pair<int,int>> pac, atl;
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> ans;
        for(int c=0; c<n ; c++){
            dfs(heights, m, n, pac, 0, c, heights[0][c]);
            dfs(heights, m, n, atl, m-1, c, heights[m-1][c]);
        }
        for(int r=0; r<m ; r++){
            dfs(heights, m, n, pac, r, 0, heights[r][0]);
            dfs(heights, m, n, atl, r, n-1, heights[r][n-1]);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac.find({i,j})!=pac.end() && atl.find({i,j})!=atl.end()){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};