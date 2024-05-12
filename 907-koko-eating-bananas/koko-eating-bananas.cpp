//Very good problem to understand how we can use binary search in a different way.
//We know if we select the max element of the pile then we will be able to finish the pile in the given time for sure.
//so we know answer lies in between 1 - Max_Pile_element.
//so we use binary search on this range and calcculate time taken for each iteration to finish the pile
//using this we can find the minmum element
//in this one we are returning l as final answer, which is a little tricky as we update l = mid+1 and r = mid bcz we want to keep the answer which finishes the pile in <=h in the binaray search.
//in another approach we can keep track of each iteration that ends up finishing the pile and take the minimum of it.
//commented code for the other approach

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int m = INT_MIN;
        int n = piles.size();
        for(int i=0;i<n;i++){
            m = max(m,piles[i]);
        }
        // int res = m 
        int l = 1, r = m;
        //l<=r
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
                //r = mid-1;
                //res = min(res,mid)
            }
        }
        return l;
        //return res;
    }
};