class Solution {
public:
void dfs(vector<vector<char>> &grid, int r, int c,   vector<vector<bool>>& vis){
      int n=grid.size();
        int m=grid[0].size();
    vis[r][c]=true;
    int dela[]={-1,0,1,0};
    int delb[]={0,1,0,-1};
    for( int i=0;i<4;i++){
     int nr=r+dela[i];
     int nc=c+delb[i];
     if(nr<0|| nr>=n||nc<0||nc>=m|| grid[nr][nc]=='0'|| vis[nr][nc]==true)
    continue;
     else{
        dfs(grid,nr,nc,vis);
         
     }
    }
   

}
    int numIslands(vector<vector<char>>& grid) {
         int count=0;
        int n=grid.size();
        int m=grid[0].size();
       vector<vector<bool>> vis(n, vector<bool>(m, false));;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
               
                if(grid[i][j] == '1' && !vis[i][j]) {
                    count++;
                    dfs(grid,i,j,vis);
                }
            }
        }
        
        
    
    return count;

    }   
    
};
