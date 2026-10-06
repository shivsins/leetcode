class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        // int maxth=nums[0], minth=nums[0];
        // int ans = nums[0];
        int pre=1, suf=1;
        int ans=INT_MIN;
        for(int i=0; i<n;i++){
            // int temp = maxth;
            // maxth = max(nums[i], max(maxth*nums[i], minth*nums[i]));
            // minth = min(nums[i], min(temp*nums[i], minth*nums[i]));
            // ans = max(ans, maxth);
            pre=nums[i]*pre;
            suf=nums[n-i-1]*suf;
            ans=max(ans, max(pre,suf));
            if(pre==0) pre=1;
            if(suf==0) suf=1;
        }
        return ans;
    }
};