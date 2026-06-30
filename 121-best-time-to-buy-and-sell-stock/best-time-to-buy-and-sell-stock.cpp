class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int sell=0;
        int ans = 0;
        int n = prices.size();
        for(int i=1;i<n;i++){
            if(prices[i]<prices[buy]) buy=i;
            else{
                ans=max(ans, prices[i]-prices[buy]);
            }
        }
        return ans;
    }
};