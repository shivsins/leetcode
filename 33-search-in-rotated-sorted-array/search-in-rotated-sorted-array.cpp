class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size()-1;
        int l=0,r=n;
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]>nums[r]) l=mid+1;
            else r=mid;  
        }
        int l1=0,r1=l-1;
        r = n;
        while(l1<=r1){
            int mid = (l1+r1)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target){
                l1=mid+1;
            }else r1 = mid-1;
        }
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target){
                l=mid+1;
            }else r = mid-1;
        }
        return -1;
    }
};