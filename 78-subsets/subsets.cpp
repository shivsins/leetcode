class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        backTrack(ans,nums,curr,0);
        return ans;
    }

    void backTrack(vector<vector<int>> &ans, vector<int>& nums, vector<int> curr, int index ){
        if(index>= nums.size()) {
            ans.push_back(curr);
            return;
        }
        backTrack(ans, nums, curr, index+1);
        curr.push_back(nums[index]);
        backTrack(ans, nums, curr, index+1);
    }
};