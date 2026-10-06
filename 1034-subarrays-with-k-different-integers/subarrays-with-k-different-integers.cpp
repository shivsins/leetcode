class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // map<int,int> mp;
        // int l=0,r=0,m=0,ans=0;
        // while(r<nums.size()){
        //     mp[nums[r]]++;
        //     if(mp.size()>k){
        //         while(mp.size()>k){
        //             if(--mp[nums[l]]==0){
        //                 mp.erase(nums[l]);
        //             }
        //             l++;
        //         }
        //         m=l;
        //     }
        //     if(mp.size()==k){
        //         map<int,int> temp = mp;
        //         while(temp.size()==k){
        //             if(--temp[nums[m]]==0){
        //                 ans+=m-l+1;
        //                 break;
        //             }
        //             m++;
        //         }
        //     }
        //     r++;
        // }
        // return ans;
        return findSub(nums,k)-findSub(nums,k-1);
    }
    int findSub(vector<int>& nums, int k){
        int l=0,r=0;
        int ans=0;
        map<int,int> mp;
        if(k==0) return 0;
        while(r<nums.size()){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
};