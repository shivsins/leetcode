class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];    // compare first element
        });
        int n = v.size();
        vector<vector<int>> ans;
        if(n<=1) return v;
        int l = 0, r = 1;
        int b = v[l][1];
        while(r<n){
            if(v[r][0]<=b){
                b = max(b, v[r][1]);
                r++;
            }else{
                ans.push_back({v[l][0], b});
                l=r;
                r++;
                b=v[l][1];
            }
        }
        ans.push_back({v[l][0], b});
        return ans;
    }
};