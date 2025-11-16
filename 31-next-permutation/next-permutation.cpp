class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // code here
        int n=nums.size();
        int r = n-2;

        while(r>=0 && nums[r]>=nums[r+1]) r--;
        if(r<0){
            reverse(nums.begin(), nums.end());
        }else{
            for(int i=n-1; i>r; i--){
                if(nums[i]>nums[r]){
                    swap(nums[r], nums[i]);
                    break;
                }
            }
            reverse(nums.begin()+r+1, nums.end());
        }
    }
};