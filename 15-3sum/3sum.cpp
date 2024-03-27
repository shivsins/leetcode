class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int l = i+1, r = n-1;
            while(l<r){
                int sum = nums[i]+nums[l]+nums[r];
                if(sum>0){
                    r-=1;
                }else if(sum<0){
                    l+=1;
                }else{
                    result.push_back({nums[i],nums[l],nums[r]});
                    l+=1;
                    while(nums[l-1]==nums[l] && l<r) l++;
                }
            }
        }
        return result;
    }
};