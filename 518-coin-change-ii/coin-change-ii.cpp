class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        return f(amount, coins, n-1, dp);
    }
    long f(int amount, vector<int>& coins, int ind, vector<vector<int>> &dp){
        if(ind==0){
            if(amount%coins[0]==0) return 1;
            else return 0;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        long notTake = f(amount, coins, ind-1, dp);
        long take=0;
        if(amount>=coins[ind]){
            take = f(amount-coins[ind],coins, ind, dp);
        }
        return dp[ind][amount]=take+notTake;
    }
};