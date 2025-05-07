class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        if(rows==1 && cols==1) return 0;
        vector<vector<int>> efforts(rows, vector<int>(cols,INT_MAX));
        vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,0});
        while(!pq.empty()){
            vector<int> curr = pq.top();
            pq.pop();
            for(vector<int> d : dir){
                int nx = d[0]+curr[1];
                int ny = d[1]+curr[2];
                if(nx>-1 && nx<rows && ny>-1 && ny<cols){
                    int effort = max(abs(heights[nx][ny]-heights[curr[1]][curr[2]]),curr[0]);
                    if(effort<efforts[nx][ny]){
                        efforts[nx][ny]=effort;
                        pq.push({effort,nx,ny});
                    }
                }
            }
        }
        return efforts[rows-1][cols-1];
    }
};