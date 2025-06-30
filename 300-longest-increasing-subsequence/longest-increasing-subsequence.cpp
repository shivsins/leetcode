class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<pair<int,int>> lth(n);
        // lth[0]={1,0};
        // int ans=1;
        // for(int i=1; i<n; i++){
        //     for(int j=i; j>=0; j--){
        //         if(nums[j]<nums[i]){
        //             if(lth[i].first<1+lth[j].first){
        //                 lth[i] = {1+lth[j].first, j};
        //             }
        //         }
        //     }
        // }
        // pair<int,int> p = lth[0];
        // int ind=1;
        // for(int i=1; i<n; i++){
        //     if(lth[i].first>p.first){
        //         p=lth[i];
        //         ind=i;
        //     }
        // }
        // while(ind != lth[ind].second){
        //     cout<<nums[ind]<<" ";
        //     ind = lth[ind].second;
        // }
        // return ans;
        // return f(nums,n-1,n,INT_MAX);
        vector<int> dp(n,1);
        int res=1;
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[i]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            res=max(res,dp[i]);
        }
        return res;
    }
    int f(vector<int>& nums, int i, int n, int mini){
        if(i==0){
            if(nums[i]<mini) return 1;
            return 0;
        }
        int notTake = f(nums,i-1,n,mini);
        int take = 0;
        if(nums[i]<mini){
            take = 1+f(nums,i-1,n,nums[i]);
        }
        return max(take,notTake);
    }
};