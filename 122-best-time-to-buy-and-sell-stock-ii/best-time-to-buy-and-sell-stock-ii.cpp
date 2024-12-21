class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0, r=1, res=0;
        int n = prices.size();
        if(n<=1) return 0;
        while(l<n && r<n){
            while(l<n-1 && prices[l]>=prices[l+1]) l++;
            r=l+1;
            while(r<n-1 && prices[r]<=prices[r+1]) r++;
            if(r<n && prices[r]>prices[l]) res+=prices[r]-prices[l];
            l=r+1;
        }
        return res;
    }
};