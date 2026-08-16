class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> ans(n+1,0);
        if(n<=4){
            for(int i=1;i<=n;i++){
                ans[i]=i;
            }
            ans.erase(ans.begin());
            return ans;
        }else{
            for(int i=1;i<=4;i++){
                ans[i]=i;
            }
            vector<vector<int>> adj(n+1);
            for(auto it : paths){
                adj[it[0]].push_back(it[1]);
                adj[it[1]].push_back(it[0]);
            }
            for(int i=5;i<=n;i++){
                set<int> av={1,2,3,4};
                for(int node : adj[i]){
                    if(ans[node]!=0){
                        av.erase(ans[node]);
                    }
                }
                for(int it: av){
                    ans[i]=it;
                    break;
                }
            }
            ans.erase(ans.begin());
            return ans;
        }
    }
};