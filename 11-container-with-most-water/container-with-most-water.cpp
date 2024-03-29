class Solution {
public:
    int maxArea(vector<int>& height) {
        int res=0, n = height.size();
        int l=0, r=n-1;
        while(l<r){
            int area = (r-l)*min(height[l],height[r]);
            res = max(area, res);
            if(height[l]>=height[r]) r--;
            else l++;
        }
        return res;
    }
};