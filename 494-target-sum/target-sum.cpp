class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return f(nums, target, nums.size()-1);
    }
    int f(vector<int>& nums, int target, int ind){
        if(ind==0){
            int ways=0;
            if(target+nums[0]==0) ways++;
            if(target-nums[0]==0) ways++;
            return ways;
        }
        int pos = f(nums, target+nums[ind], ind-1);
        int neg = f(nums, target-nums[ind], ind-1);
        return pos+neg;
    }
};