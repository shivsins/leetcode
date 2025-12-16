class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> m;
        m[0]=1;
        int n = nums.size();
        int ans =0;
        int sum=0;
        for(int i=0;i<n; i++){
            sum = sum+nums[i];
            // if(sum==k) ans++;
            if(m[sum-k]){
                ans = ans + m[sum-k];
            }
            m[sum]++;
        }
        return ans;
    }
};