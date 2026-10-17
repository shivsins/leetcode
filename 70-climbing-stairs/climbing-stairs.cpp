class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo(n+1,-1);
        memo[0]=1;
        memo[1]=1;
        for(int i=2;i<=n;i++){
            memo[i]=memo[i-1]+memo[i-2];
        }
        return memo[n];
    }

    int dp(int ind, vector<int> &memo){
        if(ind==0 || ind==1) return 1;
        if(memo[ind]!=-1) return memo[ind];
        int left=dp(ind-1, memo);
        int right=dp(ind-2, memo);
        memo[ind]=left+right;
        return memo[ind];
    }
};