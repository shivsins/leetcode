class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l =0, r = n-1;
        if(n==0) return 0;
        int res = 0;
        int maxL = height[l], maxR = height[r];
        while(l<r){
            if(maxL<maxR){
                l++;
                maxL = max(maxL, height[l]);
                res+=maxL-height[l];
            }else{
                r--;
                maxR = max(maxR, height[r]);
                res+=maxR-height[r];
            }
        } 
        return res;       
    }


    //with extra space O(n) but the concept is same. Basically we are looking for minimum of max left and max right.
    //in the above solution also we are doing the same thing but without extra space.
    // int n = height.size();
    // if(n==0) return 0;
    // vector<int> maxL(n), maxR(n);
    // maxL[0] = height[0];
    // for(int i=1;i<n;i++){
    //     maxL[i] = max(maxL[i-1], height[i]);
    // }
    // maxR[n-1] = height[n-1];
    // for(int i = n-2;i>-1;i--){
    //     maxR[i] = max(maxR[i+1], height[i]);
    // }
    // int res = 0;
    // for(int i=0;i<n;i++){
    //     res+= min(maxL[i],maxR[i]) - height[i];
    // }
    // return res;
    // }
};