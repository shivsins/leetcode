class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int c=0;c<n;c++){
            if(board[0][c]=='O'){
                dfs(board, m, n, 0, c);
            }
            if(board[m-1][c]=='O'){
                dfs(board, m, n, m-1, c);
            }
        }
        for(int r=0;r<m;r++){
            if(board[r][0]=='O'){
                dfs(board, m, n, r, 0);
            }
            if(board[r][n-1]=='O'){
                dfs(board, m, n, r, n-1);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='T'){
                    board[i][j]='O';
                }
                else{
                    board[i][j]='X';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int m, int n, int r, int c){
        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        board[r][c] = 'T';
        for(vector<int> v : dir){
            int x = r+v[0];
            int y = c+v[1];
            if(x>=0 && x<m && y>=0 && y<n){
                if(board[x][y]=='O'){
                    dfs(board, m, n, x, y);
                }
            }
        }
    }
};