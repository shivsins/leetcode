class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, r = m*n-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(mid%m==0){
                if(matrix[mid/m][0] == target) return true;
                else if(matrix[mid/m][0]<target) l = mid+1;
                else r = mid-1;
            }else{
                if(matrix[mid/m][mid%m] == target) return true;
                else if(matrix[mid/m][mid%m]<target) l = mid+1;
                else r = mid-1;
            }
        }
        return false;
    }
};