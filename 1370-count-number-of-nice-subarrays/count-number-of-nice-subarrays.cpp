class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count=0, l=0,r=0,m=0, ans=0;
        while(r<nums.size()){
            if(nums[r]%2==1) count++;
            if(count>k){
                while(count>k){
                    if(nums[l]%2==1) {count--;}
                    l++;
                }
                m=l;
            }
            if(count==k){
                while(nums[m]%2==0){
                    m++;
                }
                ans=ans+m-l+1;
            }
            r++;
        }
        return ans;
    }
};