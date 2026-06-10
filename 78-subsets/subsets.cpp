//good question, think of it as either we include the particular number or dont in the subset.
//so based on that different branching will turn out
//multiple backtracking questions can be solved using this approach.
// see this video if you want to understand more https://www.youtube.com/watch?v=3tpjp5h3M6Y
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(ans,nums,curr,0);
        ans.push_back({});
        return ans;
    }

    void backtrack(vector<vector<int>> &ans, vector<int> nums, vector<int> curr, int ind){
        if(ind==nums.size()) return;
        curr.push_back(nums[ind]);
        ans.push_back(curr);
        backtrack(ans, nums,curr , ind+1);
        curr.pop_back();
        backtrack(ans, nums, curr, ind+1);
    }
};