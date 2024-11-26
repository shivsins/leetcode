class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        int n = points.size();
        priority_queue<pair<int,int>> p;
        
        for(int i  = 0; i < n; i++){
            int x = (points[i][0]*points[i][0])+(points[i][1]*points[i][1]);
            p.push({x,i});
            if(p.size() > k){
                p.pop();
            }
        }
        
        vector<vector<int>> ans;
        while(!p.empty()){
            auto x = p.top();
            p.pop();
            int i = x.second;
            ans.push_back({points[i][0],points[i][1]});
        }
        return ans;
    }
};