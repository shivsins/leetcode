class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m=boxGrid.size();
        int n=boxGrid[0].size();
        vector<vector<char>> ans(n, vector<char>(m,'.'));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[j][m - 1 - i] = boxGrid[i][j];
            }
        }
        for(int j=0;j<m;j++){
            int last=n;
            for(int i=n-1;i>=0;i--){
                if(ans[i][j]=='*'){
                    last=i;
                }else if(ans[i][j]=='.') continue;
                else{
                    last--;
                    if(last==i){
                        continue;
                    }else{
                        ans[last][j]=ans[i][j];
                        ans[i][j]='.';
                    }
                }
            }
        }
        return ans;
    }
};