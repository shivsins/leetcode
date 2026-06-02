class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int rob=nums[i];
            int notRob=INT_MIN;
            if(i>1){
                rob=nums[i]+dp[i-2];
            }
            notRob=dp[i-1];
            dp[i]=max(rob, notRob);
        }
        return dp[n-1];
    }
};