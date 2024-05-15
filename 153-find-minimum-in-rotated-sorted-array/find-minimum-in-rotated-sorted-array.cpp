//think of it as two sorted arrays. One left sorted portion and one right sorted portion.
//value in right portion will always be less than left portion
//minimum value would lie in right sorted portion
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        int res = nums[0];
        while(l<=r){
            int mid = (l+r)/2;
            res = min(res, nums[mid]);
            if(nums[mid]>nums[r]) l = mid+1;
            else r = mid-1;
        }
        return res;
    }
};