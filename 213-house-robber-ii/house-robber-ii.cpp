class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n,0);
        vector<int> dp2(n+1,0);
        if(n==1) return nums[0];
        if(n==0) return 0;
        dp1[0]=0;
        dp1[1]=nums[0];
        for(int i=1;i<n-1;i++){
            dp1[i+1] = max(nums[i]+dp1[i-1],dp1[i]);
        }
        for(int i=1;i<n;i++){
            dp2[i+1] = max(nums[i]+dp2[i-1],dp2[i]);
        }
        return max(dp1[n-1],dp2[n]);
    }
};