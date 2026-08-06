class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int n = text1.size();
        const int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        // return lcs(n-1,m-1,text1,text2,dp);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(text1[i]==text2[j]){
                    dp[i+1][j+1] = 1+dp[i][j];
                }else{
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        return dp[n][m];
    }    

    int lcs(int i, int j, string t1, string t2, vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]) return dp[i][j];
        if(t1[i]==t2[j]) return dp[i][j] = 1+lcs(i-1,j-1,t1,t2,dp);
        else{
            return dp[i][j] = max(lcs(i-1,j,t1,t2,dp), lcs(i,j-1,t1,t2,dp));
        }

    }
};