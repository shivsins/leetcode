class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        dfs(0,0,curr,candidates,target, res);
        return res;
    }
    
    void dfs(int index, int sum, vector<int> curr,vector<int>& candidates, int target, vector<vector<int>> &res){
        if(sum>target || index>candidates.size()) return;
        if(target == sum){
            res.push_back(curr);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            curr.push_back(candidates[i]);
            dfs(i+1,sum+candidates[i],curr,candidates,target,res);
            curr.pop_back();
            while(i<candidates.size()-1 && candidates[i]==candidates[i+1]) i++;
        }
    }
};