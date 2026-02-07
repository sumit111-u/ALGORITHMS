class Solution {
public:
    int m, n;
void dfs(vector<vector<char>>& grid, int r, int c){
    int nr=grid.size();
    int nc=grid[0].size();
    if(r<0 || c<0 || r>=m || c>=n || grid[r][c]=='0'){
        return ;
    }
        grid[r][c]='0';
        dfs(grid,r-1,c);
        dfs( grid,r+1,c);
        dfs( grid, r,c-1);
        dfs(grid,r,c+1);
}
    int numIslands(vector<vector<char>>& grid) {
        
        m = grid.size();
        if(!m) return 0;
        n = grid[0].size();
       
        int ans=0;
        for( int r=0;r<m;r++){
            for( int c=0;c<n;c++){
                if(grid[r][c]=='1'){
                    dfs(grid,r,c);
                    ans++;
                }
            }
        }
        return ans;
        
    }
};