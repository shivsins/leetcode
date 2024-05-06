class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        vector<bool> found(n);
        stack<pair<int,int>> s;
        for(int i=0;i<n;i++){
            found[i] = 0;
        }
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[i]>s.top().first) {
                res[s.top().second] = nums[i];
                found[s.top().second] = 1;
                s.pop();
            }
            s.push({nums[i],i});
        }
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[i]>s.top().first) {
                if(!found[s.top().second]){
                    res[s.top().second] = nums[i];
                }
                found[s.top().second] = 1;
                s.pop();
            }
            s.push({nums[i],i});
        }
        return res;
    }
};