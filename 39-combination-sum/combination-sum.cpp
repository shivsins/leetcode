class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        dfs(ans, candidates, target, 0, curr, 0);
        return ans;
    }

    void dfs(vector<vector<int>> &ans, vector<int>& candidates, int target, int index, vector<int> curr, int sum){
        if(index>=candidates.size()) return;
        if(sum>target) return;
        if(sum==target){
            ans.push_back(curr);
            return;
        }
        curr.push_back(candidates[index]);
        sum = sum+candidates[index];
        dfs(ans, candidates, target, index, curr,sum);
        curr.pop_back();
        sum = sum-candidates[index];
        dfs(ans, candidates, target, index+1, curr,sum);
    }
};