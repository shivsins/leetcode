class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=0;
        int r=0;
        int n=nums.size();
        while(r<n){
            while(r<n && nums[r]==nums[l]) r++;
            l++;
            if(l<n && r<n){
                nums[l]=nums[r];
            }
        }
        return l;
    }
};