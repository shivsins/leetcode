class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        map<int, bool> m1;
        for(int val : nums1){
            m1[val] = true;
        }
        for(int val : nums2){
            if(m1[val]){
                ans.push_back(val);
                m1[val] = false;
            }
        }
        
        return ans;
    }
};