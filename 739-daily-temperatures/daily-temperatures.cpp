class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       stack<pair<int,int>> st;
       int n = temperatures.size();
       vector<int> res(n,0);
       for(int i=0;i<n;i++){
        while(!st.empty() && st.top().first<temperatures[i]){
            pair<int,int> curr = st.top();
            res[curr.second] = i-curr.second;
            st.pop();
        }
        st.push({temperatures[i], i});
       }
       return res;
    }
    
};