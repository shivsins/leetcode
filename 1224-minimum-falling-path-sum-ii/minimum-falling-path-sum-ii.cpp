class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[n-1][i]=grid[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int m=INT_MAX;
                for(int k=0;k<n;k++){
                    if(k!=j){
                        m=min(m,dp[i+1][k]);
                    }
                }
                dp[i][j]=grid[i][j]+m;
            }
        }
        int res=INT_MAX;
        for(int i=0;i<n;i++){
            res=min(res, dp[0][i]);
        }
        return res;
    }
};