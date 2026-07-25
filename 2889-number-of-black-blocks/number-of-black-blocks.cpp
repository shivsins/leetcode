class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        vector<long long> ans(5,0);
        map<pair<int,int>,int> cm;
        for(auto it: coordinates){
            int x=it[0], y=it[1];
            if(x<m-1 && y<n-1){
                cm[{x,y}]++;
            }
            if(x-1>=0 && x-1<m-1 && y-1>=0 && y-1<n-1){
                cm[{x-1,y-1}]++;
            }
            if(x-1>=0 && x-1<m-1 && y>=0 && y<n-1){
                cm[{x-1,y}]++;
            }
            if(y-1>=0 && y-1<n-1 && x>=0 && x<m-1){
                cm[{x,y-1}]++;
            }
        }
        long long total=((long long) (m-1))*((long long) (n-1));
        for(auto it: cm){
            int count = it.second;
            ans[count]++;
        }
        ans[0]=total-cm.size();
        return ans;
    }
};