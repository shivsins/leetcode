class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = -1, count = 0;
        for(int cur: nums){
            if(cur==ele){
                count++;
            }else if(count==0){
                ele = cur;
                count++;
            }else{
                count--;
            }
        }
        return ele;
    }
};