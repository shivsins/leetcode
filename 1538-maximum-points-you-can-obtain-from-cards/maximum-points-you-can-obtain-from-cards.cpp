class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int start=k-1,n=cardPoints.size(), r=n-1;
        int ans=0, curr=0;
        for(int i=0;i<k;i++){
            curr=curr+cardPoints[i];
        }
        ans=curr;
        cout<<ans;
        while(start>=0){
            curr=curr-cardPoints[start]+cardPoints[r];
            ans=max(ans, curr);
            cout<<curr<<endl;
            start--; r--;
        }
        return ans;
    }
};