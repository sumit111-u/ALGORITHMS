class Solution {
public:
int memo[50001];
int n;
//pehla job jiska starting point greater thasn curr end point
int getnextindex(vector<vector<int>>&array,int l, int current){
    int r =n-1;
    int result=n;
    while(l<=r){
       int mid=(l+r)/2;
        if(array[mid][0]>=current){
            // le sakde appan
            result=mid;
            r=mid-1;

        }
        else{
            l=mid+1;
        }
    }
    return result;
}
int solve( vector<vector<int>>&array, int i ){

    if(i>=n) return 0;
    if(memo[i]!=-1) return memo[i];
    int nextindex=getnextindex(array,i+1,array[i][1]);

    int take=array[i][2]+solve(array,nextindex);
    int nottake=solve(array,i+1);
    return memo[i]=max(take,nottake);
}
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
      memset(memo,-1,sizeof(memo));
      n=  startTime.size();
      vector<vector<int>>array(n,vector<int>(3,0));//{ s,e,p}

      for( int i=0;i<n;i++){
        array[i][0]=startTime[i];
        array[i][1]=endTime[i];
        array[i][2]=profit[i];
      }
      // sort kardo according to start time 
      auto comparator=[&]( auto & vec1,auto &vec2){
        return vec1[0]< vec2[0];

      };

    sort(array.begin(),array.end(),comparator);
    return solve( array,0);
    }
};