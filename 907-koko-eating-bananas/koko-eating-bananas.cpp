class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int m = INT_MIN;
        int n = piles.size();
        for(int i=0;i<n;i++){
            m = max(m,piles[i]);
        }
        int l = 1, r = m;
        while(l<r){
            int mid = (l+r)/2;
            int time = 0;
            for(int i=0;i<n;i++){
                if(piles[i]%mid==0) time+=piles[i]/mid;
                else time+=(piles[i]/mid) + 1;
            }
            if(time>h) l=mid+1;
            else {
                r = mid;
            }
        }
        return l;
    }
};