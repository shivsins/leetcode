//using the monotonic stack. Idea is to keep maintain the stack in a monotonic way(increasing or decreasing).
//In our case we are keeping it in increasing way. We start from the back and pop till the elements are less
// than the current element.

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        map<int,int> m;
        int n = nums1.size();
        vector<int> res(n,-1);
        for(int i=0;i<n;i++){
            m[nums1[i]] = i;
        }
        for(int i = nums2.size()-1; i>=0;i--){
            while(!s.empty() && nums2[i]>s.top()) s.pop();
            if(!s.empty() && m.find(nums2[i])!=m.end()){
                res[m[nums2[i]]] = s.top();
            } 
            s.push(nums2[i]);
        }
        return res;
    }
};