class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,0));
        if(m==1 || n==1) return 1;
        for(int i=m-1;i>=0;i--){
            dp[i][n-1]=1;
        }
        for(int j=n-1;j>=0;j--){
            dp[m-1][j]=1;
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-2; j>=0; j--){
                dp[i][j] = dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};