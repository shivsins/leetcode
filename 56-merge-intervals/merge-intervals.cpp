class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];    // compare first element
        });
        int n = v.size();
        vector<vector<int>> ans;
        if(n<2) return v;
        ans.push_back(v[0]);
        int l=0, r=1;
        while(r<n){
            if(ans[l][1]>=v[r][0]){
                ans[l][1] = max(ans[l][1], v[r][1]);
                r++;
            }else{
                ans.push_back(v[r]);
                l++;
                r++;
            }
        }
        return ans;
    }
};