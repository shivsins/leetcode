class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l = 0, r = n-1;
        vector<int> res;
        while(l<r){
            int sum = numbers[l]+numbers[r];
            if(sum<target){
                l++;
            }else if(sum>target){
                r--;
            }else{
                res.push_back(l+1);
                res.push_back(r+1);
                break;
            }
        }
        return res;
    }
};