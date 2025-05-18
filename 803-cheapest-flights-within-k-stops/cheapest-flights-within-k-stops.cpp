class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> adj(n);
        vector<int> dis(n,INT_MAX);
        for(vector<int> flight: flights){
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        dis[src]=0;
        queue<vector<int>> q;
        q.push({0,src,0});
        while(!q.empty()){
            vector<int> curr = q.front();
            q.pop();
            int stops = curr[2];
            if(stops<=k){
                for(vector<int> node : adj[curr[1]]){
                    if(curr[0]+node[1]<dis[node[0]]){
                        dis[node[0]]=curr[0]+node[1];
                        q.push({dis[node[0]], node[0], stops+1});
                    }
                }
            }
        }
        if(dis[dst]!=INT_MAX) return dis[dst];
        return -1;
    }
};