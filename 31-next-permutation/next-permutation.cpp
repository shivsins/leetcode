class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // code here
        int n=nums.size();
        int i = n-1, l, r;
        while(i>0 && nums[i]<=nums[i-1]) i--;
        if(i==0){
            l=0;r=n-1;
            while(l<r){
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
            return;
        }
        int target = i-1;
        l=i;r=n-1;
        while(l<r){
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
        l=i;
        while(i<n && nums[target]>=nums[i]) i++;
        swap(nums[i], nums[target]);
        return;
    }
};