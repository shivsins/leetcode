class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo(n+1,-1);
        return dp(n,memo);
    }

    int dp(int n, vector<int> &memo){
        if(n<=2) return n;
        if(memo[n]!=-1) return memo[n];
        return memo[n]=dp(n-1, memo)+dp(n-2, memo);
    }
};