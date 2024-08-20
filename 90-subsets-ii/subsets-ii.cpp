class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        backtrack(res, nums, curr,0);
        return res;
    }

    void backtrack(vector<vector<int>> &res, vector<int>& nums, vector<int> curr, int index){
        if(find(res.begin(), res.end(),curr)!=res.end()) return;
        res.push_back(curr);
        for(int i=index;i<nums.size();i++){
            curr.push_back(nums[i]);
            backtrack(res,nums, curr, i+1);
            curr.pop_back();
        }
    }
};