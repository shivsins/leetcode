class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int jumps=0, r=0,l=0;
        while(r<n-1){
            int maxj=0;
            for(int i=l;i<=r && i<n;i++){
                maxj=max(maxj, i+nums[i]);
            }
            l=r+1;
            r=maxj;
            jumps++;
        }
        return jumps;
    }
};