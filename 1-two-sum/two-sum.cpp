class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int comp = target-nums[i];
            if(ans.find(comp)!=ans.end()) return {ans[comp],i};
            ans[nums[i]]=i;
        }
        return {0,0};
        // int i;
        // for(i=0;i<n;i++){
        //     int comp = target-nums[i];
        //     if(ans[comp]!=0){
        //         break;
        //     }
        //     ans[nums[i]]++;
        // }
        // if(i<n){
        //     int comp = target-nums[i];
        //     for(int j=0;j<n;j++){
        //         if(j!=i){
        //             if(nums[j]==comp) return {i,j};
        //         }
        //     }
        // }
        // return {0,0};
    }
};