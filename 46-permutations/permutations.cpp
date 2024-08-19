class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        backtrack(result, nums, temp);
        return result;
    }

    void backtrack(vector<vector<int>> &result, vector<int>& nums, vector<int> temp){
        if(temp.size()==nums.size()){
            result.push_back(temp);
            return;
        }
        for(int n: nums){
            if(find(temp.begin(),temp.end(),n)!=temp.end()){
                continue;
            }
            temp.push_back(n);
            backtrack(result, nums, temp);
            temp.pop_back();
        }
    }
};