class Solution {
public:
void dfs( int r, int c,vector<vector<char>>& board){
     int m =board.size();
     if (m == 0) return;
     int n=board[0].size();
     if(r<0||r>=m||c<0||c>=n||board[r][c]!='O'){
        return;
     }
     board[r][c]='#';
     dfs(r+1,c,board);
     dfs(r-1,c,board);
     dfs(r,c+1,board);
     dfs(r,c-1,board);
}
    void solve(vector<vector<char>>& board) {
        int m =board.size();
        if(m==0) return ;
        int n=board[0].size();
        if(n==0) return;
        for( int i =0;i<m;i++){
            dfs(i,0,board);
            dfs(i,n-1,board);
            
        }
        for( int j=0;j<n;j++){
            dfs(0,j,board);
            dfs(m-1,j,board);
        }
        for( int i=0;i<m;i++){
            for( int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
    }
};