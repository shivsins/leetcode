class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        // dp[0]=nums[0];
        // for(int i=1;i<n;i++){
        //     int rob=nums[i];
        //     int notRob=INT_MIN;
        //     if(i>1){
        //         rob=nums[i]+dp[i-2];
        //     }
        //     notRob=dp[i-1];
        //     dp[i]=max(rob, notRob);
        // }
        // return dp[n-1];
        return recur(n-1, dp, nums);
    }

    int recur(int ind, vector<int> &dp, vector<int>& nums){
        if(ind==0) return nums[0]; 
        if(dp[ind]!=-1) return dp[ind];
        int notRob=recur(ind-1,dp,nums);
        int rob=nums[ind];
        if(ind>1) rob=nums[ind]+recur(ind-2,dp, nums);
        return dp[ind] = max(notRob, rob);
    }
};