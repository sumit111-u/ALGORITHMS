class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int i =0;
        int j=0;
        vector<vector<int>>result(numRows);
        for( int i =0;i<numRows;i++){
       result[i]= vector<int>(i+1,1);
       for( int j=1;j<i;j++){
        result[i][j]=result[i-1][j-1]+ result[i-1][j];
       }

        }
        return result;
        
    }
};