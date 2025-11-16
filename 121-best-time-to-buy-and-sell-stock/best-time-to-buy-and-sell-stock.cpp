class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int sell=0;
        int ans = 0;
        int n = prices.size();
        while(buy<n){
            sell++;
            while(sell<n && prices[sell]>=prices[buy]){
                ans = max(ans,prices[sell] - prices[buy]);
                sell++;
            }
            buy=sell;
        }
        return ans;
    }
};