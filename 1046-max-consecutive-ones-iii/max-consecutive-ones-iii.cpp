class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n =nums.size();
        int countZero=0;
        int ans=0;
        int l=0, r=0;
        while(r<n){
            if(nums[r]==1) r++;
            else if(countZero<k){
                r++;
                countZero++;
            }else{
                while(nums[l]!=0) l++;
                l++;
                countZero--;
            }
            ans=max(ans, r-l);
        }
        return ans;
    }
};