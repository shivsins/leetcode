class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j || j>i) continue;
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        int l=0, r=n-1;
        while(l<r){
            for(int i=0;i<n;i++){
                swap(matrix[i][l], matrix[i][r]);
            }
            l++;
            r--;
        }
    }
};