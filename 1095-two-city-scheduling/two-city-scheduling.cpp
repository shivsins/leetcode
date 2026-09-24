class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ans=INT_MAX;
        int n=costs.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(n+1, -1)));
        return cal(costs, 0,0,0,dp);
        // return dp[n-1][n-1][n-1];
    }
    
    int cal(vector<vector<int>>& costs, int cta, int ctb, int index, vector<vector<vector<int>>> &dp){  int n = costs.size();
        if(index==n){
            if(cta==n/2 && ctb==n/2){
                return 0;
            }
            return INT_MAX;
        }
        if(dp[index][cta][ctb]!=-1) return dp[index][cta][ctb];
        int a=INT_MAX;
        int b=INT_MAX;
        if(cta<n/2){
            int temp = cal(costs, cta+1, ctb, index+1,dp);
            if(temp!=INT_MAX) a=temp+costs[index][0];
        }
        if(ctb<n/2){
            int temp = cal(costs, cta, ctb+1, index+1,dp);
            if(temp!=INT_MAX) b=temp+costs[index][1];
        }
        return dp[index][cta][ctb]=min(a,b);
    }
};