class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];    // compare first element
        });
        int count=0;
        int n = intervals.size();
        if(n<=1) return 0;
        int last = intervals[0][1];
        count++;
        int i=1;
        while(i<n){
            if(intervals[i][0]>=last){
                count++;
                last=intervals[i][1];
            }
            i++;
        }
        return n-count;
    }
};