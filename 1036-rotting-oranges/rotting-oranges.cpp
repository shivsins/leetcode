class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>> q;
        int total = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==1) total++;
            }
        }
        int rotten = 0;
        int ans = 0;
        bfs(grid, m, n, q, ans, total);
        if(total>0) return -1;
        else return ans;
        // return ans;
    }

    void bfs(vector<vector<int>>& grid, int m, int n, queue<vector<int>> q, int &ans, int &total){
        vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while(!q.empty() && total>0){
            int qn = q.size();
            for(int i=0;i<qn;i++){
                vector<int> curr = q.front();
                q.pop();
                for(vector<int> vec : dir){
                    int x = curr[0] + vec[0];
                    int y = curr[1] + vec[1];
                    if(x>=0 && x<m && y>=0 && y<n){
                        // vector<int> temp = {x,y};
                        if(grid[x][y]==1) {
                            q.push({x,y});
                            grid[x][y] = 2;
                            total--;
                        }    
                    }
                }
            }
            ans++;
        }
    }
};