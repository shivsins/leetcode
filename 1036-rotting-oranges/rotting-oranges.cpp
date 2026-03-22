class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m =grid.size();
        int n = grid[0].size();
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        queue<vector<int>> q;
        int f=0;
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==1) f++;
            }
        }
        if(f==0) return 0;
        while(!q.empty()){
            int len=q.size();
            ans++;
            for(int i=0;i<len;i++){
                vector<int> curr = q.front();
                q.pop();
                for(vector<int> d : dir){
                    int x = curr[0]+d[0];
                    int y = curr[1]+d[1];
                    if(x>=0 && x<m && y>=0 && y<n){
                        if(grid[x][y]==1){
                            f--;
                            grid[x][y]=2;
                            q.push({x,y});
                        }
                    }
                }
            }
            
        }
        if(f==0) return ans-1;
        return -1;
    }
};