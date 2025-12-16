class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> res(n,-1);
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                res[st.top()]=nums[i];
                st.pop();
            }
            st.push(i);
        }
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                if(res[st.top()]==-1){
                    res[st.top()]=nums[i];
                }
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};