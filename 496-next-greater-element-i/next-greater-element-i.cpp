class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        // map<int,int> m;
        int n = nums2.size();
        vector<int> res;
        for(int i=0;i<n;i++){
            // m[nums2[i]] = i;
            s.push(nums2[i]);
        }
        for(int i = 0; i<nums1.size();i++){
            stack<int> temp = s;
            int ans = -1;
            while(temp.top()!=nums1[i]){
                if(temp.top()>nums1[i]) ans = temp.top();
                temp.pop();
            }
            res.push_back(ans);
        }
        return res;
    }
};