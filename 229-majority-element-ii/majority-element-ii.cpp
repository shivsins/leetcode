class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1=-1, ele2=-1, c1=0, c2=0;
        for(int cur: nums){
            if(cur==ele1){
                c1++;
            }else if(cur==ele2){
                c2++;
            }else if(c1==0){
                ele1 = cur;
                c1++;
            }else if(c2==0){
                ele2 = cur;
                c2++;
            }else{
                c1--;
                c2--;
            }
        }
        vector<int> res;
        int n = nums.size();
        if(c1>0){
            c1=0;
            for(int cur: nums){
                if(cur==ele1){
                    c1++;
                }
            }
            if(c1>n/3){
                res.push_back(ele1);
            }
        }
        if(c2>0){
            c2=0;
            for(int cur: nums){
                if(cur==ele2){
                    c2++;
                }
            }
            if(c2>n/3){
                res.push_back(ele2);
            }
        }
        return res;
        }
};