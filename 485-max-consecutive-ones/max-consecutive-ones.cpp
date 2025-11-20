class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int l=0, r=0,ans=0;
        while(r<n){
            while(l<n && nums[l]==0) l++;
            r=l;
            while(r<n && nums[r]==1) r++;  
            ans = max(ans, r-l);
            l=r;
        }
        return ans;
    }
};