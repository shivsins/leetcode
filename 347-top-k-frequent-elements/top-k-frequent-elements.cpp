class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        map<int, int> count;
        vector<vector<int>> bucket(nums.size()+1);
        for(int i : nums){
            count[i]++;
        }
        for(auto it : count){
            bucket[it.second].push_back(it.first);
        }
        for(int i=nums.size();i>=0;i--){
            for(int j : bucket[i]){
                res.push_back(j);
                if(res.size()==k){
                    return res;
                }
            }
        }
        return res;
    }
};