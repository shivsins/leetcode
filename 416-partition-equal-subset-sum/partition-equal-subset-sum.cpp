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
        vector<bool> prev(sum+1,false);
        vector<bool> curr(sum+1,false);
        prev[0]=true;
        curr[0]=true;
        // for(int i=0;i<n;i++){
        //     dp[i][0] = true;
        // }
        if(nums[0]<=sum) prev[nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int t=1;t<=sum;t++){
                bool notTake = prev[t];
                bool take = false;
                if(nums[i]<=t) take=prev[t-nums[i]];
                curr[t]=take||notTake;
            }
            prev=curr;
        }
        return curr[sum];
    }
};