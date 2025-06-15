class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(int e : nums){
            sum+=e;
        }
        if(sum%2!=0) return false;
        sum = sum/2;
        vector<vector<bool>> dp(n, vector<bool>(sum+1,false));
        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }
        if(nums[0]<=sum) dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int t=1;t<=sum;t++){
                bool notTake = dp[i-1][t];
                bool take = false;
                if(nums[i]<=t) take=dp[i-1][t-nums[i]];
                dp[i][t]=take||notTake;
            }
        }
        return dp[n-1][sum];
    }
};