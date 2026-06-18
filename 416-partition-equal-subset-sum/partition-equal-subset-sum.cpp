class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(int i=0;i<n;i++) sum+=nums[i];
        if(sum%2!=0) return false;
        int k=sum/2;
        vector<vector<bool>> dp(n, vector<bool>(k+1,0));
        for(int i=0;i<n;i++) dp[i][0]=true;
        if(nums[0]<k) dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int target=1;target<=k;target++){
                int notTake=dp[i-1][target];
                int take=false;
                if(nums[i]<=target) take=dp[i-1][target-nums[i]];
                dp[i][target]=take||notTake;
            }
        }
        return dp[n-1][k];
    }

};