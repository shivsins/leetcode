class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[n-1][i]=matrix[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int m=INT_MAX;
                if(j+1<n){
                    m=min(m,dp[i+1][j+1]);
                }
                if(j-1>-1){
                    m=min(m,dp[i+1][j-1]);
                }
                m=min(m,dp[i+1][j]);
                dp[i][j]=matrix[i][j]+m;
            }
        }
        int res=INT_MAX;
        for(int i=0;i<n;i++){
            res=min(res, dp[0][i]);
        }
        return res;
    }
};