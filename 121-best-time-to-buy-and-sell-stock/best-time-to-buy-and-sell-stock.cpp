class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l =0, r=1;
        int res = 0;
        while(r<prices.size()){
            if(prices[l]>=prices[r]){
                l++;
                r = l+1;
            }
            else{
                res = max(res,prices[r]-prices[l]);
                r++;
            }
        }
        return res;
    }
};