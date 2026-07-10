class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
         int i=0;
         int j=0;
         bool zeroo=false;
         bool colu=false;

for( int j=0;j<n;j++){
    if( matrix[0][j]==0){
        zeroo=true;
    }
}
for( int i=0;i<m;i++){
    if( matrix[i][0]==0){
        colu=true;
    }

}
// set markers
for ( int i=1;i<m;i++){
    for( int j=1;j<n;j++){
        if( matrix[i][j]==0){
            matrix[0][j]=0;
            matrix[i][0]=0;
        }

    }

    }
for ( int i=1;i<m;i++){
    for( int j=1;j<n;j++){
        if( matrix[i][0]==0 || matrix[0][j]==0){
            matrix[i][j]=0;
        }
    }
}
if(zeroo==true){
    for( int j=0;j<n;j++){
        matrix[0][j]=0;
    }

}
if(colu==true){
    for( int i=0;i<m;i++){
        matrix[i][0]=0;
    }
}

    }

};