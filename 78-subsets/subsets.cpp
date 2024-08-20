//good question, think of it as either we include the particular number or dont in the subset.
//so based on that different branching will turn out
//multiple backtracking questions can be solved using this approach.
// see this video if you want to understand more https://www.youtube.com/watch?v=3tpjp5h3M6Y
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        backTrack(ans,nums,curr,0);
        return ans;
    }

    // void backTrack(vector<vector<int>> &ans, vector<int>& nums, vector<int> curr, int index ){
    //     if(index>= nums.size()) {
    //         ans.push_back(curr);
    //         return;
    //     }
    //     backTrack(ans, nums, curr, index+1);
    //     curr.push_back(nums[index]);
    //     backTrack(ans, nums, curr, index+1);
    // }

    void backTrack(vector<vector<int>> &ans, vector<int>& nums, vector<int> curr, int index){
        ans.push_back(curr);
        for(int i=index;i<nums.size();i++){
            curr.push_back(nums[i]);
            backTrack(ans, nums, curr, i+1);
            curr.pop_back();
        }
    }
};