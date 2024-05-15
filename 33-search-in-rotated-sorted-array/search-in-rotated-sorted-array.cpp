//two ways to solve it, one is to find the minimum value index and then treat the problem as two differnt sorted arrays.
// other one is a little different and it does it in a single go which is what I have coded below.
// so we know there exists two sorted portions in the same array. left and right sorted portions.
// so with each iteration we check which portion we are in
// then we check where the target lies, and we make a move accordingly

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>=nums[l]){
                if(target<nums[l] || target > nums[mid]) l = mid+1;
                else r = mid-1;
            }
            else{
                if(target>nums[r] || target<nums[mid]) r = mid-1;
                else l = mid+1;
            }
        }
        return -1;
    }
};