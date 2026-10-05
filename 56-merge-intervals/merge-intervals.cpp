class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];    // compare first element
        });
        int n = v.size();
        vector<vector<int>> ans;
        ans.push_back(v[0]);
        for(int i=1;i<n;i++){
            vector<int>& last=ans.back();
            vector<int> curr=v[i];
            if(last[1]>=curr[0]){
                last[1]=max(last[1],curr[1]);
            }else{
                ans.push_back(curr);
            }
        }
        return ans;
    }
};