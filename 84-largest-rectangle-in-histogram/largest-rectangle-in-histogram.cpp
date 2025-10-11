class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n,0);
        vector<int> nse(n,0);
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i]<=st.top().second) {
                st.pop();
            }
            if(!st.empty()){
                pse[i]=st.top().first;
            }else{
                pse[i]=-1;
            }
            st.push({i,heights[i]});
        }
        stack<pair<int,int>> st1;
        for(int i=n-1;i>=0;i--){
            while(!st1.empty() && heights[i]<=st1.top().second) {
                st1.pop();
            }
            if(!st1.empty()){
                nse[i]=st1.top().first;
            }else{
                nse[i]=n;
            }
            st1.push({i,heights[i]});
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans = max(ans,(nse[i]-pse[i]-1)*heights[i]);
        }
        return ans;
    }
};