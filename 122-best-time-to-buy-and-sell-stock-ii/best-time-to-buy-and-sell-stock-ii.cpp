class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int l=0, r=1, res=0;
        // int n = prices.size();
        // if(n<=1) return 0;
        // while(l<n && r<n){
        //     while(l<n-1 && prices[l]>=prices[l+1]) l++;
        //     r=l+1;
        //     while(r<n-1 && prices[r]<=prices[r+1]) r++;
        //     if(r<n && prices[r]>prices[l]) res+=prices[r]-prices[l];
        //     l=r+1;
        // }
        // return res;
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(prices,0,prices.size(),1,dp);
    }
    int f(vector<int>& prices, int i, int n, int buy, vector<vector<int>> &dp){
        if(i==n) return 0;
        int profit=0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            dp[i][buy]=max(-prices[i]+f(prices, i+1,n,0,dp),f(prices,i+1,n,1,dp));
        }else{
            dp[i][buy]=max(prices[i]+f(prices,i+1,n,1,dp),f(prices,i+1,n,0,dp));
        }
        return dp[i][buy];
    }
};