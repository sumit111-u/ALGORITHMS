class Solution {
public:
    int m, n;
    int dfs(vector<vector<int>>&grid, int r, int c){
        
        if(r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0) return 0;
        
        grid[r][c] = 0;
        
        int top =  dfs(grid, r-1, c);
        int down = dfs(grid, r+1, c);
        int left = dfs(grid, r, c-1);
        int right = dfs(grid, r, c+1);
        
        return 1 + top + down + left + right;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int area=0;
        for( int  r=0;r<m;r++){
            for( int c=0;c<n;c++){
                if(grid[r][c]==1){
                    area=max(area,dfs(grid,r,c));
                }
            }
        }
        return area;
    }
};