class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        int n = nums.size();
        if(n==0 || n==1) return n; 
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int res=1;
        for(int i : nums){
            if(m[i-1]==0){
                int temp=i;
                int len = 1;
                while(m[++temp]){
                    len++;
                }
                res = max(res, len);
            }
        }
        return res;
    }
};

//place the array on a number line, you will find the the start of the sequence has no left neighbour
// so that's the clue. then you take that element and see how long of a sequence it makes.
