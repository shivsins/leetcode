class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxth=nums[0], minth=nums[0];
        int ans = nums[0];
        for(int i=1; i<n;i++){
            int temp = maxth;
            maxth = max(nums[i], max(maxth*nums[i], minth*nums[i]));
            minth = min(nums[i], min(temp*nums[i], minth*nums[i]));
            ans = max(ans, maxth);
        }
        return ans;
    }
};