class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
      int n=grid.size();
      int col=grid[0].size();
      
      int ans=0;
       for( int i =0;i<n;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j]==1){
                ans+=4;

            
              if (i > 0 && grid[i-1][j] == 1) {
                        ans -= 2; // Subtract shared 
                    }

                  
                    if (j > 0 && grid[i][j-1] == 1) {
               ans -= 2; // Subtract shared edge
                    }
        }
       }
      
       }
       return ans;
    }
};