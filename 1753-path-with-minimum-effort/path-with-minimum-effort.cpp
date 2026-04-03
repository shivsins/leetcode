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
        efforts[0][0]=0;
        while(!pq.empty()){
            vector<int> curr = pq.top();
            pq.pop();
            int x=curr[1];
            int y=curr[2];
            for(vector<int> d : dir){
                int dx=x+d[0];
                int dy=y+d[1];
                if(dx>-1 && dx<rows && dy>-1 &&dy<cols){
                    int effort = max(curr[0],abs(heights[x][y]-heights[dx][dy]));
                    if(effort<efforts[dx][dy]){
                        pq.push({effort,dx,dy});
                        efforts[dx][dy]=effort;
                    }
                }
            }
        }
        return efforts[rows-1][cols-1];
    }
};