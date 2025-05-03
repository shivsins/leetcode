class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lth(n,1);
        lth[0]=1;
        int ans=1;
        for(int i=1; i<n; i++){
            for(int j=i; j>=0; j--){
                if(nums[j]<nums[i]){
                    lth[i] = max(lth[i], 1+lth[j]);
                }
            }
            ans = max(ans,lth[i]);
        }
        return ans;
    }
};